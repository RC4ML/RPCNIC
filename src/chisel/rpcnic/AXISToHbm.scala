package cloud_fpga
import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
import common.storage._
import common.axi._
import common._
import network.roce.util._

class AXISToHbm() extends RawModule {

    val io = IO(new Bundle{
        val userClk     = Input(Clock())
        val userRstn    = Input(UInt(1.W))

        val hbmClk      = Input(Clock())
        val hbmRstn     = Input(UInt(1.W))

        val hbmCtrlAw   = Flipped(Decoupled(new RoceMsg))
        val hbmCtrlW    = Flipped(Decoupled(UInt(512.W)))

        val hbmCtrlAr   = Flipped(Decoupled(new RoceMsg))
        val hbmCtrlR    = (Decoupled(UInt(512.W)))

        val hbmAxi    = new AXI(33, 256, 6, 0, 4)
    })


    io.hbmAxi.hbm_init()

    val hbmCtrlAw   = Wire(Decoupled(new RoceMsg))
    val hbmCtrlW    = Wire(Decoupled(UInt(512.W)))

    val clkCvtAw    = XConverter(new RoceMsg, io.userClk, io.userRstn.asBool, io.hbmClk)
    clkCvtAw.io.in  <> io.hbmCtrlAw
    clkCvtAw.io.out <> hbmCtrlAw
    val clkCvtW     = XConverter(UInt(512.W), io.userClk, io.userRstn.asBool, io.hbmClk)
    clkCvtW.io.in   <> io.hbmCtrlW
    clkCvtW.io.out  <> hbmCtrlW


    withClockAndReset(io.hbmClk, ~io.hbmRstn.asBool) {
        val ctrlFifoAw  = XQueue(new RoceMsg, 1024, almostfull_threshold=800)
        val ctrlFifoAw_r  = XQueue(new RoceMsg, 1024, almostfull_threshold=800)
        val ctrlFifoW   = XQueue(UInt(512.W), 1024, almostfull_threshold=800)

        ctrlFifoAw.io.in    <> hbmCtrlAw
        ctrlFifoW.io.in     <> hbmCtrlW

        ToZero(ctrlFifoAw_r.io.in.valid)
        ToZero(ctrlFifoAw_r.io.in.bits)


        val sIdle :: sWrite :: sWriteSecond :: Nil = Enum(3)

        val St_aw   = RegInit(sIdle)
        val St_w    = RegInit(sIdle)
        val wrLen   = RegInit(UInt(9.W), 0.U)
        val ctrlWLen= RegInit(UInt(32.W), 0.U)
        val wdata_r = RegInit(UInt(256.W), 0.U)

        val ctrlAwAddr  = RegInit(UInt(33.W), 0.U)
        val ctrlAwLen  = RegInit(UInt(32.W), 0.U)

        io.hbmAxi.aw.valid      := St_aw === sWrite

        io.hbmAxi.aw.bits.addr  := ctrlAwAddr

        io.hbmAxi.aw.bits.len   := Mux(ctrlAwLen > 512.U, 0xf.U, ((ctrlAwLen >> 5.U)-1.U))
        io.hbmAxi.w.bits.data   := Mux(ctrlWLen(5), wdata_r, ctrlFifoW.io.out.bits(255, 0))
        io.hbmAxi.w.bits.strb   := "hffffffff".U
        io.hbmAxi.w.bits.last   := ((wrLen === 15.U)||(ctrlWLen <= 32.U)) && io.hbmAxi.w.fire()
        io.hbmAxi.w.valid       := ((St_w === sWrite) && ctrlFifoW.io.out.valid)||(St_w === sWriteSecond)
        io.hbmAxi.b.ready       := 1.U
        ctrlFifoAw.io.out.ready := St_aw === sIdle
        ctrlFifoAw_r.io.out.ready := St_w  === sIdle
        ctrlFifoW.io.out.ready  := io.hbmAxi.w.fire && (St_w  === sWrite)

        switch(St_aw){
            is(sIdle){
                when(ctrlFifoAw.io.out.fire()){
                    ctrlAwAddr                  := ctrlFifoAw.io.out.bits.addr
                    ctrlAwLen                   := ctrlFifoAw.io.out.bits.length
                    ctrlFifoAw_r.io.in.valid    := 1.U
                    ctrlFifoAw_r.io.in.bits     := ctrlFifoAw.io.out.bits
                    St_aw                       := sWrite
                }
            }
            is(sWrite){
                when(io.hbmAxi.aw.fire()){
                    when(ctrlAwLen > 512.U){
                        ctrlAwAddr              := ctrlAwAddr + 512.U
                        ctrlAwLen               := ctrlAwLen - 512.U
                        St_aw                   := sWrite
                    }.otherwise{
                        St_aw                   := sIdle
                    }
                }
            }
        }

        switch(St_w){
            is(sIdle){
                when(ctrlFifoAw_r.io.out.fire()){
                    ctrlWLen                    := ctrlFifoAw_r.io.out.bits.length
                    wrLen                       := 0.U
                    St_w                        := sWrite
                }
            }
            is(sWrite){
                when(io.hbmAxi.w.fire()){
                    wrLen                       := wrLen + 1.U
                    ctrlWLen                    := ctrlWLen - 32.U
                    wdata_r                     := ctrlFifoW.io.out.bits(511, 256)
                    St_w                        := sWriteSecond
                }
            }
            is(sWriteSecond){
                when(io.hbmAxi.w.fire()){
                    wrLen                       := wrLen + 1.U
                    when(wrLen === 15.U){
                        wrLen                   := 0.U
                    }
                    when(ctrlWLen > 32.U){
                        ctrlWLen                := ctrlWLen - 32.U
                        St_w                    := sWrite
                    }.otherwise{
                        St_w                    := sIdle
                    }
                }
            }
        }


    }

    //hbm read

    val hbmCtrlAr   = Wire(Decoupled(new RoceMsg))
    val hbmCtrlR    = Wire(Decoupled(UInt(512.W)))

    val clkCvtAr    = XConverter(new RoceMsg, io.userClk, io.userRstn.asBool, io.hbmClk)
    clkCvtAr.io.in  <> io.hbmCtrlAr
    clkCvtAr.io.out <> hbmCtrlAr
    val clkCvtR     = XConverter(UInt(512.W), io.hbmClk, io.userRstn.asBool, io.userClk)
    clkCvtR.io.out  <> io.hbmCtrlR
    clkCvtR.io.in   <> hbmCtrlR

    withClockAndReset(io.hbmClk, ~io.hbmRstn.asBool) {
        val ctrlFifoAr  = XQueue(new RoceMsg, 1024, almostfull_threshold=800)
        val ctrlFifoAr_r  = XQueue(new RoceMsg, 1024, almostfull_threshold=800)
        val ctrlFifoR   = XQueue(UInt(512.W), 1024, almostfull_threshold=800)

        ctrlFifoAr.io.in    <> hbmCtrlAr
        ctrlFifoR.io.out     <> hbmCtrlR

        ToZero(ctrlFifoAr_r.io.in.valid)
        ToZero(ctrlFifoAr_r.io.in.bits)

        val sIdle :: sWrite :: sWriteSecond :: Nil = Enum(3)

        val St_ar   = RegInit(sIdle)
        val St_r    = RegInit(sIdle)
        val ctrlRLen= RegInit(UInt(32.W), 0.U)
        val rdata_r = RegInit(UInt(256.W), 0.U)

        val ctrlArAddr  = RegInit(UInt(33.W), 0.U)
        val ctrlArLen  = RegInit(UInt(32.W), 0.U)

        io.hbmAxi.ar.valid      := St_ar === sWrite

        io.hbmAxi.ar.bits.addr  := ctrlArAddr

        io.hbmAxi.ar.bits.len   := Mux(ctrlArLen > 512.U, 0xf.U, ((ctrlArLen >> 5.U)-1.U))

        io.hbmAxi.r.ready       := (St_r === sWrite)||((St_r  === sWriteSecond)&& ctrlFifoR.io.out.ready)
        ctrlFifoAr.io.out.ready := St_ar === sIdle
        ctrlFifoAr_r.io.out.ready := St_r  === sIdle

        ctrlFifoR.io.in.valid   := ((St_r  === sWriteSecond)&& io.hbmAxi.r.fire)
        ctrlFifoR.io.in.bits    := Cat(io.hbmAxi.r.bits.data,rdata_r)

        switch(St_ar){
            is(sIdle){
                when(ctrlFifoAr.io.out.fire()){
                    ctrlArAddr                  := ctrlFifoAr.io.out.bits.addr
                    ctrlArLen                   := ctrlFifoAr.io.out.bits.length
                    ctrlFifoAr_r.io.in.valid    := 1.U
                    ctrlFifoAr_r.io.in.bits     := ctrlFifoAr.io.out.bits
                    St_ar                       := sWrite
                }
            }
            is(sWrite){
                when(io.hbmAxi.ar.fire()){
                    when(ctrlArLen > 512.U){
                        ctrlArAddr              := ctrlArAddr + 512.U
                        ctrlArLen               := ctrlArLen - 512.U
                        St_ar                   := sWrite
                    }.otherwise{
                        St_ar                   := sIdle
                    }
                }
            }
        }

        switch(St_r){
            is(sIdle){
                when(ctrlFifoAr_r.io.out.fire()){
                    ctrlRLen                    := ctrlFifoAr_r.io.out.bits.length
                    St_r                        := sWrite
                }
            }
            is(sWrite){
                when(io.hbmAxi.r.fire()){
                    ctrlRLen                    := ctrlRLen - 32.U
                    rdata_r                     := io.hbmAxi.r.bits.data
                    St_r                        := sWriteSecond
                }
            }
            is(sWriteSecond){
                when(io.hbmAxi.r.fire()){
                    when(ctrlRLen > 32.U){
                        ctrlRLen                := ctrlRLen - 32.U
                        St_r                    := sWrite
                    }.otherwise{
                        St_r                    := sIdle
                    }
                }
            }
        }
    }
}
