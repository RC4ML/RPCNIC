package cloud_fpga

import common.storage._
import common.Delay
import common.connection._
import common.axi._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.ToZero
import network.roce.util._
import qdma._


class EngineSim() extends Module{
	val io = IO(new Bundle{
        val meta_in         	= Flipped(Decoupled(new EngMeta))
		val host_data_in		= Flipped(Decoupled(UInt(512.W)))
		val device_data_in		= Flipped(Decoupled(UInt(512.W)))
		val host_write_cmd		= (Decoupled(new C2H_CMD))
		val host_write_data		= (Decoupled(new C2H_DATA))
        val enghbmCtrlAw   		= (Decoupled(new RoceMsg))
        val enghbmCtrlW    		= (Decoupled(UInt(512.W)))
		val delay_time			= Input(UInt(32.W))
		val notice_addr			= Input(UInt(64.W))
		val thread_num          = Input(UInt(8.W))
	})

    Collector.fire(io.meta_in)
    Collector.fire(io.host_data_in)
    Collector.fire(io.device_data_in)

    Collector.fire(io.host_write_cmd)
    Collector.fire(io.host_write_data)

    Collector.fire(io.enghbmCtrlAw)
    Collector.fire(io.enghbmCtrlW)	


    val meta_in_fifo            = XQueue(new EngMeta(), 32)

    val host_data_fifo          = XQueue(UInt(512.W), 4096)
    val device_data_fifo        = XQueue(UInt(512.W), 4096)


    io.meta_in              <> meta_in_fifo.io.in
	io.host_data_in			<> host_data_fifo.io.in
	io.device_data_in		<> device_data_fifo.io.in


    val meta_reg        = RegInit(0.U.asTypeOf(new EngMeta()))

	val delay_cnt		= RegInit(0.U(32.W))
	val delay_time		= RegNext(io.delay_time)

	val notice_addr		= RegInit(VecInit(Seq.fill(16)(0.U(64.W))))
	val eng_notice_cnt	= RegInit(VecInit(Seq.fill(16)(1.U(32.W))))
    for(i<- 0 until 16){
        notice_addr(i)  := RegNext(io.notice_addr + 64.U*i.U)
    }
	val notice_flag     = RegInit(UInt(4.W),0.U)
	val thread_num      = RegNext(io.thread_num - 1.U)




	val first_cyc		= RegInit(true.B)


	val sIdle :: sDelay :: sDevice :: sHost :: sEnd :: Nil = Enum(5)
	val state	= RegInit(sIdle)



    ToZero(io.enghbmCtrlAw.valid)
    ToZero(io.enghbmCtrlAw.bits)
    ToZero(io.enghbmCtrlW.valid)
    ToZero(io.enghbmCtrlW.bits)
    ToZero(io.host_write_cmd.valid)
    ToZero(io.host_write_cmd.bits)
    ToZero(io.host_write_data.valid)
    ToZero(io.host_write_data.bits)


    meta_in_fifo.io.out.ready                   := (state === sIdle) & io.enghbmCtrlAw.ready & io.host_write_cmd.ready

	device_data_fifo.io.out.ready				:= (state === sDevice) & ((meta_reg.dest_device & io.enghbmCtrlW.ready) || ((!meta_reg.dest_device) & io.host_write_data.ready))
	host_data_fifo.io.out.ready					:= (state === sHost) & ((meta_reg.dest_device & io.enghbmCtrlW.ready) || ((!meta_reg.dest_device) & io.host_write_data.ready))

	switch(state){
		is(sIdle){
			when(meta_in_fifo.io.out.fire()){
                meta_reg                	:= meta_in_fifo.io.out.bits
				state                   	:= sDelay
			}
		}
		is(sDelay){
			when(delay_cnt === delay_time){
				delay_cnt						:= 0.U
				when(meta_reg.src_device){
					state                   	:= sDevice
				}.otherwise{
					state                   	:= sHost
				}
				when(meta_reg.dest_device){
					io.enghbmCtrlAw.valid		:= 1.U
					io.enghbmCtrlAw.bits.addr	:= meta_reg.dest_addr
					io.enghbmCtrlAw.bits.length	:= meta_reg.dest_length
				}.otherwise{
					io.host_write_cmd.valid		:= 1.U
					io.host_write_cmd.bits.addr	:= meta_reg.dest_addr
					io.host_write_cmd.bits.len	:= meta_reg.dest_length
				}				
			}.otherwise{
				delay_cnt						:= delay_cnt + 1.U
				state                   		:= sDelay
			}
		}		
		is(sDevice){
			when(device_data_fifo.io.out.fire()){
				when(meta_reg.dest_device){
					when(first_cyc){
						io.enghbmCtrlW.bits			:= meta_reg.dest_length - 64.U
						first_cyc					:= false.B
					}.otherwise{
						io.enghbmCtrlW.bits			:= device_data_fifo.io.out.bits
					}
					when(meta_reg.src_length > 64.U){
						meta_reg.src_length			:= meta_reg.src_length - 64.U
						state						:= sDevice
					}.otherwise{
						state						:= sEnd
					}
					when(meta_reg.dest_length === 0.U){
						io.enghbmCtrlW.valid			:= 0.U
					}.elsewhen(meta_reg.dest_length > 64.U){
						meta_reg.dest_length			:= meta_reg.dest_length - 64.U
						io.enghbmCtrlW.valid			:= 1.U
					}.otherwise{
						meta_reg.dest_length			:= 0.U
						io.enghbmCtrlW.valid			:= 1.U
					}
				}.otherwise{
					io.host_write_data.bits.data		:= device_data_fifo.io.out.bits
					when(meta_reg.src_length > 64.U){
						meta_reg.src_length			:= meta_reg.src_length - 64.U
						state						:= sDevice
					}.otherwise{
						state						:= sEnd
					}
					when(meta_reg.dest_length === 0.U){
						io.host_write_data.valid		:= 0.U
					}.elsewhen(meta_reg.dest_length > 64.U){
						meta_reg.dest_length			:= meta_reg.dest_length - 64.U
						io.host_write_data.valid		:= 1.U
					}.otherwise{
						meta_reg.dest_length			:= 0.U
						io.host_write_data.valid		:= 1.U
						io.host_write_data.bits.last	:= 1.U
					}					
				}
			}
		}
		is(sHost){
			when(host_data_fifo.io.out.fire()){
				when(meta_reg.dest_device){
					when(first_cyc){
						io.enghbmCtrlW.bits			:= meta_reg.dest_length - 64.U
						first_cyc					:= false.B
					}.otherwise{
						io.enghbmCtrlW.bits			:= device_data_fifo.io.out.bits
					}
					when(meta_reg.src_length > 64.U){
						meta_reg.src_length			:= meta_reg.src_length - 64.U
						state						:= sHost
					}.otherwise{
						state						:= sEnd
					}
					when(meta_reg.dest_length === 0.U){
						io.enghbmCtrlW.valid			:= 0.U
					}.elsewhen(meta_reg.dest_length > 64.U){
						meta_reg.dest_length			:= meta_reg.dest_length - 64.U
						io.enghbmCtrlW.valid			:= 1.U
					}.otherwise{
						meta_reg.dest_length			:= 0.U
						io.enghbmCtrlW.valid			:= 1.U
					}					
				}.otherwise{
					io.host_write_data.bits.data		:= host_data_fifo.io.out.bits
					when(meta_reg.src_length > 64.U){
						meta_reg.src_length			:= meta_reg.src_length - 64.U
						state						:= sHost
					}.otherwise{
						state						:= sEnd
					}
					when(meta_reg.dest_length === 0.U){
						io.host_write_data.valid		:= 0.U
					}.elsewhen(meta_reg.dest_length > 64.U){
						meta_reg.dest_length			:= meta_reg.dest_length - 64.U
						io.host_write_data.valid		:= 1.U
					}.otherwise{
						meta_reg.dest_length			:= 0.U
						io.host_write_data.valid		:= 1.U
						io.host_write_data.bits.last	:= 1.U
					}					
				}
			}
		}
		is(sEnd){
			first_cyc					:= true.B
			when(io.host_write_cmd.ready & io.host_write_data.ready){
				io.host_write_cmd.valid		:= 1.U				
				io.host_write_cmd.bits.len	:= 64.U	
				io.host_write_data.valid	:= 1.U				
				io.host_write_data.bits.last:= 1.U	
                when(notice_flag >= thread_num){
                    notice_flag                     := 0.U
                }.otherwise{
                    notice_flag                     := notice_flag + 1.U
                }						
				io.host_write_cmd.bits.addr		:= notice_addr(notice_flag)
				io.host_write_data.bits.data	:= eng_notice_cnt(notice_flag)
				eng_notice_cnt(notice_flag)		:= eng_notice_cnt(notice_flag) + 1.U
				state							:= sIdle
			}.otherwise{
				state						:= sEnd
			}
		}
	}	
    
}