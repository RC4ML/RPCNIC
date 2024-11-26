package cloud_fpga

import common.storage._
import common.Delay
import common.connection._
import common.axi._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import network.roce.util._
import network.roce._
import common.Collector
import common.ToZero
import common.RSHIFT
import serialization._
import common._


class ReadHostDeser() extends Module{
	val io = IO(new Bundle{
        val ser_cmd     = Flipped(Decoupled(new SerMeta))
        
        val m_mem_read_cmd      = (Decoupled(new MEM_CMD()))
        val s_mem_read_data	    = Flipped(Decoupled(new AXIS(512))) 
        
        val ser_cmd_out         = (Decoupled(new DeserMeta))
        val ser_host_data_out   = (Decoupled(AXIS(512)))

        val recv_meta_fire      = Input(Bool())
        val total_send_num      = Input(UInt(32.W))
        val idle_cycle          = Input(UInt(32.W))
        val outstanding_cmd     = Input(UInt(32.W))

        val idle                = Input(UInt(1.W))
    
	})


    Collector.fire(io.ser_cmd)
    Collector.fire(io.m_mem_read_cmd)
    Collector.fire(io.s_mem_read_data)


    Collector.fire(io.ser_cmd_out)
    Collector.fire(io.ser_host_data_out)



    val ser_cmd_fifo            = XQueue(new SerMeta(), 8)

    val host_data_fifo          = XQueue(AXIS(512), 4096)
    val host_data_fifo1          = XQueue(AXIS(512), 4096)

    host_data_fifo.io.out       <> host_data_fifo1.io.in

    val ser_reg        = RegInit(0.U.asTypeOf(new SerMeta()))
    val host_reg       = RegInit(0.U.asTypeOf(new HostCmdType()))

    val host_length     = RegInit(UInt(32.W),0.U)
    val recv_meta_fire  = RegNext(io.recv_meta_fire)
    val total_send_num  = RegNext(io.total_send_num)
    val idle_cycle      = RegNext(io.idle_cycle)
    val outstanding_cmd = RegNext(io.outstanding_cmd)
    val start           = RegInit(false.B)
    val idle            = RegNext(io.idle)

    val arbiter							= SerialArbiter(AXIS(512), 2)


    


	val sIdle :: sWork :: sDelay :: sEnd :: Nil = Enum(4)
	val state	= RegInit(sIdle)



    ToZero(io.m_mem_read_cmd.valid)
    ToZero(io.m_mem_read_cmd.bits)    
    ToZero(io.ser_cmd_out.valid)
    ToZero(io.ser_cmd_out.bits)
    ToZero(arbiter.io.in(0).valid)
    ToZero(arbiter.io.in(0).bits)

    io.s_mem_read_data.ready                := (state === sEnd) & arbiter.io.in(0).ready

    io.ser_cmd              <> ser_cmd_fifo.io.in


    ser_cmd_fifo.io.out.ready                   := (state === sIdle)

	switch(state){
		is(sIdle){
			when(ser_cmd_fifo.io.out.fire()){
                ser_reg                 := ser_cmd_fifo.io.out.bits
                state                   := sWork
                start                   := false.B
			}
		}
		is(sWork){
            when(io.m_mem_read_cmd.ready){
                io.m_mem_read_cmd.valid             := 1.U
                io.m_mem_read_cmd.bits.vaddr        := ser_reg.host_base_addr
                io.m_mem_read_cmd.bits.length       := ((ser_reg.host_length + 63.U) >> 6.U)<<6.U
                host_length                         := ((ser_reg.host_length + 63.U) >> 6.U)<<6.U
                state                               := sEnd
            }
		}
        is(sEnd){
            when(io.s_mem_read_data.fire()){
                arbiter.io.in(0).valid              := 1.U
                arbiter.io.in(0).bits               := io.s_mem_read_data.bits
                host_length                         := host_length - 64.U
                when(host_length <= 64.U){
                    arbiter.io.in(0).bits.last      := 1.U
                    state                           := sIdle
                    start                           := true.B
                }.otherwise{
                    arbiter.io.in(0).bits.last      := 0.U
                    state                           := sEnd
                }
            }
        }
	}

    //send meta
    {
        val q = XQueue(new DeserMeta, 32)  

		val rpc_cnt			        = RegInit(UInt(32.W), 0.U)//count q.io.in.fire()
		val state					= RegInit(sIdle)
        val flying_cnt              = RegInit(UInt(32.W), 0.U)
        val delay_cnt               = RegInit(UInt(32.W), 0.U)

        when(q.io.in.fire & recv_meta_fire){
            flying_cnt              := flying_cnt
        }.elsewhen(q.io.in.fire){
            flying_cnt              := flying_cnt + 1.U
        }.elsewhen(recv_meta_fire){
            flying_cnt              := flying_cnt - 1.U
        }.otherwise{
            flying_cnt              := flying_cnt
        }

		switch(state){
			is(sIdle){
				rpc_cnt	    := 0.U
				when(start){
					state		:= sWork
				}
			}
			is(sWork){
				when(q.io.in.fire){
                    when(rpc_cnt === (total_send_num - 1.U)){
                        state		:= sEnd
                    }.otherwise{
                        rpc_cnt     := rpc_cnt + 1.U
                        state		:= sDelay
                    }
					
				}
			}
            is(sDelay){
                delay_cnt       := delay_cnt + 1.U
                when((delay_cnt > idle_cycle)&&(flying_cnt < outstanding_cmd)&&(idle === 1.U)){
                    delay_cnt   := 0.U
                    state		:= sWork
                }.otherwise{
                    state		:= sDelay
                }

            }
			is(sEnd){
				when((!start) & RegNext(start)){
					state		:= sIdle
				}
			}
		}

        q.io.out                    <> io.ser_cmd_out
        q.io.in.valid				:= state === sWork
        q.io.in.bits.class_id       := ser_reg.class_id
        q.io.in.bits.length         := ser_reg.host_length
        q.io.in.bits.result_base_addr         := 0.U

    }

    //send data
    {
        val q = XQueue(AXIS(512), 32)  

		val rpc_cnt			        = RegInit(UInt(32.W), 0.U)//count q.io.in.fire()
		val state					= RegInit(sIdle)

        Connection.one2many(host_data_fifo1.io.out)(io.ser_host_data_out, q.io.in)
        io.ser_host_data_out.bits               := host_data_fifo1.io.out.bits
        q.io.in.bits                            := host_data_fifo1.io.out.bits


		arbiter.io.in(1)						<> q.io.out
		arbiter.io.out							<> host_data_fifo.io.in

		switch(state){
			is(sIdle){
				rpc_cnt	    := 0.U
				when(start){
					state		:= sWork
				}
			}
			is(sWork){
				when(host_data_fifo1.io.out.fire){
                    when((rpc_cnt === (total_send_num - 1.U))&(host_data_fifo1.io.out.bits.last === 1.U)){
                        io.ser_host_data_out.bits.keep   := ((1.U << ser_reg.host_length(5,0)) - 1.U)
                        rpc_cnt     := rpc_cnt + 1.U
                        state		:= sEnd
                    }.elsewhen(host_data_fifo1.io.out.bits.last === 1.U){
                        io.ser_host_data_out.bits.keep   := ((1.U << ser_reg.host_length(5,0)) - 1.U)
                        rpc_cnt     := rpc_cnt + 1.U
                        state		:= sWork
                    }.otherwise{
                        state		:= sWork
                    }
					
				}
			}
			is(sEnd){
				when((!start) & RegNext(start)){
					state		:= sIdle
				}
			}
		}

    }

}