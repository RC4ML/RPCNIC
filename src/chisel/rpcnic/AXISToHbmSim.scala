package cloud_fpga
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.storage._
import common.axi._
import common._
import network.roce.util._

class AXISToHbmSim() extends Module {

    val io = IO(new Bundle{

        val hbmCtrlAw   = Flipped(Decoupled(new RoceMsg))
        val hbmCtrlW    = Flipped(Decoupled(UInt(512.W)))

        val hbmCtrlAr   = Flipped(Decoupled(new RoceMsg))
        val hbmCtrlR    = (Decoupled(UInt(512.W)))
    })

    io.hbmCtrlAw.ready  := 1.U
    io.hbmCtrlW.ready   := 1.U
 
 
    //hbm read



    val ctrlFifoAr  = XQueue(new RoceMsg, 1024)

    io.hbmCtrlAr        <> ctrlFifoAr.io.in

    val sIdle :: sWrite :: sDelay :: Nil = Enum(3)

    val St_ar   = RegInit(sIdle)
    val ctrlArLen  = RegInit(UInt(32.W), 0.U)
    val delay_cnt  = RegInit(UInt(8.W), 0.U)

    ctrlFifoAr.io.out.ready             := St_ar === sIdle

    ToZero(io.hbmCtrlR.valid)
    ToZero(io.hbmCtrlR.bits)

    switch(St_ar){
        is(sIdle){
            when(ctrlFifoAr.io.out.fire()){
                ctrlArLen                   := ctrlFifoAr.io.out.bits.length
                delay_cnt                   := 0.U
                St_ar                       := sDelay
            }
        }
        is(sDelay){
            when(delay_cnt === 24.U){
                St_ar                       := sWrite
            }.otherwise{
                delay_cnt                   := delay_cnt + 1.U
            }
        }
        is(sWrite){
            when(io.hbmCtrlR.ready){
                io.hbmCtrlR.valid           := 1.U
                when(ctrlArLen <=64.U){
                    St_ar                   := sIdle
                }.otherwise{
                    ctrlArLen               := ctrlArLen - 64.U
                }
            }
        }
    }
}
