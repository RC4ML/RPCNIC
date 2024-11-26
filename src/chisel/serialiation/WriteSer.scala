package serialization

import common.storage._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.axi._
import common._

class SerOutMeta extends Bundle {
    val class_id = UInt(10.W)
    val length = UInt(32.W)
}


class WriteSer() extends Module{
	val io = IO(new Bundle{
        val done                = Flipped(Decoupled(UInt(10.W)))
		val writer_req	        = Flipped(Decoupled(new SerWriteReq))
        val meta_out            = (Decoupled(new SerOutMeta()))
        val data_out            = (Decoupled(new AXIS(512)))
	})

    Collector.fire(io.meta_out)
    Collector.fire(io.data_out)


    val writer_req_fifo = XQueue(new SerWriteReq(), entries=512)

    val done_fifo = XQueue(UInt(10.W), entries=8)

    val data_out_fifo = XQueue(new AXIS(512), entries=1024)

    io.data_out     <> data_out_fifo.io.out

    val ser_buffer = XRam(UInt(512.W), entries = 4096, latency = 1, use_musk = 1)

    val addr_offset = WireInit(UInt(10.W),0.U)
    addr_offset := writer_req_fifo.io.out.bits.addr & 63.U
    
    val tmp_musk = WireInit(VecInit(Seq.fill(64)(0.U(1.W))))

    val next_addr = RegInit(UInt(16.W),0.U)
    val next_data = RegInit(VecInit(Seq.fill(64)(0.U(8.W))))
    val tmp_data = WireInit(VecInit(Seq.fill(64)(0.U(8.W))))
    val tmp_data_a = WireInit(VecInit(Seq.fill(64)(0.U(8.W))))
    
    val next_musk = RegInit(UInt(64.W),0.U)
    val remain_length = RegInit(UInt(16.W),0.U)

    val base_addr = RegInit(UInt(16.W),0.U)
    val ser_length  = RegInit(UInt(16.W),0.U)
    val send_remain_len  = RegInit(UInt(16.W),0.U)
    val send_addr   = RegInit(UInt(16.W),0.U)
    val send_offset = RegInit(UInt(6.W),0.U)
    val send_data = RegInit(VecInit(Seq.fill(64)(0.U(8.W))))
    val tmp_send = WireInit(VecInit(Seq.fill(64)(0.U(8.W))))

    val data_out_valid = RegInit(UInt(1.W),0.U)
    val data_out_last = RegInit(UInt(1.W),0.U)
    val tmp_data_out = RegInit(VecInit(Seq.fill(64)(0.U(8.W))))
    val tmp_keep = RegInit(VecInit(Seq.fill(64)(0.U(1.W))))
    

	val sIDLE :: sLAST :: sLONG :: sFIRSTADDR :: sFIRSTDATA:: sSEND :: sEND :: Nil = Enum(7)
	val state                   = RegInit(sIDLE)
    val state_out               = RegInit(sIDLE)    

    io.writer_req                       <> writer_req_fifo.io.in
    io.done                             <> done_fifo.io.in

    writer_req_fifo.io.out.ready        := (state === sIDLE) || (state === sLONG) 
    done_fifo.io.out.ready                       := state_out === sIDLE

    ToZero(ser_buffer.io.addr_a)
    ToZero(ser_buffer.io.addr_b)
    ToZero(ser_buffer.io.wr_en_a)
    ToZero(ser_buffer.io.data_in_a)

    ToZero(data_out_fifo.io.in.bits.last)
    ToZero(data_out_fifo.io.in.valid)
    ToZero(io.meta_out.valid)
    ToZero(io.meta_out.bits)
    ToZero(data_out_valid)

    ser_buffer.io.musk_a.get    := tmp_musk.asUInt
    data_out_fifo.io.in.bits.keep       := tmp_keep.asUInt
    ser_buffer.io.data_in_a     := tmp_data_a.asUInt
    data_out_fifo.io.in.bits.data       := tmp_data_out.asUInt
    data_out_fifo.io.in.valid           := data_out_valid
    data_out_fifo.io.in.bits.last       := data_out_last


    when(done_fifo.io.out.fire()){
        ser_length      := 0.U
    }.elsewhen(writer_req_fifo.io.out.fire() & (state===sIDLE)){
        ser_length      := ser_length + writer_req_fifo.io.out.bits.length
    }.otherwise{
        ser_length      := ser_length;
    }


    switch(state){
        is(sIDLE){
            when(writer_req_fifo.io.out.fire()){
                base_addr                   := writer_req_fifo.io.out.bits.addr
                ser_buffer.io.addr_a        := writer_req_fifo.io.out.bits.addr >> 6.U
                ser_buffer.io.wr_en_a       := 1.U
                ser_buffer.io.data_in_a     := writer_req_fifo.io.out.bits.data << (addr_offset*8.U)
                for(i<- 0 until 64){
                    when((i.U>=addr_offset)&(i.U<(addr_offset+writer_req_fifo.io.out.bits.length))){
                        tmp_musk(i)         := 1.U
                    }.otherwise{
                        tmp_musk(i)         := 0.U
                    }
                }                
                when(writer_req_fifo.io.out.bits.length > 64.U){
                    remain_length               := writer_req_fifo.io.out.bits.length - 64.U
                    next_addr                   := (writer_req_fifo.io.out.bits.addr >> 6.U)+1.U
                    for(i<- 0 until 64){
                        next_data(i) := (writer_req_fifo.io.out.bits.data >> (512.U - addr_offset*8.U))(i*8+7,i*8)
                    }                    
                    next_musk                   := addr_offset
                    state                       := sLONG
                }.elsewhen((addr_offset + writer_req_fifo.io.out.bits.length)>64.U){
                    next_addr                   := (writer_req_fifo.io.out.bits.addr >> 6.U)+1.U
                    for(i<- 0 until 64){
                        next_data(i) := (writer_req_fifo.io.out.bits.data >> (512.U - addr_offset*8.U))(i*8+7,i*8)
                    }                    
                    next_musk                   := addr_offset + writer_req_fifo.io.out.bits.length - 64.U
                    state                       := sLAST                
                }.otherwise{
                    state                       := sIDLE         
                }
            }
        }
        is(sLAST){
            ser_buffer.io.addr_a        := next_addr        
            ser_buffer.io.wr_en_a       := 1.U
            for(i<- 0 until 64){
                tmp_data(i) := next_data(i)
            }            
            for(i<- 0 until 64){
                when(i.U < next_musk){
                    tmp_musk(i)         := 1.U
                }.otherwise{
                    tmp_musk(i)         := 0.U
                }
            }            
            state                       := sIDLE
        }
        is(sLONG){
            when(writer_req_fifo.io.out.fire()){
                ser_buffer.io.addr_a        := next_addr
                ser_buffer.io.wr_en_a       := 1.U
                for(i<- 0 until 64){
                    tmp_data(i) := writer_req_fifo.io.out.bits.data(i*8+7,i*8)
                }                 
                for(i<- 0 until 64){
                    when(i.U < next_musk){
                        tmp_data_a(i) := next_data(i)
                    }.otherwise{
                        tmp_data_a(i) := tmp_data(i.U + 64.U - next_musk - next_musk)
                    }
                }                
                next_addr                   := next_addr + 1.U
                for(i<- 0 until 64){
                    next_data(i) := (writer_req_fifo.io.out.bits.data >> (512.U - addr_offset*8.U))(i*8+7,i*8)
                }                 
                when(remain_length > 64.U){
                    remain_length           := remain_length - 64.U
                    for(i<- 0 until 64){
                        tmp_musk(i)         := 1.U
                    } 
                    state                   := sLONG
                }.elsewhen((remain_length + next_musk) > 64.U){
                    for(i<- 0 until 64){
                        tmp_musk(i)         := 1.U
                    }  
                    next_musk               := remain_length + next_musk - 64.U
                    state                   := sLAST
                }.otherwise{
                    for(i<- 0 until 64){
                        when(i.U<(remain_length + next_musk)){
                            tmp_musk(i)         := 1.U
                        }.otherwise{
                            tmp_musk(i)         := 0.U
                        }
                    } 
                    state                   := sIDLE
                }
            }
        }
    }


    switch(state_out){
        is(sIDLE){
            when(done_fifo.io.out.fire()){
                state_out               := sFIRSTADDR   
                io.meta_out.valid       := 1.U  
                io.meta_out.bits.class_id := done_fifo.io.out.bits
                io.meta_out.bits.length := ser_length
                send_remain_len         := ser_length  
                send_addr               := base_addr >> 6.U 
                send_offset             := base_addr(5,0)
            }
        }
        is(sFIRSTADDR){
            ser_buffer.io.addr_b        := send_addr
            send_addr                   := send_addr + 1.U                      

            when(send_remain_len < (64.U - send_offset)){
                state_out               := sLAST
            }.otherwise{
                state_out               := sFIRSTDATA
                send_remain_len         := send_remain_len - (64.U - send_offset) 
            }
        }
        is(sFIRSTDATA){
            for(i<- 0 until 64){
                send_data(i) := ser_buffer.io.data_out_b(i*8+7,i*8)
            }            
            ser_buffer.io.addr_b        := send_addr
            send_addr                   := send_addr + 1.U 
            when(send_remain_len <= 64.U){
                state_out               := sLAST
            }.otherwise{
                state_out               := sSEND
                send_remain_len         := send_remain_len - 64.U
            }           
        }
        is(sSEND){
            ser_buffer.io.addr_b        := send_addr
            send_addr                   := send_addr + 1.U 
            for(i<- 0 until 64){
                send_data(i) := ser_buffer.io.data_out_b(i*8+7,i*8)
            }                         
            data_out_valid              := 1.U
            for(i<- 0 until 64){
                tmp_send(i) := ser_buffer.io.data_out_b(i*8+7,i*8)
            }   
            for(i<- 0 until 64){
                when(i.U < (64.U - send_offset)){
                    tmp_data_out(i) := send_data(i.U+send_offset)
                }.otherwise{
                    tmp_data_out(i) := tmp_send(i.U + send_offset - 64.U)
                }
            }                      
            for(i<- 0 until 64){
                tmp_keep(i) := 1.U
            }  
            data_out_last            := 0.U
            when(send_remain_len <= 64.U){
                state_out               := sLAST
            }.otherwise{
                state_out               := sSEND
                send_remain_len         := send_remain_len - 64.U
            } 
        }
        is(sLAST){
            when(send_remain_len < send_offset){
                for(i<- 0 until 64){
                    send_data(i) := ser_buffer.io.data_out_b(i*8+7,i*8)
                }                 
                data_out_valid           := 1.U
                for(i<- 0 until 64){
                    tmp_send(i) := ser_buffer.io.data_out_b(i*8+7,i*8)
                }   
                for(i<- 0 until 64){
                    when(i.U < (64.U - send_offset)){
                        tmp_data_out(i) := send_data(i.U+send_offset)
                    }.otherwise{
                        tmp_data_out(i) := tmp_send(i.U + send_offset - 64.U)
                    }
                }                   
                for(i<- 0 until 64){
                    when(i.U < (64.U -send_offset+send_remain_len)){
                        tmp_keep(i) := 1.U
                    }.otherwise{
                        tmp_keep(i) := 0.U
                    }
                }  
                data_out_last            := 1.U                
                state_out               := sIDLE
            }.otherwise{
                for(i<- 0 until 64){
                    send_data(i) := ser_buffer.io.data_out_b(i*8+7,i*8)
                }                 
                data_out_valid           := 1.U
                for(i<- 0 until 64){
                    tmp_send(i) := ser_buffer.io.data_out_b(i*8+7,i*8)
                }   
                for(i<- 0 until 64){
                    when(i.U < (64.U - send_offset)){
                        tmp_data_out(i) := send_data(i.U+send_offset)
                    }.otherwise{
                        tmp_data_out(i) := tmp_send(i.U + send_offset - 64.U)
                    }
                }                  
                for(i<- 0 until 64){
                    tmp_keep(i) := 1.U
                }  
                data_out_last            := 0.U                 
                state_out               := sEND
            }
        }
        is(sEND){
            data_out_valid           := 1.U
            for(i<- 0 until 64){
                tmp_data_out(i) := send_data(i.U+send_offset)
            }             
            for(i<- 0 until 64){
                when(i.U < send_remain_len - send_offset){
                    tmp_keep(i) := 1.U
                }.otherwise{
                    tmp_keep(i) := 0.U
                }
            }              
            data_out_last            := 1.U                
            state_out               := sIDLE
        }
    }
}
