package serialization

import common.storage._
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.Collector
import common.axi._
import common._

class DerOutMeta extends Bundle {
    val host_length = UInt(32.W)
    val device_length = UInt(32.W)
}


class WriteDeser() extends Module{
	val io = IO(new Bundle{
		val writer_req	        = Flipped(Decoupled(new WriteReq))
        val meta_out            = (Decoupled(new DerOutMeta()))
        val host_data_out       = (Decoupled(UInt(512.W)))
        val device_data_out     = (Decoupled(UInt(512.W)))
	})

    Collector.fire(io.meta_out)
    Collector.fire(io.host_data_out)
    Collector.fire(io.device_data_out)

    val writer_req_fifo = XQueue(new WriteReq(), entries=1024)


    val host_128to512 = Module(new Data128to512())
    val device_128to512 = Module(new Data128to512())

    io.host_data_out        <> host_128to512.io.out
    io.device_data_out      <> device_128to512.io.out

    val tmp_host_data = WireInit(VecInit(Seq.fill(16)(0.U(8.W))))
    val tmp_device_data = WireInit(VecInit(Seq.fill(16)(0.U(8.W))))

    val reg_host_data = RegInit(VecInit(Seq.fill(16)(0.U(8.W))))
    val reg_device_data = RegInit(VecInit(Seq.fill(16)(0.U(8.W))))


    val host_remain_length = RegInit(UInt(16.W),0.U)
    val device_remain_length = RegInit(UInt(16.W),0.U)


    val host_length = RegInit(UInt(32.W),0.U)
    val device_length = RegInit(UInt(32.W),0.U)

    val host_remain_len = RegInit(UInt(8.W),0.U)
    val device_remain_len = RegInit(UInt(8.W),0.U)


    val send_data = RegInit(VecInit(Seq.fill(16)(0.U(8.W))))
    val req_reg = RegInit(0.U.asTypeOf(new WriteReq()))

	val sIDLE :: sHostData :: sDeviceData :: sMeta :: Nil = Enum(4)
	val state                   = RegInit(sIDLE)
    val state_out               = RegInit(sIDLE)    

    io.writer_req                       <> writer_req_fifo.io.in

    writer_req_fifo.io.out.ready        := ((state === sIDLE) & host_128to512.io.in.ready & device_128to512.io.in.ready) || ((state === sHostData) & host_128to512.io.in.ready) || ((state === sDeviceData)  & device_128to512.io.in.ready) 


    ToZero(io.meta_out.bits)
    ToZero(io.meta_out.valid)
    ToZero(host_128to512.io.in.valid)
    ToZero(host_128to512.io.in.bits)
    ToZero(device_128to512.io.in.valid)
    ToZero(device_128to512.io.in.bits)


    host_128to512.io.in.bits.data  := tmp_host_data.asUInt
    device_128to512.io.in.bits.data  := tmp_device_data.asUInt


    switch(state){
        is(sIDLE){
            when(writer_req_fifo.io.out.fire()){
                req_reg                 := writer_req_fifo.io.out.bits
                when(writer_req_fifo.io.out.bits.is_host){
                    host_length         := host_length + writer_req_fifo.io.out.bits.length
                    when((writer_req_fifo.io.out.bits.length + host_remain_len) < 16.U){
                        host_remain_len             := writer_req_fifo.io.out.bits.length + host_remain_len
                        for(i<- 0 until 16){
                            when(i.U < host_remain_len){
                                reg_host_data(i) := reg_host_data(i)
                            }.otherwise{
                                reg_host_data(i) := (writer_req_fifo.io.out.bits.data << (host_remain_len *8.U))(i*8+7,i*8)
                            }
                        }       
                        when(writer_req_fifo.io.out.bits.done){
                            state               := sMeta
                        }.otherwise{
                            state               := sIDLE
                        }          
                    }.elsewhen((writer_req_fifo.io.out.bits.length + host_remain_len) === 16.U){
                        for(i<- 0 until 16){
                            when(i.U < host_remain_len){
                                reg_host_data(i) := reg_host_data(i)
                                tmp_host_data(i) := reg_host_data(i)
                            }.otherwise{
                                reg_host_data(i) := (writer_req_fifo.io.out.bits.data << (host_remain_len *8.U))(i*8+7,i*8)
                                tmp_host_data(i) := (writer_req_fifo.io.out.bits.data << (host_remain_len *8.U))(i*8+7,i*8)
                            }
                        } 
                        when(writer_req_fifo.io.out.bits.done){
                            state               := sMeta
                            host_remain_len             := 16.U
                        }.otherwise{
                            state               := sIDLE
                            host_128to512.io.in.valid      := 1.U
                            host_remain_len             := 0.U
                        } 
                    }.elsewhen(writer_req_fifo.io.out.bits.length <= 16.U){
                        host_remain_len             := writer_req_fifo.io.out.bits.length + host_remain_len - 16.U
                        for(i<- 0 until 16){
                            when(i.U < host_remain_len){
                                tmp_host_data(i) := reg_host_data(i)
                            }.otherwise{
                                tmp_host_data(i) := (writer_req_fifo.io.out.bits.data << (host_remain_len *8.U))(i*8+7,i*8)
                            }
                            when(i.U < (host_remain_len + writer_req_fifo.io.out.bits.length - 16.U)){
                                reg_host_data(i) := (writer_req_fifo.io.out.bits.data >> ((16.U - host_remain_len)*8.U))(i*8+7,i*8)
                            }
                        } 
                        host_128to512.io.in.valid      := 1.U
                        when(writer_req_fifo.io.out.bits.done){
                            state               := sMeta
                        }.otherwise{
                            state               := sIDLE
                        }
                    }.otherwise{
                        host_remain_len             := writer_req_fifo.io.out.bits.length + host_remain_len - 16.U
                        for(i<- 0 until 16){
                            when(i.U < host_remain_len){
                                tmp_host_data(i) := reg_host_data(i)
                            }.otherwise{
                                tmp_host_data(i) := (writer_req_fifo.io.out.bits.data << (host_remain_len *8.U))(i*8+7,i*8)
                            }
                            when(i.U < (host_remain_len + writer_req_fifo.io.out.bits.length - 16.U)){
                                reg_host_data(i) := (writer_req_fifo.io.out.bits.data >> ((16.U - host_remain_len)*8.U))(i*8+7,i*8)
                            }
                        } 
                        host_128to512.io.in.valid      := 1.U
                        state                       := sHostData                
                    }
                }.otherwise{
                    device_length                   := device_length + writer_req_fifo.io.out.bits.length
                    when((writer_req_fifo.io.out.bits.length + device_remain_len) < 16.U){
                        device_remain_len             := writer_req_fifo.io.out.bits.length + device_remain_len
                        for(i<- 0 until 16){
                            when(i.U < device_remain_len){
                                reg_device_data(i) := reg_device_data(i)
                            }.otherwise{
                                reg_device_data(i) := (writer_req_fifo.io.out.bits.data << (device_remain_len *8.U))(i*8+7,i*8)
                            }
                        }      
                        when(writer_req_fifo.io.out.bits.done){
                            state               := sMeta
                        }.otherwise{
                            state               := sIDLE
                        }                                        
                    }.elsewhen((writer_req_fifo.io.out.bits.length + device_remain_len) === 16.U){
                        for(i<- 0 until 16){
                            when(i.U < device_remain_len){
                                reg_device_data(i) := reg_device_data(i)
                                tmp_device_data(i) := reg_device_data(i)
                            }.otherwise{
                                reg_device_data(i) := (writer_req_fifo.io.out.bits.data << (device_remain_len *8.U))(i*8+7,i*8)
                                tmp_device_data(i) := (writer_req_fifo.io.out.bits.data << (device_remain_len *8.U))(i*8+7,i*8)
                            }
                        } 
                        when(writer_req_fifo.io.out.bits.done){
                            state               := sMeta
                            device_remain_len             := 16.U
                        }.otherwise{
                            state               := sIDLE
                            device_128to512.io.in.valid      := 1.U
                            device_remain_len             := 0.U
                        }                          
                    }.elsewhen(writer_req_fifo.io.out.bits.length <= 16.U){
                        device_remain_len             := writer_req_fifo.io.out.bits.length + device_remain_len - 16.U
                        for(i<- 0 until 16){
                            when(i.U < device_remain_len){
                                tmp_device_data(i) := reg_device_data(i)
                            }.otherwise{
                                tmp_device_data(i) := (writer_req_fifo.io.out.bits.data << (device_remain_len *8.U))(i*8+7,i*8)
                            }
                            when(i.U < (device_remain_len + writer_req_fifo.io.out.bits.length - 16.U)){
                                reg_device_data(i) := (writer_req_fifo.io.out.bits.data >> ((16.U - host_remain_len)*8.U))(i*8+7,i*8)
                            }                            
                        } 
                        device_128to512.io.in.valid      := 1.U
                        when(writer_req_fifo.io.out.bits.done){
                            state               := sMeta
                        }.otherwise{
                            state               := sIDLE
                        } 
                    }.otherwise{
                        device_remain_len             := writer_req_fifo.io.out.bits.length + device_remain_len - 16.U
                        for(i<- 0 until 16){
                            when(i.U < device_remain_len){
                                tmp_device_data(i) := reg_device_data(i)
                            }.otherwise{
                                tmp_device_data(i) := (writer_req_fifo.io.out.bits.data << (device_remain_len *8.U))(i*8+7,i*8)
                            }
                            when(i.U < (device_remain_len + writer_req_fifo.io.out.bits.length - 16.U)){
                                reg_device_data(i) := (writer_req_fifo.io.out.bits.data >> ((16.U - host_remain_len)*8.U))(i*8+7,i*8)
                            }                            
                        } 
                        device_128to512.io.in.valid      := 1.U
                        state                       := sDeviceData                
                    }
                }             
            }
        }
        is(sHostData){
            when(writer_req_fifo.io.out.fire()){
                when((writer_req_fifo.io.out.bits.length + host_remain_len) < 16.U){
                    host_remain_len             := writer_req_fifo.io.out.bits.length + host_remain_len
                    for(i<- 0 until 16){
                        when(i.U < host_remain_len){
                            reg_host_data(i) := reg_host_data(i)
                        }.otherwise{
                            reg_host_data(i) := (writer_req_fifo.io.out.bits.data << (host_remain_len *8.U))(i*8+7,i*8)
                        }
                    }       
                    when(writer_req_fifo.io.out.bits.done){
                        state               := sMeta
                    }.otherwise{
                        state               := sIDLE
                    }          
                }.elsewhen((writer_req_fifo.io.out.bits.length + host_remain_len) === 16.U){
                    
                    for(i<- 0 until 16){
                        when(i.U < host_remain_len){
                            reg_host_data(i) := reg_host_data(i)
                            tmp_host_data(i) := reg_host_data(i)
                        }.otherwise{
                            reg_host_data(i) := (writer_req_fifo.io.out.bits.data << (host_remain_len *8.U))(i*8+7,i*8)
                            tmp_host_data(i) := (writer_req_fifo.io.out.bits.data << (host_remain_len *8.U))(i*8+7,i*8)
                        }
                    } 
                    when(writer_req_fifo.io.out.bits.done){
                        state               := sMeta
                        host_remain_len             := 16.U
                    }.otherwise{
                        state               := sIDLE
                        host_128to512.io.in.valid      := 1.U
                        host_remain_len             := 0.U
                    }       
                }.elsewhen(writer_req_fifo.io.out.bits.length <= 16.U){
                    host_remain_len             := writer_req_fifo.io.out.bits.length + host_remain_len - 16.U
                    for(i<- 0 until 16){
                        when(i.U < host_remain_len){
                            tmp_host_data(i) := reg_host_data(i)
                        }.otherwise{
                            tmp_host_data(i) := (writer_req_fifo.io.out.bits.data << (host_remain_len *8.U))(i*8+7,i*8)
                        }
                        when(i.U < (host_remain_len + writer_req_fifo.io.out.bits.length - 16.U)){
                            reg_host_data(i) := (writer_req_fifo.io.out.bits.data >> ((16.U - host_remain_len)*8.U))(i*8+7,i*8)
                        }
                    } 
                    host_128to512.io.in.valid      := 1.U
                    when(writer_req_fifo.io.out.bits.done){
                        state               := sMeta
                    }.otherwise{
                        state               := sIDLE
                    }
                }.otherwise{
                    host_remain_len             := writer_req_fifo.io.out.bits.length + host_remain_len - 16.U
                    for(i<- 0 until 16){
                        when(i.U < host_remain_len){
                            tmp_host_data(i) := reg_host_data(i)
                        }.otherwise{
                            tmp_host_data(i) := (writer_req_fifo.io.out.bits.data << (host_remain_len *8.U))(i*8+7,i*8)
                        }
                        when(i.U < (host_remain_len + writer_req_fifo.io.out.bits.length - 16.U)){
                            reg_host_data(i) := (writer_req_fifo.io.out.bits.data >> ((16.U - host_remain_len)*8.U))(i*8+7,i*8)
                        }
                    } 
                    host_128to512.io.in.valid      := 1.U
                    state                       := sHostData                
                }                
            }        
        }
        is(sDeviceData){
            when(writer_req_fifo.io.out.fire()){
                when((writer_req_fifo.io.out.bits.length + device_remain_len) < 16.U){
                    device_remain_len             := writer_req_fifo.io.out.bits.length + device_remain_len
                    for(i<- 0 until 16){
                        when(i.U < device_remain_len){
                            reg_device_data(i) := reg_device_data(i)
                        }.otherwise{
                            reg_device_data(i) := (writer_req_fifo.io.out.bits.data << (device_remain_len *8.U))(i*8+7,i*8)
                        }
                    }      
                    when(writer_req_fifo.io.out.bits.done){
                        state               := sMeta
                    }.otherwise{
                        state               := sIDLE
                    }                                        
                }.elsewhen((writer_req_fifo.io.out.bits.length + device_remain_len) === 16.U){
                    
                    for(i<- 0 until 16){
                        when(i.U < device_remain_len){
                            reg_device_data(i) := reg_device_data(i)
                            tmp_device_data(i) := reg_device_data(i)
                        }.otherwise{
                            reg_device_data(i) := (writer_req_fifo.io.out.bits.data << (device_remain_len *8.U))(i*8+7,i*8)
                            tmp_device_data(i) := (writer_req_fifo.io.out.bits.data << (device_remain_len *8.U))(i*8+7,i*8)
                        }
                    } 
                    when(writer_req_fifo.io.out.bits.done){
                        state               := sMeta
                        device_remain_len             := 16.U
                    }.otherwise{
                        state               := sIDLE
                        device_128to512.io.in.valid      := 1.U
                        device_remain_len             := 0.U
                    }                          
                    
                }.elsewhen(writer_req_fifo.io.out.bits.length <= 16.U){
                    device_remain_len             := writer_req_fifo.io.out.bits.length + device_remain_len - 16.U
                    for(i<- 0 until 16){
                        when(i.U < device_remain_len){
                            tmp_device_data(i) := reg_device_data(i)
                        }.otherwise{
                            tmp_device_data(i) := (writer_req_fifo.io.out.bits.data << (device_remain_len *8.U))(i*8+7,i*8)
                        }
                        when(i.U < (device_remain_len + writer_req_fifo.io.out.bits.length - 16.U)){
                            reg_device_data(i) := (writer_req_fifo.io.out.bits.data >> ((16.U - host_remain_len)*8.U))(i*8+7,i*8)
                        }                            
                    } 
                    device_128to512.io.in.valid      := 1.U
                    when(writer_req_fifo.io.out.bits.done){
                        state               := sMeta
                    }.otherwise{
                        state               := sIDLE
                    } 
                }.otherwise{
                    device_remain_len             := writer_req_fifo.io.out.bits.length + device_remain_len - 16.U
                    for(i<- 0 until 16){
                        when(i.U < device_remain_len){
                            tmp_device_data(i) := reg_device_data(i)
                        }.otherwise{
                            tmp_device_data(i) := (writer_req_fifo.io.out.bits.data << (device_remain_len *8.U))(i*8+7,i*8)
                        }
                        when(i.U < (device_remain_len + writer_req_fifo.io.out.bits.length - 16.U)){
                            reg_device_data(i) := (writer_req_fifo.io.out.bits.data >> ((16.U - host_remain_len)*8.U))(i*8+7,i*8)
                        }                            
                    } 
                    device_128to512.io.in.valid      := 1.U
                    state                       := sDeviceData                
                }
            }
        }
        is(sMeta){
            when(io.meta_out.ready & host_128to512.io.in.ready & device_128to512.io.in.ready){
                io.meta_out.valid              := 1.U
                io.meta_out.bits.host_length        := host_length
                io.meta_out.bits.device_length      := device_length
                host_length                         := 0.U
                device_length                       := 0.U
                when(host_remain_len > 0.U){
                    host_128to512.io.in.bits.last       := 1.U
                    host_128to512.io.in.valid           := 1.U
                    for(i<- 0 until 16){
                        tmp_host_data(i) := reg_host_data(i)
                    } 

                    host_remain_len                 := 0.U
                }
                when(device_remain_len > 0.U){
                    device_128to512.io.in.bits.last     := 1.U
                    device_128to512.io.in.valid         := 1.U
                    for(i<- 0 until 16){
                        tmp_device_data(i) := reg_device_data(i)
                    }

                    device_remain_len               := 0.U
                }   
                state                               := sIDLE
            }
        }
    }
}
