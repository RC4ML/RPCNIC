module MMCME4_ADV_Wrapper(
  input   io_CLKIN1,
  output  io_LOCKED,
  output  io_CLKOUT0,
  output  io_CLKOUT1,
  output  io_CLKOUT2,
  output  io_CLKOUT3
);
  wire  mmcm4_adv_CLKIN1; // @[Buf.scala 109:25]
  wire  mmcm4_adv_CLKIN2; // @[Buf.scala 109:25]
  wire  mmcm4_adv_RST; // @[Buf.scala 109:25]
  wire  mmcm4_adv_PWRDWN; // @[Buf.scala 109:25]
  wire  mmcm4_adv_CDDCREQ; // @[Buf.scala 109:25]
  wire  mmcm4_adv_CLKINSEL; // @[Buf.scala 109:25]
  wire [6:0] mmcm4_adv_DADDR; // @[Buf.scala 109:25]
  wire  mmcm4_adv_DEN; // @[Buf.scala 109:25]
  wire [15:0] mmcm4_adv_DI; // @[Buf.scala 109:25]
  wire  mmcm4_adv_DWE; // @[Buf.scala 109:25]
  wire  mmcm4_adv_PSCLK; // @[Buf.scala 109:25]
  wire  mmcm4_adv_PSEN; // @[Buf.scala 109:25]
  wire  mmcm4_adv_DCLK; // @[Buf.scala 109:25]
  wire  mmcm4_adv_PSINCDEC; // @[Buf.scala 109:25]
  wire  mmcm4_adv_LOCKED; // @[Buf.scala 109:25]
  wire  mmcm4_adv_CLKOUT0; // @[Buf.scala 109:25]
  wire  mmcm4_adv_CLKOUT1; // @[Buf.scala 109:25]
  wire  mmcm4_adv_CLKOUT2; // @[Buf.scala 109:25]
  wire  mmcm4_adv_CLKOUT3; // @[Buf.scala 109:25]
  wire  mmcm4_adv_CLKOUT4; // @[Buf.scala 109:25]
  wire  mmcm4_adv_CLKOUT5; // @[Buf.scala 109:25]
  wire  mmcm4_adv_CLKOUT6; // @[Buf.scala 109:25]
  MMCME4_ADV
    #(.CLKOUT5_DIVIDE(2.0), .CLKOUT3_DIVIDE(5.0), .CLKFBOUT_PHASE(0.0), .CLKIN1_PERIOD(10.0), .CLKOUT2_DIVIDE(10.0), .CLKOUT0_PHASE(0.0), .CLKFBOUT_MULT_F(10.0), .CLKOUT4_DIVIDE(2.0), .CLKOUT6_DIVIDE(2.0), .CLKOUT0_USE_FINE_PS("FALSE"), .COMPENSATION("INTERNAL"), .CLKOUT1_DIVIDE(10.0), .BANDWIDTH("OPTIMIZED"), .CLKFBOUT_USE_FINE_PS("FALSE"), .CLKOUT4_CASCADE("FALSE"), .CLKOUT0_DIVIDE_F(5.0), .CLKOUT0_DUTY_CYCLE(0.5), .REF_JITTER1(0.01), .DIVCLK_DIVIDE(1), .STARTUP_WAIT("FALSE"))
    mmcm4_adv ( // @[Buf.scala 109:25]
    .CLKIN1(mmcm4_adv_CLKIN1),
    .CLKIN2(mmcm4_adv_CLKIN2),
    .RST(mmcm4_adv_RST),
    .PWRDWN(mmcm4_adv_PWRDWN),
    .CDDCREQ(mmcm4_adv_CDDCREQ),
    .CLKINSEL(mmcm4_adv_CLKINSEL),
    .DADDR(mmcm4_adv_DADDR),
    .DEN(mmcm4_adv_DEN),
    .DI(mmcm4_adv_DI),
    .DWE(mmcm4_adv_DWE),
    .PSCLK(mmcm4_adv_PSCLK),
    .PSEN(mmcm4_adv_PSEN),
    .DCLK(mmcm4_adv_DCLK),
    .PSINCDEC(mmcm4_adv_PSINCDEC),
    .LOCKED(mmcm4_adv_LOCKED),
    .CLKOUT0(mmcm4_adv_CLKOUT0),
    .CLKOUT1(mmcm4_adv_CLKOUT1),
    .CLKOUT2(mmcm4_adv_CLKOUT2),
    .CLKOUT3(mmcm4_adv_CLKOUT3),
    .CLKOUT4(mmcm4_adv_CLKOUT4),
    .CLKOUT5(mmcm4_adv_CLKOUT5),
    .CLKOUT6(mmcm4_adv_CLKOUT6)
  );
  assign io_LOCKED = mmcm4_adv_LOCKED; // @[Buf.scala 123:25]
  assign io_CLKOUT0 = mmcm4_adv_CLKOUT0; // @[Buf.scala 124:26]
  assign io_CLKOUT1 = mmcm4_adv_CLKOUT1; // @[Buf.scala 125:26]
  assign io_CLKOUT2 = mmcm4_adv_CLKOUT2; // @[Buf.scala 126:26]
  assign io_CLKOUT3 = mmcm4_adv_CLKOUT3; // @[Buf.scala 127:26]
  assign mmcm4_adv_CLKIN1 = io_CLKIN1; // @[Buf.scala 121:25]
  assign mmcm4_adv_CLKIN2 = 1'h0; // @[Buf.scala 132:31]
  assign mmcm4_adv_RST = 1'h0; // @[Buf.scala 122:25]
  assign mmcm4_adv_PWRDWN = 1'h0; // @[Buf.scala 133:30]
  assign mmcm4_adv_CDDCREQ = 1'h0; // @[Buf.scala 134:32]
  assign mmcm4_adv_CLKINSEL = 1'h1; // @[Buf.scala 135:32]
  assign mmcm4_adv_DADDR = 7'h0; // @[Buf.scala 136:30]
  assign mmcm4_adv_DEN = 1'h0; // @[Buf.scala 137:28]
  assign mmcm4_adv_DI = 16'h0; // @[Buf.scala 138:26]
  assign mmcm4_adv_DWE = 1'h0; // @[Buf.scala 139:28]
  assign mmcm4_adv_PSCLK = 1'h0; // @[Buf.scala 140:30]
  assign mmcm4_adv_PSEN = 1'h0; // @[Buf.scala 141:28]
  assign mmcm4_adv_DCLK = 1'h0; // @[Buf.scala 142:28]
  assign mmcm4_adv_PSINCDEC = 1'h0; // @[Buf.scala 143:32]
endmodule
module DDR_DRIVER(
  input          io_ddrpin_ddr0_sys_100M_p,
  input          io_ddrpin_ddr0_sys_100M_n,
  output         io_ddrpin_act_n,
  output [16:0]  io_ddrpin_adr,
  output [1:0]   io_ddrpin_ba,
  output [1:0]   io_ddrpin_bg,
  output         io_ddrpin_cke,
  output         io_ddrpin_odt,
  output         io_ddrpin_cs_n,
  output         io_ddrpin_ck_t,
  output         io_ddrpin_ck_c,
  output         io_ddrpin_reset_n,
  output         io_ddrpin_parity,
  inout  [71:0]  io_ddrpin_dq,
  inout  [17:0]  io_ddrpin_dqs_t,
  inout  [17:0]  io_ddrpin_dqs_c,
  output         io_user_clk,
  output         io_user_rst,
  output         io_axi_aw_ready,
  input          io_axi_aw_valid,
  input  [33:0]  io_axi_aw_bits_addr,
  input  [1:0]   io_axi_aw_bits_burst,
  input  [3:0]   io_axi_aw_bits_cache,
  input  [3:0]   io_axi_aw_bits_id,
  input  [7:0]   io_axi_aw_bits_len,
  input          io_axi_aw_bits_lock,
  input  [2:0]   io_axi_aw_bits_prot,
  input  [3:0]   io_axi_aw_bits_qos,
  input  [2:0]   io_axi_aw_bits_size,
  output         io_axi_ar_ready,
  input          io_axi_ar_valid,
  input  [33:0]  io_axi_ar_bits_addr,
  input  [1:0]   io_axi_ar_bits_burst,
  input  [3:0]   io_axi_ar_bits_cache,
  input  [3:0]   io_axi_ar_bits_id,
  input  [7:0]   io_axi_ar_bits_len,
  input          io_axi_ar_bits_lock,
  input  [2:0]   io_axi_ar_bits_prot,
  input  [3:0]   io_axi_ar_bits_qos,
  input  [2:0]   io_axi_ar_bits_size,
  output         io_axi_w_ready,
  input          io_axi_w_valid,
  input  [511:0] io_axi_w_bits_data,
  input          io_axi_w_bits_last,
  input  [63:0]  io_axi_w_bits_strb,
  input          io_axi_r_ready,
  output         io_axi_r_valid,
  output [511:0] io_axi_r_bits_data,
  output         io_axi_r_bits_last,
  output [1:0]   io_axi_r_bits_resp,
  output [3:0]   io_axi_r_bits_id,
  input          io_axi_b_ready,
  output         io_axi_b_valid,
  output [3:0]   io_axi_b_bits_id,
  output [1:0]   io_axi_b_bits_resp
);
  wire  ddr0Sys100M_pad_O; // @[Buf.scala 51:34]
  wire  ddr0Sys100M_pad_I; // @[Buf.scala 51:34]
  wire  ddr0Sys100M_pad_IB; // @[Buf.scala 51:34]
  wire  DDR0_sys_clk_pad_O; // @[Buf.scala 33:34]
  wire  DDR0_sys_clk_pad_I; // @[Buf.scala 33:34]
  wire  instDDR_sys_rst; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_sys_clk_i; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_init_calib_complete; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_act_n; // @[DDR_driver.scala 62:25]
  wire [16:0] instDDR_c0_ddr4_adr; // @[DDR_driver.scala 62:25]
  wire [1:0] instDDR_c0_ddr4_ba; // @[DDR_driver.scala 62:25]
  wire [1:0] instDDR_c0_ddr4_bg; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_cke; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_odt; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_cs_n; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_ck_t; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_ck_c; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_reset_n; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_parity; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_ui_clk; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_ui_clk_sync_rst; // @[DDR_driver.scala 62:25]
  wire  instDDR_addn_ui_clkout1; // @[DDR_driver.scala 62:25]
  wire  instDDR_dbg_clk; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_ctrl_awvalid; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_ctrl_awready; // @[DDR_driver.scala 62:25]
  wire [31:0] instDDR_c0_ddr4_s_axi_ctrl_awaddr; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_ctrl_wvalid; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_ctrl_wready; // @[DDR_driver.scala 62:25]
  wire [31:0] instDDR_c0_ddr4_s_axi_ctrl_wdata; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_ctrl_bvalid; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_ctrl_bready; // @[DDR_driver.scala 62:25]
  wire [1:0] instDDR_c0_ddr4_s_axi_ctrl_bresp; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_ctrl_arvalid; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_ctrl_arready; // @[DDR_driver.scala 62:25]
  wire [31:0] instDDR_c0_ddr4_s_axi_ctrl_araddr; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_ctrl_rvalid; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_ctrl_rready; // @[DDR_driver.scala 62:25]
  wire [31:0] instDDR_c0_ddr4_s_axi_ctrl_rdata; // @[DDR_driver.scala 62:25]
  wire [1:0] instDDR_c0_ddr4_s_axi_ctrl_rresp; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_interrupt; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_aresetn; // @[DDR_driver.scala 62:25]
  wire [3:0] instDDR_c0_ddr4_s_axi_awid; // @[DDR_driver.scala 62:25]
  wire [33:0] instDDR_c0_ddr4_s_axi_awaddr; // @[DDR_driver.scala 62:25]
  wire [7:0] instDDR_c0_ddr4_s_axi_awlen; // @[DDR_driver.scala 62:25]
  wire [2:0] instDDR_c0_ddr4_s_axi_awsize; // @[DDR_driver.scala 62:25]
  wire [1:0] instDDR_c0_ddr4_s_axi_awburst; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_awlock; // @[DDR_driver.scala 62:25]
  wire [3:0] instDDR_c0_ddr4_s_axi_awcache; // @[DDR_driver.scala 62:25]
  wire [2:0] instDDR_c0_ddr4_s_axi_awprot; // @[DDR_driver.scala 62:25]
  wire [3:0] instDDR_c0_ddr4_s_axi_awqos; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_awready; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_awvalid; // @[DDR_driver.scala 62:25]
  wire [511:0] instDDR_c0_ddr4_s_axi_wdata; // @[DDR_driver.scala 62:25]
  wire [63:0] instDDR_c0_ddr4_s_axi_wstrb; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_wlast; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_wvalid; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_wready; // @[DDR_driver.scala 62:25]
  wire [3:0] instDDR_c0_ddr4_s_axi_bid; // @[DDR_driver.scala 62:25]
  wire [1:0] instDDR_c0_ddr4_s_axi_bresp; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_bvalid; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_bready; // @[DDR_driver.scala 62:25]
  wire [3:0] instDDR_c0_ddr4_s_axi_arid; // @[DDR_driver.scala 62:25]
  wire [33:0] instDDR_c0_ddr4_s_axi_araddr; // @[DDR_driver.scala 62:25]
  wire [7:0] instDDR_c0_ddr4_s_axi_arlen; // @[DDR_driver.scala 62:25]
  wire [2:0] instDDR_c0_ddr4_s_axi_arsize; // @[DDR_driver.scala 62:25]
  wire [1:0] instDDR_c0_ddr4_s_axi_arburst; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_arlock; // @[DDR_driver.scala 62:25]
  wire [3:0] instDDR_c0_ddr4_s_axi_arcache; // @[DDR_driver.scala 62:25]
  wire [2:0] instDDR_c0_ddr4_s_axi_arprot; // @[DDR_driver.scala 62:25]
  wire [3:0] instDDR_c0_ddr4_s_axi_arqos; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_arready; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_arvalid; // @[DDR_driver.scala 62:25]
  wire [3:0] instDDR_c0_ddr4_s_axi_rid; // @[DDR_driver.scala 62:25]
  wire [511:0] instDDR_c0_ddr4_s_axi_rdata; // @[DDR_driver.scala 62:25]
  wire [1:0] instDDR_c0_ddr4_s_axi_rresp; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_rlast; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_rvalid; // @[DDR_driver.scala 62:25]
  wire  instDDR_c0_ddr4_s_axi_rready; // @[DDR_driver.scala 62:25]
  wire [511:0] instDDR_dbg_bus; // @[DDR_driver.scala 62:25]
  wire  init_complete = instDDR_c0_init_calib_complete; // @[DDR_driver.scala 43:31 DDR_driver.scala 66:29]
  IBUFDS ddr0Sys100M_pad ( // @[Buf.scala 51:34]
    .O(ddr0Sys100M_pad_O),
    .I(ddr0Sys100M_pad_I),
    .IB(ddr0Sys100M_pad_IB)
  );
  BUFG DDR0_sys_clk_pad ( // @[Buf.scala 33:34]
    .O(DDR0_sys_clk_pad_O),
    .I(DDR0_sys_clk_pad_I)
  );
  DDRBlackBoxBase2 instDDR ( // @[DDR_driver.scala 62:25]
    .sys_rst(instDDR_sys_rst),
    .c0_sys_clk_i(instDDR_c0_sys_clk_i),
    .c0_init_calib_complete(instDDR_c0_init_calib_complete),
    .c0_ddr4_act_n(instDDR_c0_ddr4_act_n),
    .c0_ddr4_adr(instDDR_c0_ddr4_adr),
    .c0_ddr4_ba(instDDR_c0_ddr4_ba),
    .c0_ddr4_bg(instDDR_c0_ddr4_bg),
    .c0_ddr4_cke(instDDR_c0_ddr4_cke),
    .c0_ddr4_odt(instDDR_c0_ddr4_odt),
    .c0_ddr4_cs_n(instDDR_c0_ddr4_cs_n),
    .c0_ddr4_ck_t(instDDR_c0_ddr4_ck_t),
    .c0_ddr4_ck_c(instDDR_c0_ddr4_ck_c),
    .c0_ddr4_reset_n(instDDR_c0_ddr4_reset_n),
    .c0_ddr4_parity(instDDR_c0_ddr4_parity),
    .c0_ddr4_dq(io_ddrpin_dq),
    .c0_ddr4_dqs_c(io_ddrpin_dqs_c),
    .c0_ddr4_dqs_t(io_ddrpin_dqs_t),
    .c0_ddr4_ui_clk(instDDR_c0_ddr4_ui_clk),
    .c0_ddr4_ui_clk_sync_rst(instDDR_c0_ddr4_ui_clk_sync_rst),
    .addn_ui_clkout1(instDDR_addn_ui_clkout1),
    .dbg_clk(instDDR_dbg_clk),
    .c0_ddr4_s_axi_ctrl_awvalid(instDDR_c0_ddr4_s_axi_ctrl_awvalid),
    .c0_ddr4_s_axi_ctrl_awready(instDDR_c0_ddr4_s_axi_ctrl_awready),
    .c0_ddr4_s_axi_ctrl_awaddr(instDDR_c0_ddr4_s_axi_ctrl_awaddr),
    .c0_ddr4_s_axi_ctrl_wvalid(instDDR_c0_ddr4_s_axi_ctrl_wvalid),
    .c0_ddr4_s_axi_ctrl_wready(instDDR_c0_ddr4_s_axi_ctrl_wready),
    .c0_ddr4_s_axi_ctrl_wdata(instDDR_c0_ddr4_s_axi_ctrl_wdata),
    .c0_ddr4_s_axi_ctrl_bvalid(instDDR_c0_ddr4_s_axi_ctrl_bvalid),
    .c0_ddr4_s_axi_ctrl_bready(instDDR_c0_ddr4_s_axi_ctrl_bready),
    .c0_ddr4_s_axi_ctrl_bresp(instDDR_c0_ddr4_s_axi_ctrl_bresp),
    .c0_ddr4_s_axi_ctrl_arvalid(instDDR_c0_ddr4_s_axi_ctrl_arvalid),
    .c0_ddr4_s_axi_ctrl_arready(instDDR_c0_ddr4_s_axi_ctrl_arready),
    .c0_ddr4_s_axi_ctrl_araddr(instDDR_c0_ddr4_s_axi_ctrl_araddr),
    .c0_ddr4_s_axi_ctrl_rvalid(instDDR_c0_ddr4_s_axi_ctrl_rvalid),
    .c0_ddr4_s_axi_ctrl_rready(instDDR_c0_ddr4_s_axi_ctrl_rready),
    .c0_ddr4_s_axi_ctrl_rdata(instDDR_c0_ddr4_s_axi_ctrl_rdata),
    .c0_ddr4_s_axi_ctrl_rresp(instDDR_c0_ddr4_s_axi_ctrl_rresp),
    .c0_ddr4_interrupt(instDDR_c0_ddr4_interrupt),
    .c0_ddr4_aresetn(instDDR_c0_ddr4_aresetn),
    .c0_ddr4_s_axi_awid(instDDR_c0_ddr4_s_axi_awid),
    .c0_ddr4_s_axi_awaddr(instDDR_c0_ddr4_s_axi_awaddr),
    .c0_ddr4_s_axi_awlen(instDDR_c0_ddr4_s_axi_awlen),
    .c0_ddr4_s_axi_awsize(instDDR_c0_ddr4_s_axi_awsize),
    .c0_ddr4_s_axi_awburst(instDDR_c0_ddr4_s_axi_awburst),
    .c0_ddr4_s_axi_awlock(instDDR_c0_ddr4_s_axi_awlock),
    .c0_ddr4_s_axi_awcache(instDDR_c0_ddr4_s_axi_awcache),
    .c0_ddr4_s_axi_awprot(instDDR_c0_ddr4_s_axi_awprot),
    .c0_ddr4_s_axi_awqos(instDDR_c0_ddr4_s_axi_awqos),
    .c0_ddr4_s_axi_awready(instDDR_c0_ddr4_s_axi_awready),
    .c0_ddr4_s_axi_awvalid(instDDR_c0_ddr4_s_axi_awvalid),
    .c0_ddr4_s_axi_wdata(instDDR_c0_ddr4_s_axi_wdata),
    .c0_ddr4_s_axi_wstrb(instDDR_c0_ddr4_s_axi_wstrb),
    .c0_ddr4_s_axi_wlast(instDDR_c0_ddr4_s_axi_wlast),
    .c0_ddr4_s_axi_wvalid(instDDR_c0_ddr4_s_axi_wvalid),
    .c0_ddr4_s_axi_wready(instDDR_c0_ddr4_s_axi_wready),
    .c0_ddr4_s_axi_bid(instDDR_c0_ddr4_s_axi_bid),
    .c0_ddr4_s_axi_bresp(instDDR_c0_ddr4_s_axi_bresp),
    .c0_ddr4_s_axi_bvalid(instDDR_c0_ddr4_s_axi_bvalid),
    .c0_ddr4_s_axi_bready(instDDR_c0_ddr4_s_axi_bready),
    .c0_ddr4_s_axi_arid(instDDR_c0_ddr4_s_axi_arid),
    .c0_ddr4_s_axi_araddr(instDDR_c0_ddr4_s_axi_araddr),
    .c0_ddr4_s_axi_arlen(instDDR_c0_ddr4_s_axi_arlen),
    .c0_ddr4_s_axi_arsize(instDDR_c0_ddr4_s_axi_arsize),
    .c0_ddr4_s_axi_arburst(instDDR_c0_ddr4_s_axi_arburst),
    .c0_ddr4_s_axi_arlock(instDDR_c0_ddr4_s_axi_arlock),
    .c0_ddr4_s_axi_arcache(instDDR_c0_ddr4_s_axi_arcache),
    .c0_ddr4_s_axi_arprot(instDDR_c0_ddr4_s_axi_arprot),
    .c0_ddr4_s_axi_arqos(instDDR_c0_ddr4_s_axi_arqos),
    .c0_ddr4_s_axi_arready(instDDR_c0_ddr4_s_axi_arready),
    .c0_ddr4_s_axi_arvalid(instDDR_c0_ddr4_s_axi_arvalid),
    .c0_ddr4_s_axi_rid(instDDR_c0_ddr4_s_axi_rid),
    .c0_ddr4_s_axi_rdata(instDDR_c0_ddr4_s_axi_rdata),
    .c0_ddr4_s_axi_rresp(instDDR_c0_ddr4_s_axi_rresp),
    .c0_ddr4_s_axi_rlast(instDDR_c0_ddr4_s_axi_rlast),
    .c0_ddr4_s_axi_rvalid(instDDR_c0_ddr4_s_axi_rvalid),
    .c0_ddr4_s_axi_rready(instDDR_c0_ddr4_s_axi_rready),
    .dbg_bus(instDDR_dbg_bus)
  );
  assign io_ddrpin_act_n = instDDR_c0_ddr4_act_n; // @[DDR_driver.scala 67:31]
  assign io_ddrpin_adr = instDDR_c0_ddr4_adr; // @[DDR_driver.scala 68:31]
  assign io_ddrpin_ba = instDDR_c0_ddr4_ba; // @[DDR_driver.scala 69:31]
  assign io_ddrpin_bg = instDDR_c0_ddr4_bg; // @[DDR_driver.scala 70:31]
  assign io_ddrpin_cke = instDDR_c0_ddr4_cke; // @[DDR_driver.scala 71:31]
  assign io_ddrpin_odt = instDDR_c0_ddr4_odt; // @[DDR_driver.scala 72:31]
  assign io_ddrpin_cs_n = instDDR_c0_ddr4_cs_n; // @[DDR_driver.scala 73:31]
  assign io_ddrpin_ck_t = instDDR_c0_ddr4_ck_t; // @[DDR_driver.scala 74:31]
  assign io_ddrpin_ck_c = instDDR_c0_ddr4_ck_c; // @[DDR_driver.scala 75:31]
  assign io_ddrpin_reset_n = instDDR_c0_ddr4_reset_n; // @[DDR_driver.scala 76:31]
  assign io_ddrpin_parity = instDDR_c0_ddr4_parity; // @[DDR_driver.scala 78:31]
  assign io_user_clk = instDDR_c0_ddr4_ui_clk; // @[DDR_driver.scala 83:44]
  assign io_user_rst = instDDR_c0_ddr4_ui_clk_sync_rst | ~init_complete; // @[DDR_driver.scala 84:80]
  assign io_axi_aw_ready = instDDR_c0_ddr4_s_axi_awready; // @[DDR_driver.scala 145:52]
  assign io_axi_ar_ready = instDDR_c0_ddr4_s_axi_arready; // @[DDR_driver.scala 168:52]
  assign io_axi_w_ready = instDDR_c0_ddr4_s_axi_wready; // @[DDR_driver.scala 151:52]
  assign io_axi_r_valid = instDDR_c0_ddr4_s_axi_rvalid; // @[DDR_driver.scala 174:52]
  assign io_axi_r_bits_data = instDDR_c0_ddr4_s_axi_rdata; // @[DDR_driver.scala 171:52]
  assign io_axi_r_bits_last = instDDR_c0_ddr4_s_axi_rlast; // @[DDR_driver.scala 173:52]
  assign io_axi_r_bits_resp = instDDR_c0_ddr4_s_axi_rresp; // @[DDR_driver.scala 172:52]
  assign io_axi_r_bits_id = instDDR_c0_ddr4_s_axi_rid; // @[DDR_driver.scala 170:52]
  assign io_axi_b_valid = instDDR_c0_ddr4_s_axi_bvalid; // @[DDR_driver.scala 155:49]
  assign io_axi_b_bits_id = instDDR_c0_ddr4_s_axi_bid; // @[DDR_driver.scala 153:49]
  assign io_axi_b_bits_resp = instDDR_c0_ddr4_s_axi_bresp; // @[DDR_driver.scala 154:49]
  assign ddr0Sys100M_pad_I = io_ddrpin_ddr0_sys_100M_p; // @[Buf.scala 52:26]
  assign ddr0Sys100M_pad_IB = io_ddrpin_ddr0_sys_100M_n; // @[Buf.scala 53:27]
  assign DDR0_sys_clk_pad_I = ddr0Sys100M_pad_O; // @[Buf.scala 34:26]
  assign instDDR_sys_rst = 1'h0; // @[DDR_driver.scala 64:39]
  assign instDDR_c0_sys_clk_i = DDR0_sys_clk_pad_O; // @[DDR_driver.scala 65:39]
  assign instDDR_c0_ddr4_s_axi_ctrl_awvalid = 1'h0; // @[DDR_driver.scala 113:50]
  assign instDDR_c0_ddr4_s_axi_ctrl_awaddr = 32'h0; // @[DDR_driver.scala 115:50]
  assign instDDR_c0_ddr4_s_axi_ctrl_wvalid = 1'h0; // @[DDR_driver.scala 116:50]
  assign instDDR_c0_ddr4_s_axi_ctrl_wdata = 32'h0; // @[DDR_driver.scala 118:50]
  assign instDDR_c0_ddr4_s_axi_ctrl_bready = 1'h1; // @[DDR_driver.scala 120:50]
  assign instDDR_c0_ddr4_s_axi_ctrl_arvalid = 1'h0; // @[DDR_driver.scala 122:50]
  assign instDDR_c0_ddr4_s_axi_ctrl_araddr = 32'h0; // @[DDR_driver.scala 124:50]
  assign instDDR_c0_ddr4_s_axi_ctrl_rready = 1'h1; // @[DDR_driver.scala 126:50]
  assign instDDR_c0_ddr4_aresetn = ~io_user_rst; // @[DDR_driver.scala 133:62]
  assign instDDR_c0_ddr4_s_axi_awid = io_axi_aw_bits_id; // @[DDR_driver.scala 135:52]
  assign instDDR_c0_ddr4_s_axi_awaddr = io_axi_aw_bits_addr; // @[DDR_driver.scala 136:52]
  assign instDDR_c0_ddr4_s_axi_awlen = io_axi_aw_bits_len; // @[DDR_driver.scala 137:52]
  assign instDDR_c0_ddr4_s_axi_awsize = io_axi_aw_bits_size; // @[DDR_driver.scala 138:52]
  assign instDDR_c0_ddr4_s_axi_awburst = io_axi_aw_bits_burst; // @[DDR_driver.scala 139:52]
  assign instDDR_c0_ddr4_s_axi_awlock = io_axi_aw_bits_lock; // @[DDR_driver.scala 140:52]
  assign instDDR_c0_ddr4_s_axi_awcache = io_axi_aw_bits_cache; // @[DDR_driver.scala 141:52]
  assign instDDR_c0_ddr4_s_axi_awprot = io_axi_aw_bits_prot; // @[DDR_driver.scala 142:52]
  assign instDDR_c0_ddr4_s_axi_awqos = io_axi_aw_bits_qos; // @[DDR_driver.scala 143:52]
  assign instDDR_c0_ddr4_s_axi_awvalid = io_axi_aw_valid; // @[DDR_driver.scala 144:52]
  assign instDDR_c0_ddr4_s_axi_wdata = io_axi_w_bits_data; // @[DDR_driver.scala 147:52]
  assign instDDR_c0_ddr4_s_axi_wstrb = io_axi_w_bits_strb; // @[DDR_driver.scala 148:52]
  assign instDDR_c0_ddr4_s_axi_wlast = io_axi_w_bits_last; // @[DDR_driver.scala 149:52]
  assign instDDR_c0_ddr4_s_axi_wvalid = io_axi_w_valid; // @[DDR_driver.scala 150:52]
  assign instDDR_c0_ddr4_s_axi_bready = io_axi_b_ready; // @[DDR_driver.scala 156:52]
  assign instDDR_c0_ddr4_s_axi_arid = io_axi_ar_bits_id; // @[DDR_driver.scala 158:52]
  assign instDDR_c0_ddr4_s_axi_araddr = io_axi_ar_bits_addr; // @[DDR_driver.scala 159:52]
  assign instDDR_c0_ddr4_s_axi_arlen = io_axi_ar_bits_len; // @[DDR_driver.scala 160:52]
  assign instDDR_c0_ddr4_s_axi_arsize = io_axi_ar_bits_size; // @[DDR_driver.scala 161:52]
  assign instDDR_c0_ddr4_s_axi_arburst = io_axi_ar_bits_burst; // @[DDR_driver.scala 162:52]
  assign instDDR_c0_ddr4_s_axi_arlock = io_axi_ar_bits_lock; // @[DDR_driver.scala 163:52]
  assign instDDR_c0_ddr4_s_axi_arcache = io_axi_ar_bits_cache; // @[DDR_driver.scala 164:52]
  assign instDDR_c0_ddr4_s_axi_arprot = io_axi_ar_bits_prot; // @[DDR_driver.scala 165:52]
  assign instDDR_c0_ddr4_s_axi_arqos = io_axi_ar_bits_qos; // @[DDR_driver.scala 166:52]
  assign instDDR_c0_ddr4_s_axi_arvalid = io_axi_ar_valid; // @[DDR_driver.scala 167:52]
  assign instDDR_c0_ddr4_s_axi_rready = io_axi_r_ready; // @[DDR_driver.scala 175:52]
endmodule
module StaticU280Top(
  input         sysClkP,
  input         sysClkN,
  output [7:0]  qdmaPin_tx_p,
  output [7:0]  qdmaPin_tx_n,
  input  [7:0]  qdmaPin_rx_p,
  input  [7:0]  qdmaPin_rx_n,
  input         qdmaPin_sys_clk_p,
  input         qdmaPin_sys_clk_n,
  input         qdmaPin_sys_rst_n,
  output [3:0]  cmacPin_tx_p,
  output [3:0]  cmacPin_tx_n,
  input  [3:0]  cmacPin_rx_p,
  input  [3:0]  cmacPin_rx_n,
  input         cmacPin_gt_clk_p,
  input         cmacPin_gt_clk_n,
  output [3:0]  cmacPin2_tx_p,
  output [3:0]  cmacPin2_tx_n,
  input  [3:0]  cmacPin2_rx_p,
  input  [3:0]  cmacPin2_rx_n,
  input         cmacPin2_gt_clk_p,
  input         cmacPin2_gt_clk_n,
  input         ddrPin2_ddr0_sys_100M_p,
  input         ddrPin2_ddr0_sys_100M_n,
  output        ddrPin2_act_n,
  output [16:0] ddrPin2_adr,
  output [1:0]  ddrPin2_ba,
  output [1:0]  ddrPin2_bg,
  output        ddrPin2_cke,
  output        ddrPin2_odt,
  output        ddrPin2_cs_n,
  output        ddrPin2_ck_t,
  output        ddrPin2_ck_c,
  output        ddrPin2_reset_n,
  output        ddrPin2_parity,
  inout  [71:0] ddrPin2_dq,
  inout  [17:0] ddrPin2_dqs_t,
  inout  [17:0] ddrPin2_dqs_c,
  output        hbmCattrip
);
  wire  sysClk_pad_O; // @[Buf.scala 51:34]
  wire  sysClk_pad_I; // @[Buf.scala 51:34]
  wire  sysClk_pad_IB; // @[Buf.scala 51:34]
  wire  sysClk_pad_1_O; // @[Buf.scala 33:34]
  wire  sysClk_pad_1_I; // @[Buf.scala 33:34]
  wire  instQdma_sys_rst_n; // @[StaticU280Top.scala 49:30]
  wire  instQdma_sys_clk; // @[StaticU280Top.scala 49:30]
  wire  instQdma_sys_clk_gt; // @[StaticU280Top.scala 49:30]
  wire [15:0] instQdma_pci_exp_txn; // @[StaticU280Top.scala 49:30]
  wire [15:0] instQdma_pci_exp_txp; // @[StaticU280Top.scala 49:30]
  wire [15:0] instQdma_pci_exp_rxn; // @[StaticU280Top.scala 49:30]
  wire [15:0] instQdma_pci_exp_rxp; // @[StaticU280Top.scala 49:30]
  wire [3:0] instQdma_m_axib_awid; // @[StaticU280Top.scala 49:30]
  wire [63:0] instQdma_m_axib_awaddr; // @[StaticU280Top.scala 49:30]
  wire [7:0] instQdma_m_axib_awlen; // @[StaticU280Top.scala 49:30]
  wire [2:0] instQdma_m_axib_awsize; // @[StaticU280Top.scala 49:30]
  wire [1:0] instQdma_m_axib_awburst; // @[StaticU280Top.scala 49:30]
  wire [2:0] instQdma_m_axib_awprot; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_awlock; // @[StaticU280Top.scala 49:30]
  wire [3:0] instQdma_m_axib_awcache; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_awvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_awready; // @[StaticU280Top.scala 49:30]
  wire [511:0] instQdma_m_axib_wdata; // @[StaticU280Top.scala 49:30]
  wire [63:0] instQdma_m_axib_wstrb; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_wlast; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_wvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_wready; // @[StaticU280Top.scala 49:30]
  wire [3:0] instQdma_m_axib_bid; // @[StaticU280Top.scala 49:30]
  wire [1:0] instQdma_m_axib_bresp; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_bvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_bready; // @[StaticU280Top.scala 49:30]
  wire [3:0] instQdma_m_axib_arid; // @[StaticU280Top.scala 49:30]
  wire [63:0] instQdma_m_axib_araddr; // @[StaticU280Top.scala 49:30]
  wire [7:0] instQdma_m_axib_arlen; // @[StaticU280Top.scala 49:30]
  wire [2:0] instQdma_m_axib_arsize; // @[StaticU280Top.scala 49:30]
  wire [1:0] instQdma_m_axib_arburst; // @[StaticU280Top.scala 49:30]
  wire [2:0] instQdma_m_axib_arprot; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_arlock; // @[StaticU280Top.scala 49:30]
  wire [3:0] instQdma_m_axib_arcache; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_arvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_arready; // @[StaticU280Top.scala 49:30]
  wire [3:0] instQdma_m_axib_rid; // @[StaticU280Top.scala 49:30]
  wire [511:0] instQdma_m_axib_rdata; // @[StaticU280Top.scala 49:30]
  wire [1:0] instQdma_m_axib_rresp; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_rlast; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_rvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axib_rready; // @[StaticU280Top.scala 49:30]
  wire [31:0] instQdma_m_axil_awaddr; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axil_awvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axil_awready; // @[StaticU280Top.scala 49:30]
  wire [31:0] instQdma_m_axil_wdata; // @[StaticU280Top.scala 49:30]
  wire [3:0] instQdma_m_axil_wstrb; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axil_wvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axil_wready; // @[StaticU280Top.scala 49:30]
  wire [1:0] instQdma_m_axil_bresp; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axil_bvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axil_bready; // @[StaticU280Top.scala 49:30]
  wire [31:0] instQdma_m_axil_araddr; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axil_arvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axil_arready; // @[StaticU280Top.scala 49:30]
  wire [31:0] instQdma_m_axil_rdata; // @[StaticU280Top.scala 49:30]
  wire [1:0] instQdma_m_axil_rresp; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axil_rvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axil_rready; // @[StaticU280Top.scala 49:30]
  wire  instQdma_axi_aclk; // @[StaticU280Top.scala 49:30]
  wire  instQdma_axi_aresetn; // @[StaticU280Top.scala 49:30]
  wire  instQdma_soft_reset_n; // @[StaticU280Top.scala 49:30]
  wire [63:0] instQdma_h2c_byp_in_st_addr; // @[StaticU280Top.scala 49:30]
  wire [31:0] instQdma_h2c_byp_in_st_len; // @[StaticU280Top.scala 49:30]
  wire  instQdma_h2c_byp_in_st_eop; // @[StaticU280Top.scala 49:30]
  wire  instQdma_h2c_byp_in_st_sop; // @[StaticU280Top.scala 49:30]
  wire  instQdma_h2c_byp_in_st_mrkr_req; // @[StaticU280Top.scala 49:30]
  wire  instQdma_h2c_byp_in_st_sdi; // @[StaticU280Top.scala 49:30]
  wire [10:0] instQdma_h2c_byp_in_st_qid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_h2c_byp_in_st_error; // @[StaticU280Top.scala 49:30]
  wire [7:0] instQdma_h2c_byp_in_st_func; // @[StaticU280Top.scala 49:30]
  wire [15:0] instQdma_h2c_byp_in_st_cidx; // @[StaticU280Top.scala 49:30]
  wire [2:0] instQdma_h2c_byp_in_st_port_id; // @[StaticU280Top.scala 49:30]
  wire  instQdma_h2c_byp_in_st_no_dma; // @[StaticU280Top.scala 49:30]
  wire  instQdma_h2c_byp_in_st_vld; // @[StaticU280Top.scala 49:30]
  wire  instQdma_h2c_byp_in_st_rdy; // @[StaticU280Top.scala 49:30]
  wire [63:0] instQdma_c2h_byp_in_st_csh_addr; // @[StaticU280Top.scala 49:30]
  wire [10:0] instQdma_c2h_byp_in_st_csh_qid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_c2h_byp_in_st_csh_error; // @[StaticU280Top.scala 49:30]
  wire [7:0] instQdma_c2h_byp_in_st_csh_func; // @[StaticU280Top.scala 49:30]
  wire [2:0] instQdma_c2h_byp_in_st_csh_port_id; // @[StaticU280Top.scala 49:30]
  wire [6:0] instQdma_c2h_byp_in_st_csh_pfch_tag; // @[StaticU280Top.scala 49:30]
  wire  instQdma_c2h_byp_in_st_csh_vld; // @[StaticU280Top.scala 49:30]
  wire  instQdma_c2h_byp_in_st_csh_rdy; // @[StaticU280Top.scala 49:30]
  wire [511:0] instQdma_s_axis_c2h_tdata; // @[StaticU280Top.scala 49:30]
  wire [31:0] instQdma_s_axis_c2h_tcrc; // @[StaticU280Top.scala 49:30]
  wire  instQdma_s_axis_c2h_ctrl_marker; // @[StaticU280Top.scala 49:30]
  wire [6:0] instQdma_s_axis_c2h_ctrl_ecc; // @[StaticU280Top.scala 49:30]
  wire [31:0] instQdma_s_axis_c2h_ctrl_len; // @[StaticU280Top.scala 49:30]
  wire [2:0] instQdma_s_axis_c2h_ctrl_port_id; // @[StaticU280Top.scala 49:30]
  wire [10:0] instQdma_s_axis_c2h_ctrl_qid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_s_axis_c2h_ctrl_has_cmpt; // @[StaticU280Top.scala 49:30]
  wire [5:0] instQdma_s_axis_c2h_mty; // @[StaticU280Top.scala 49:30]
  wire  instQdma_s_axis_c2h_tlast; // @[StaticU280Top.scala 49:30]
  wire  instQdma_s_axis_c2h_tvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_s_axis_c2h_tready; // @[StaticU280Top.scala 49:30]
  wire [511:0] instQdma_m_axis_h2c_tdata; // @[StaticU280Top.scala 49:30]
  wire [31:0] instQdma_m_axis_h2c_tcrc; // @[StaticU280Top.scala 49:30]
  wire [10:0] instQdma_m_axis_h2c_tuser_qid; // @[StaticU280Top.scala 49:30]
  wire [2:0] instQdma_m_axis_h2c_tuser_port_id; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axis_h2c_tuser_err; // @[StaticU280Top.scala 49:30]
  wire [31:0] instQdma_m_axis_h2c_tuser_mdata; // @[StaticU280Top.scala 49:30]
  wire [5:0] instQdma_m_axis_h2c_tuser_mty; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axis_h2c_tuser_zero_byte; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axis_h2c_tlast; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axis_h2c_tvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_m_axis_h2c_tready; // @[StaticU280Top.scala 49:30]
  wire  instQdma_axis_c2h_status_drop; // @[StaticU280Top.scala 49:30]
  wire  instQdma_axis_c2h_status_last; // @[StaticU280Top.scala 49:30]
  wire  instQdma_axis_c2h_status_cmp; // @[StaticU280Top.scala 49:30]
  wire  instQdma_axis_c2h_status_valid; // @[StaticU280Top.scala 49:30]
  wire [10:0] instQdma_axis_c2h_status_qid; // @[StaticU280Top.scala 49:30]
  wire [511:0] instQdma_s_axis_c2h_cmpt_tdata; // @[StaticU280Top.scala 49:30]
  wire [1:0] instQdma_s_axis_c2h_cmpt_size; // @[StaticU280Top.scala 49:30]
  wire [15:0] instQdma_s_axis_c2h_cmpt_dpar; // @[StaticU280Top.scala 49:30]
  wire  instQdma_s_axis_c2h_cmpt_tvalid; // @[StaticU280Top.scala 49:30]
  wire  instQdma_s_axis_c2h_cmpt_tready; // @[StaticU280Top.scala 49:30]
  wire [10:0] instQdma_s_axis_c2h_cmpt_ctrl_qid; // @[StaticU280Top.scala 49:30]
  wire [1:0] instQdma_s_axis_c2h_cmpt_ctrl_cmpt_type; // @[StaticU280Top.scala 49:30]
  wire [15:0] instQdma_s_axis_c2h_cmpt_ctrl_wait_pld_pkt_id; // @[StaticU280Top.scala 49:30]
  wire  instQdma_s_axis_c2h_cmpt_ctrl_no_wrb_marker; // @[StaticU280Top.scala 49:30]
  wire [2:0] instQdma_s_axis_c2h_cmpt_ctrl_port_id; // @[StaticU280Top.scala 49:30]
  wire  instQdma_s_axis_c2h_cmpt_ctrl_marker; // @[StaticU280Top.scala 49:30]
  wire  instQdma_s_axis_c2h_cmpt_ctrl_user_trig; // @[StaticU280Top.scala 49:30]
  wire [2:0] instQdma_s_axis_c2h_cmpt_ctrl_col_idx; // @[StaticU280Top.scala 49:30]
  wire [2:0] instQdma_s_axis_c2h_cmpt_ctrl_err_idx; // @[StaticU280Top.scala 49:30]
  wire  instQdma_h2c_byp_out_rdy; // @[StaticU280Top.scala 49:30]
  wire  instQdma_c2h_byp_out_rdy; // @[StaticU280Top.scala 49:30]
  wire  instQdma_tm_dsc_sts_rdy; // @[StaticU280Top.scala 49:30]
  wire  instQdma_dsc_crdt_in_vld; // @[StaticU280Top.scala 49:30]
  wire  instQdma_dsc_crdt_in_rdy; // @[StaticU280Top.scala 49:30]
  wire  instQdma_dsc_crdt_in_dir; // @[StaticU280Top.scala 49:30]
  wire  instQdma_dsc_crdt_in_fence; // @[StaticU280Top.scala 49:30]
  wire [10:0] instQdma_dsc_crdt_in_qid; // @[StaticU280Top.scala 49:30]
  wire [15:0] instQdma_dsc_crdt_in_crdt; // @[StaticU280Top.scala 49:30]
  wire  instQdma_qsts_out_rdy; // @[StaticU280Top.scala 49:30]
  wire  instQdma_usr_irq_in_vld; // @[StaticU280Top.scala 49:30]
  wire [10:0] instQdma_usr_irq_in_vec; // @[StaticU280Top.scala 49:30]
  wire [7:0] instQdma_usr_irq_in_fnc; // @[StaticU280Top.scala 49:30]
  wire  instQdma_usr_irq_out_ack; // @[StaticU280Top.scala 49:30]
  wire  instQdma_usr_irq_out_fail; // @[StaticU280Top.scala 49:30]
  wire  ibufds_gte4_inst_O; // @[StaticU280Top.scala 56:38]
  wire  ibufds_gte4_inst_ODIV2; // @[StaticU280Top.scala 56:38]
  wire  ibufds_gte4_inst_CEB; // @[StaticU280Top.scala 56:38]
  wire  ibufds_gte4_inst_I; // @[StaticU280Top.scala 56:38]
  wire  ibufds_gte4_inst_IB; // @[StaticU280Top.scala 56:38]
  wire  instQdma_io_sys_rst_n_pad_O; // @[Buf.scala 17:34]
  wire  instQdma_io_sys_rst_n_pad_I; // @[Buf.scala 17:34]
  wire  mmcmUsrClk_io_CLKIN1; // @[StaticU280Top.scala 72:33]
  wire  mmcmUsrClk_io_LOCKED; // @[StaticU280Top.scala 72:33]
  wire  mmcmUsrClk_io_CLKOUT0; // @[StaticU280Top.scala 72:33]
  wire  mmcmUsrClk_io_CLKOUT1; // @[StaticU280Top.scala 72:33]
  wire  mmcmUsrClk_io_CLKOUT2; // @[StaticU280Top.scala 72:33]
  wire  mmcmUsrClk_io_CLKOUT3; // @[StaticU280Top.scala 72:33]
  wire  core_clock; // @[StaticU280Top.scala 92:26]
  wire  core_reset; // @[StaticU280Top.scala 92:26]
  wire  core_io_sysClk; // @[StaticU280Top.scala 92:26]
  wire  core_io_cmacClk; // @[StaticU280Top.scala 92:26]
  wire  core_io_serClk; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_cmacPin_tx_p; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_cmacPin_tx_n; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_cmacPin_rx_p; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_cmacPin_rx_n; // @[StaticU280Top.scala 92:26]
  wire  core_io_cmacPin_gt_clk_p; // @[StaticU280Top.scala 92:26]
  wire  core_io_cmacPin_gt_clk_n; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_cmacPin2_tx_p; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_cmacPin2_tx_n; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_cmacPin2_rx_p; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_cmacPin2_rx_n; // @[StaticU280Top.scala 92:26]
  wire  core_io_cmacPin2_gt_clk_p; // @[StaticU280Top.scala 92:26]
  wire  core_io_cmacPin2_gt_clk_n; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_clk; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_rst; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_aw_ready; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_aw_valid; // @[StaticU280Top.scala 92:26]
  wire [33:0] core_io_ddrPort2_axi_aw_bits_addr; // @[StaticU280Top.scala 92:26]
  wire [1:0] core_io_ddrPort2_axi_aw_bits_burst; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_ddrPort2_axi_aw_bits_cache; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_ddrPort2_axi_aw_bits_id; // @[StaticU280Top.scala 92:26]
  wire [7:0] core_io_ddrPort2_axi_aw_bits_len; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_aw_bits_lock; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_ddrPort2_axi_aw_bits_prot; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_ddrPort2_axi_aw_bits_qos; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_ddrPort2_axi_aw_bits_region; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_ddrPort2_axi_aw_bits_size; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_ar_ready; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_ar_valid; // @[StaticU280Top.scala 92:26]
  wire [33:0] core_io_ddrPort2_axi_ar_bits_addr; // @[StaticU280Top.scala 92:26]
  wire [1:0] core_io_ddrPort2_axi_ar_bits_burst; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_ddrPort2_axi_ar_bits_cache; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_ddrPort2_axi_ar_bits_id; // @[StaticU280Top.scala 92:26]
  wire [7:0] core_io_ddrPort2_axi_ar_bits_len; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_ar_bits_lock; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_ddrPort2_axi_ar_bits_prot; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_ddrPort2_axi_ar_bits_qos; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_ddrPort2_axi_ar_bits_region; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_ddrPort2_axi_ar_bits_size; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_w_ready; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_w_valid; // @[StaticU280Top.scala 92:26]
  wire [511:0] core_io_ddrPort2_axi_w_bits_data; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_w_bits_last; // @[StaticU280Top.scala 92:26]
  wire [63:0] core_io_ddrPort2_axi_w_bits_strb; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_r_ready; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_r_valid; // @[StaticU280Top.scala 92:26]
  wire [511:0] core_io_ddrPort2_axi_r_bits_data; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_r_bits_last; // @[StaticU280Top.scala 92:26]
  wire [1:0] core_io_ddrPort2_axi_r_bits_resp; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_ddrPort2_axi_r_bits_id; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_b_ready; // @[StaticU280Top.scala 92:26]
  wire  core_io_ddrPort2_axi_b_valid; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_ddrPort2_axi_b_bits_id; // @[StaticU280Top.scala 92:26]
  wire [1:0] core_io_ddrPort2_axi_b_bits_resp; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_axi_aclk; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_axi_aresetn; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_qdma_m_axib_awid; // @[StaticU280Top.scala 92:26]
  wire [63:0] core_io_qdma_m_axib_awaddr; // @[StaticU280Top.scala 92:26]
  wire [7:0] core_io_qdma_m_axib_awlen; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_qdma_m_axib_awsize; // @[StaticU280Top.scala 92:26]
  wire [1:0] core_io_qdma_m_axib_awburst; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_qdma_m_axib_awprot; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_awlock; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_qdma_m_axib_awcache; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_awvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_awready; // @[StaticU280Top.scala 92:26]
  wire [511:0] core_io_qdma_m_axib_wdata; // @[StaticU280Top.scala 92:26]
  wire [63:0] core_io_qdma_m_axib_wstrb; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_wlast; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_wvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_wready; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_qdma_m_axib_bid; // @[StaticU280Top.scala 92:26]
  wire [1:0] core_io_qdma_m_axib_bresp; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_bvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_bready; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_qdma_m_axib_arid; // @[StaticU280Top.scala 92:26]
  wire [63:0] core_io_qdma_m_axib_araddr; // @[StaticU280Top.scala 92:26]
  wire [7:0] core_io_qdma_m_axib_arlen; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_qdma_m_axib_arsize; // @[StaticU280Top.scala 92:26]
  wire [1:0] core_io_qdma_m_axib_arburst; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_qdma_m_axib_arprot; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_arlock; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_qdma_m_axib_arcache; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_arvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_arready; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_qdma_m_axib_rid; // @[StaticU280Top.scala 92:26]
  wire [511:0] core_io_qdma_m_axib_rdata; // @[StaticU280Top.scala 92:26]
  wire [1:0] core_io_qdma_m_axib_rresp; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_rlast; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_rvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axib_rready; // @[StaticU280Top.scala 92:26]
  wire [31:0] core_io_qdma_m_axil_awaddr; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axil_awvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axil_awready; // @[StaticU280Top.scala 92:26]
  wire [31:0] core_io_qdma_m_axil_wdata; // @[StaticU280Top.scala 92:26]
  wire [3:0] core_io_qdma_m_axil_wstrb; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axil_wvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axil_wready; // @[StaticU280Top.scala 92:26]
  wire [1:0] core_io_qdma_m_axil_bresp; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axil_bvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axil_bready; // @[StaticU280Top.scala 92:26]
  wire [31:0] core_io_qdma_m_axil_araddr; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axil_arvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axil_arready; // @[StaticU280Top.scala 92:26]
  wire [31:0] core_io_qdma_m_axil_rdata; // @[StaticU280Top.scala 92:26]
  wire [1:0] core_io_qdma_m_axil_rresp; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axil_rvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axil_rready; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_soft_reset_n; // @[StaticU280Top.scala 92:26]
  wire [63:0] core_io_qdma_h2c_byp_in_st_addr; // @[StaticU280Top.scala 92:26]
  wire [31:0] core_io_qdma_h2c_byp_in_st_len; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_h2c_byp_in_st_eop; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_h2c_byp_in_st_sop; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_h2c_byp_in_st_mrkr_req; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_h2c_byp_in_st_sdi; // @[StaticU280Top.scala 92:26]
  wire [10:0] core_io_qdma_h2c_byp_in_st_qid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_h2c_byp_in_st_error; // @[StaticU280Top.scala 92:26]
  wire [7:0] core_io_qdma_h2c_byp_in_st_func; // @[StaticU280Top.scala 92:26]
  wire [15:0] core_io_qdma_h2c_byp_in_st_cidx; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_qdma_h2c_byp_in_st_port_id; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_h2c_byp_in_st_no_dma; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_h2c_byp_in_st_vld; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_h2c_byp_in_st_rdy; // @[StaticU280Top.scala 92:26]
  wire [63:0] core_io_qdma_c2h_byp_in_st_csh_addr; // @[StaticU280Top.scala 92:26]
  wire [10:0] core_io_qdma_c2h_byp_in_st_csh_qid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_c2h_byp_in_st_csh_error; // @[StaticU280Top.scala 92:26]
  wire [7:0] core_io_qdma_c2h_byp_in_st_csh_func; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_qdma_c2h_byp_in_st_csh_port_id; // @[StaticU280Top.scala 92:26]
  wire [6:0] core_io_qdma_c2h_byp_in_st_csh_pfch_tag; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_c2h_byp_in_st_csh_vld; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_c2h_byp_in_st_csh_rdy; // @[StaticU280Top.scala 92:26]
  wire [511:0] core_io_qdma_s_axis_c2h_tdata; // @[StaticU280Top.scala 92:26]
  wire [31:0] core_io_qdma_s_axis_c2h_tcrc; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_s_axis_c2h_ctrl_marker; // @[StaticU280Top.scala 92:26]
  wire [6:0] core_io_qdma_s_axis_c2h_ctrl_ecc; // @[StaticU280Top.scala 92:26]
  wire [31:0] core_io_qdma_s_axis_c2h_ctrl_len; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_qdma_s_axis_c2h_ctrl_port_id; // @[StaticU280Top.scala 92:26]
  wire [10:0] core_io_qdma_s_axis_c2h_ctrl_qid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_s_axis_c2h_ctrl_has_cmpt; // @[StaticU280Top.scala 92:26]
  wire [5:0] core_io_qdma_s_axis_c2h_mty; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_s_axis_c2h_tlast; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_s_axis_c2h_tvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_s_axis_c2h_tready; // @[StaticU280Top.scala 92:26]
  wire [511:0] core_io_qdma_m_axis_h2c_tdata; // @[StaticU280Top.scala 92:26]
  wire [31:0] core_io_qdma_m_axis_h2c_tcrc; // @[StaticU280Top.scala 92:26]
  wire [10:0] core_io_qdma_m_axis_h2c_tuser_qid; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_qdma_m_axis_h2c_tuser_port_id; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axis_h2c_tuser_err; // @[StaticU280Top.scala 92:26]
  wire [31:0] core_io_qdma_m_axis_h2c_tuser_mdata; // @[StaticU280Top.scala 92:26]
  wire [5:0] core_io_qdma_m_axis_h2c_tuser_mty; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axis_h2c_tuser_zero_byte; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axis_h2c_tlast; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axis_h2c_tvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_m_axis_h2c_tready; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_axis_c2h_status_drop; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_axis_c2h_status_last; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_axis_c2h_status_cmp; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_axis_c2h_status_valid; // @[StaticU280Top.scala 92:26]
  wire [10:0] core_io_qdma_axis_c2h_status_qid; // @[StaticU280Top.scala 92:26]
  wire [511:0] core_io_qdma_s_axis_c2h_cmpt_tdata; // @[StaticU280Top.scala 92:26]
  wire [1:0] core_io_qdma_s_axis_c2h_cmpt_size; // @[StaticU280Top.scala 92:26]
  wire [15:0] core_io_qdma_s_axis_c2h_cmpt_dpar; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_s_axis_c2h_cmpt_tvalid; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_s_axis_c2h_cmpt_tready; // @[StaticU280Top.scala 92:26]
  wire [10:0] core_io_qdma_s_axis_c2h_cmpt_ctrl_qid; // @[StaticU280Top.scala 92:26]
  wire [1:0] core_io_qdma_s_axis_c2h_cmpt_ctrl_cmpt_type; // @[StaticU280Top.scala 92:26]
  wire [15:0] core_io_qdma_s_axis_c2h_cmpt_ctrl_wait_pld_pkt_id; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_s_axis_c2h_cmpt_ctrl_no_wrb_marker; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_qdma_s_axis_c2h_cmpt_ctrl_port_id; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_s_axis_c2h_cmpt_ctrl_marker; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_s_axis_c2h_cmpt_ctrl_user_trig; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_qdma_s_axis_c2h_cmpt_ctrl_col_idx; // @[StaticU280Top.scala 92:26]
  wire [2:0] core_io_qdma_s_axis_c2h_cmpt_ctrl_err_idx; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_h2c_byp_out_rdy; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_c2h_byp_out_rdy; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_tm_dsc_sts_rdy; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_dsc_crdt_in_vld; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_dsc_crdt_in_rdy; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_dsc_crdt_in_dir; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_dsc_crdt_in_fence; // @[StaticU280Top.scala 92:26]
  wire [10:0] core_io_qdma_dsc_crdt_in_qid; // @[StaticU280Top.scala 92:26]
  wire [15:0] core_io_qdma_dsc_crdt_in_crdt; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_qsts_out_rdy; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_usr_irq_in_vld; // @[StaticU280Top.scala 92:26]
  wire [10:0] core_io_qdma_usr_irq_in_vec; // @[StaticU280Top.scala 92:26]
  wire [7:0] core_io_qdma_usr_irq_in_fnc; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_usr_irq_out_ack; // @[StaticU280Top.scala 92:26]
  wire  core_io_qdma_usr_irq_out_fail; // @[StaticU280Top.scala 92:26]
  wire  core_S_BSCAN_drck; // @[StaticU280Top.scala 92:26]
  wire  core_S_BSCAN_shift; // @[StaticU280Top.scala 92:26]
  wire  core_S_BSCAN_tdi; // @[StaticU280Top.scala 92:26]
  wire  core_S_BSCAN_update; // @[StaticU280Top.scala 92:26]
  wire  core_S_BSCAN_sel; // @[StaticU280Top.scala 92:26]
  wire  core_S_BSCAN_tdo; // @[StaticU280Top.scala 92:26]
  wire  core_S_BSCAN_tms; // @[StaticU280Top.scala 92:26]
  wire  core_S_BSCAN_tck; // @[StaticU280Top.scala 92:26]
  wire  core_S_BSCAN_runtest; // @[StaticU280Top.scala 92:26]
  wire  core_S_BSCAN_reset; // @[StaticU280Top.scala 92:26]
  wire  core_S_BSCAN_capture; // @[StaticU280Top.scala 92:26]
  wire  core_S_BSCAN_bscanid_en; // @[StaticU280Top.scala 92:26]
  wire  ddrInst2_io_ddrpin_ddr0_sys_100M_p; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_ddrpin_ddr0_sys_100M_n; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_ddrpin_act_n; // @[StaticU280Top.scala 179:46]
  wire [16:0] ddrInst2_io_ddrpin_adr; // @[StaticU280Top.scala 179:46]
  wire [1:0] ddrInst2_io_ddrpin_ba; // @[StaticU280Top.scala 179:46]
  wire [1:0] ddrInst2_io_ddrpin_bg; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_ddrpin_cke; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_ddrpin_odt; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_ddrpin_cs_n; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_ddrpin_ck_t; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_ddrpin_ck_c; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_ddrpin_reset_n; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_ddrpin_parity; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_user_clk; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_user_rst; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_aw_ready; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_aw_valid; // @[StaticU280Top.scala 179:46]
  wire [33:0] ddrInst2_io_axi_aw_bits_addr; // @[StaticU280Top.scala 179:46]
  wire [1:0] ddrInst2_io_axi_aw_bits_burst; // @[StaticU280Top.scala 179:46]
  wire [3:0] ddrInst2_io_axi_aw_bits_cache; // @[StaticU280Top.scala 179:46]
  wire [3:0] ddrInst2_io_axi_aw_bits_id; // @[StaticU280Top.scala 179:46]
  wire [7:0] ddrInst2_io_axi_aw_bits_len; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_aw_bits_lock; // @[StaticU280Top.scala 179:46]
  wire [2:0] ddrInst2_io_axi_aw_bits_prot; // @[StaticU280Top.scala 179:46]
  wire [3:0] ddrInst2_io_axi_aw_bits_qos; // @[StaticU280Top.scala 179:46]
  wire [2:0] ddrInst2_io_axi_aw_bits_size; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_ar_ready; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_ar_valid; // @[StaticU280Top.scala 179:46]
  wire [33:0] ddrInst2_io_axi_ar_bits_addr; // @[StaticU280Top.scala 179:46]
  wire [1:0] ddrInst2_io_axi_ar_bits_burst; // @[StaticU280Top.scala 179:46]
  wire [3:0] ddrInst2_io_axi_ar_bits_cache; // @[StaticU280Top.scala 179:46]
  wire [3:0] ddrInst2_io_axi_ar_bits_id; // @[StaticU280Top.scala 179:46]
  wire [7:0] ddrInst2_io_axi_ar_bits_len; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_ar_bits_lock; // @[StaticU280Top.scala 179:46]
  wire [2:0] ddrInst2_io_axi_ar_bits_prot; // @[StaticU280Top.scala 179:46]
  wire [3:0] ddrInst2_io_axi_ar_bits_qos; // @[StaticU280Top.scala 179:46]
  wire [2:0] ddrInst2_io_axi_ar_bits_size; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_w_ready; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_w_valid; // @[StaticU280Top.scala 179:46]
  wire [511:0] ddrInst2_io_axi_w_bits_data; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_w_bits_last; // @[StaticU280Top.scala 179:46]
  wire [63:0] ddrInst2_io_axi_w_bits_strb; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_r_ready; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_r_valid; // @[StaticU280Top.scala 179:46]
  wire [511:0] ddrInst2_io_axi_r_bits_data; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_r_bits_last; // @[StaticU280Top.scala 179:46]
  wire [1:0] ddrInst2_io_axi_r_bits_resp; // @[StaticU280Top.scala 179:46]
  wire [3:0] ddrInst2_io_axi_r_bits_id; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_b_ready; // @[StaticU280Top.scala 179:46]
  wire  ddrInst2_io_axi_b_valid; // @[StaticU280Top.scala 179:46]
  wire [3:0] ddrInst2_io_axi_b_bits_id; // @[StaticU280Top.scala 179:46]
  wire [1:0] ddrInst2_io_axi_b_bits_resp; // @[StaticU280Top.scala 179:46]
  wire  userRstn = mmcmUsrClk_io_LOCKED; // @[StaticU280Top.scala 85:49]
  IBUFDS sysClk_pad ( // @[Buf.scala 51:34]
    .O(sysClk_pad_O),
    .I(sysClk_pad_I),
    .IB(sysClk_pad_IB)
  );
  BUFG sysClk_pad_1 ( // @[Buf.scala 33:34]
    .O(sysClk_pad_1_O),
    .I(sysClk_pad_1_I)
  );
  QDMABlackBox instQdma ( // @[StaticU280Top.scala 49:30]
    .sys_rst_n(instQdma_sys_rst_n),
    .sys_clk(instQdma_sys_clk),
    .sys_clk_gt(instQdma_sys_clk_gt),
    .pci_exp_txn(instQdma_pci_exp_txn),
    .pci_exp_txp(instQdma_pci_exp_txp),
    .pci_exp_rxn(instQdma_pci_exp_rxn),
    .pci_exp_rxp(instQdma_pci_exp_rxp),
    .m_axib_awid(instQdma_m_axib_awid),
    .m_axib_awaddr(instQdma_m_axib_awaddr),
    .m_axib_awlen(instQdma_m_axib_awlen),
    .m_axib_awsize(instQdma_m_axib_awsize),
    .m_axib_awburst(instQdma_m_axib_awburst),
    .m_axib_awprot(instQdma_m_axib_awprot),
    .m_axib_awlock(instQdma_m_axib_awlock),
    .m_axib_awcache(instQdma_m_axib_awcache),
    .m_axib_awvalid(instQdma_m_axib_awvalid),
    .m_axib_awready(instQdma_m_axib_awready),
    .m_axib_wdata(instQdma_m_axib_wdata),
    .m_axib_wstrb(instQdma_m_axib_wstrb),
    .m_axib_wlast(instQdma_m_axib_wlast),
    .m_axib_wvalid(instQdma_m_axib_wvalid),
    .m_axib_wready(instQdma_m_axib_wready),
    .m_axib_bid(instQdma_m_axib_bid),
    .m_axib_bresp(instQdma_m_axib_bresp),
    .m_axib_bvalid(instQdma_m_axib_bvalid),
    .m_axib_bready(instQdma_m_axib_bready),
    .m_axib_arid(instQdma_m_axib_arid),
    .m_axib_araddr(instQdma_m_axib_araddr),
    .m_axib_arlen(instQdma_m_axib_arlen),
    .m_axib_arsize(instQdma_m_axib_arsize),
    .m_axib_arburst(instQdma_m_axib_arburst),
    .m_axib_arprot(instQdma_m_axib_arprot),
    .m_axib_arlock(instQdma_m_axib_arlock),
    .m_axib_arcache(instQdma_m_axib_arcache),
    .m_axib_arvalid(instQdma_m_axib_arvalid),
    .m_axib_arready(instQdma_m_axib_arready),
    .m_axib_rid(instQdma_m_axib_rid),
    .m_axib_rdata(instQdma_m_axib_rdata),
    .m_axib_rresp(instQdma_m_axib_rresp),
    .m_axib_rlast(instQdma_m_axib_rlast),
    .m_axib_rvalid(instQdma_m_axib_rvalid),
    .m_axib_rready(instQdma_m_axib_rready),
    .m_axil_awaddr(instQdma_m_axil_awaddr),
    .m_axil_awvalid(instQdma_m_axil_awvalid),
    .m_axil_awready(instQdma_m_axil_awready),
    .m_axil_wdata(instQdma_m_axil_wdata),
    .m_axil_wstrb(instQdma_m_axil_wstrb),
    .m_axil_wvalid(instQdma_m_axil_wvalid),
    .m_axil_wready(instQdma_m_axil_wready),
    .m_axil_bresp(instQdma_m_axil_bresp),
    .m_axil_bvalid(instQdma_m_axil_bvalid),
    .m_axil_bready(instQdma_m_axil_bready),
    .m_axil_araddr(instQdma_m_axil_araddr),
    .m_axil_arvalid(instQdma_m_axil_arvalid),
    .m_axil_arready(instQdma_m_axil_arready),
    .m_axil_rdata(instQdma_m_axil_rdata),
    .m_axil_rresp(instQdma_m_axil_rresp),
    .m_axil_rvalid(instQdma_m_axil_rvalid),
    .m_axil_rready(instQdma_m_axil_rready),
    .axi_aclk(instQdma_axi_aclk),
    .axi_aresetn(instQdma_axi_aresetn),
    .soft_reset_n(instQdma_soft_reset_n),
    .h2c_byp_in_st_addr(instQdma_h2c_byp_in_st_addr),
    .h2c_byp_in_st_len(instQdma_h2c_byp_in_st_len),
    .h2c_byp_in_st_eop(instQdma_h2c_byp_in_st_eop),
    .h2c_byp_in_st_sop(instQdma_h2c_byp_in_st_sop),
    .h2c_byp_in_st_mrkr_req(instQdma_h2c_byp_in_st_mrkr_req),
    .h2c_byp_in_st_sdi(instQdma_h2c_byp_in_st_sdi),
    .h2c_byp_in_st_qid(instQdma_h2c_byp_in_st_qid),
    .h2c_byp_in_st_error(instQdma_h2c_byp_in_st_error),
    .h2c_byp_in_st_func(instQdma_h2c_byp_in_st_func),
    .h2c_byp_in_st_cidx(instQdma_h2c_byp_in_st_cidx),
    .h2c_byp_in_st_port_id(instQdma_h2c_byp_in_st_port_id),
    .h2c_byp_in_st_no_dma(instQdma_h2c_byp_in_st_no_dma),
    .h2c_byp_in_st_vld(instQdma_h2c_byp_in_st_vld),
    .h2c_byp_in_st_rdy(instQdma_h2c_byp_in_st_rdy),
    .c2h_byp_in_st_csh_addr(instQdma_c2h_byp_in_st_csh_addr),
    .c2h_byp_in_st_csh_qid(instQdma_c2h_byp_in_st_csh_qid),
    .c2h_byp_in_st_csh_error(instQdma_c2h_byp_in_st_csh_error),
    .c2h_byp_in_st_csh_func(instQdma_c2h_byp_in_st_csh_func),
    .c2h_byp_in_st_csh_port_id(instQdma_c2h_byp_in_st_csh_port_id),
    .c2h_byp_in_st_csh_pfch_tag(instQdma_c2h_byp_in_st_csh_pfch_tag),
    .c2h_byp_in_st_csh_vld(instQdma_c2h_byp_in_st_csh_vld),
    .c2h_byp_in_st_csh_rdy(instQdma_c2h_byp_in_st_csh_rdy),
    .s_axis_c2h_tdata(instQdma_s_axis_c2h_tdata),
    .s_axis_c2h_tcrc(instQdma_s_axis_c2h_tcrc),
    .s_axis_c2h_ctrl_marker(instQdma_s_axis_c2h_ctrl_marker),
    .s_axis_c2h_ctrl_ecc(instQdma_s_axis_c2h_ctrl_ecc),
    .s_axis_c2h_ctrl_len(instQdma_s_axis_c2h_ctrl_len),
    .s_axis_c2h_ctrl_port_id(instQdma_s_axis_c2h_ctrl_port_id),
    .s_axis_c2h_ctrl_qid(instQdma_s_axis_c2h_ctrl_qid),
    .s_axis_c2h_ctrl_has_cmpt(instQdma_s_axis_c2h_ctrl_has_cmpt),
    .s_axis_c2h_mty(instQdma_s_axis_c2h_mty),
    .s_axis_c2h_tlast(instQdma_s_axis_c2h_tlast),
    .s_axis_c2h_tvalid(instQdma_s_axis_c2h_tvalid),
    .s_axis_c2h_tready(instQdma_s_axis_c2h_tready),
    .m_axis_h2c_tdata(instQdma_m_axis_h2c_tdata),
    .m_axis_h2c_tcrc(instQdma_m_axis_h2c_tcrc),
    .m_axis_h2c_tuser_qid(instQdma_m_axis_h2c_tuser_qid),
    .m_axis_h2c_tuser_port_id(instQdma_m_axis_h2c_tuser_port_id),
    .m_axis_h2c_tuser_err(instQdma_m_axis_h2c_tuser_err),
    .m_axis_h2c_tuser_mdata(instQdma_m_axis_h2c_tuser_mdata),
    .m_axis_h2c_tuser_mty(instQdma_m_axis_h2c_tuser_mty),
    .m_axis_h2c_tuser_zero_byte(instQdma_m_axis_h2c_tuser_zero_byte),
    .m_axis_h2c_tlast(instQdma_m_axis_h2c_tlast),
    .m_axis_h2c_tvalid(instQdma_m_axis_h2c_tvalid),
    .m_axis_h2c_tready(instQdma_m_axis_h2c_tready),
    .axis_c2h_status_drop(instQdma_axis_c2h_status_drop),
    .axis_c2h_status_last(instQdma_axis_c2h_status_last),
    .axis_c2h_status_cmp(instQdma_axis_c2h_status_cmp),
    .axis_c2h_status_valid(instQdma_axis_c2h_status_valid),
    .axis_c2h_status_qid(instQdma_axis_c2h_status_qid),
    .s_axis_c2h_cmpt_tdata(instQdma_s_axis_c2h_cmpt_tdata),
    .s_axis_c2h_cmpt_size(instQdma_s_axis_c2h_cmpt_size),
    .s_axis_c2h_cmpt_dpar(instQdma_s_axis_c2h_cmpt_dpar),
    .s_axis_c2h_cmpt_tvalid(instQdma_s_axis_c2h_cmpt_tvalid),
    .s_axis_c2h_cmpt_tready(instQdma_s_axis_c2h_cmpt_tready),
    .s_axis_c2h_cmpt_ctrl_qid(instQdma_s_axis_c2h_cmpt_ctrl_qid),
    .s_axis_c2h_cmpt_ctrl_cmpt_type(instQdma_s_axis_c2h_cmpt_ctrl_cmpt_type),
    .s_axis_c2h_cmpt_ctrl_wait_pld_pkt_id(instQdma_s_axis_c2h_cmpt_ctrl_wait_pld_pkt_id),
    .s_axis_c2h_cmpt_ctrl_no_wrb_marker(instQdma_s_axis_c2h_cmpt_ctrl_no_wrb_marker),
    .s_axis_c2h_cmpt_ctrl_port_id(instQdma_s_axis_c2h_cmpt_ctrl_port_id),
    .s_axis_c2h_cmpt_ctrl_marker(instQdma_s_axis_c2h_cmpt_ctrl_marker),
    .s_axis_c2h_cmpt_ctrl_user_trig(instQdma_s_axis_c2h_cmpt_ctrl_user_trig),
    .s_axis_c2h_cmpt_ctrl_col_idx(instQdma_s_axis_c2h_cmpt_ctrl_col_idx),
    .s_axis_c2h_cmpt_ctrl_err_idx(instQdma_s_axis_c2h_cmpt_ctrl_err_idx),
    .h2c_byp_out_rdy(instQdma_h2c_byp_out_rdy),
    .c2h_byp_out_rdy(instQdma_c2h_byp_out_rdy),
    .tm_dsc_sts_rdy(instQdma_tm_dsc_sts_rdy),
    .dsc_crdt_in_vld(instQdma_dsc_crdt_in_vld),
    .dsc_crdt_in_rdy(instQdma_dsc_crdt_in_rdy),
    .dsc_crdt_in_dir(instQdma_dsc_crdt_in_dir),
    .dsc_crdt_in_fence(instQdma_dsc_crdt_in_fence),
    .dsc_crdt_in_qid(instQdma_dsc_crdt_in_qid),
    .dsc_crdt_in_crdt(instQdma_dsc_crdt_in_crdt),
    .qsts_out_rdy(instQdma_qsts_out_rdy),
    .usr_irq_in_vld(instQdma_usr_irq_in_vld),
    .usr_irq_in_vec(instQdma_usr_irq_in_vec),
    .usr_irq_in_fnc(instQdma_usr_irq_in_fnc),
    .usr_irq_out_ack(instQdma_usr_irq_out_ack),
    .usr_irq_out_fail(instQdma_usr_irq_out_fail)
  );
  IBUFDS_GTE4 #(.REFCLK_EN_TX_PATH(0), .REFCLK_HROW_CK_SEL(0), .REFCLK_ICNTL_RX(0)) ibufds_gte4_inst ( // @[StaticU280Top.scala 56:38]
    .O(ibufds_gte4_inst_O),
    .ODIV2(ibufds_gte4_inst_ODIV2),
    .CEB(ibufds_gte4_inst_CEB),
    .I(ibufds_gte4_inst_I),
    .IB(ibufds_gte4_inst_IB)
  );
  IBUF instQdma_io_sys_rst_n_pad ( // @[Buf.scala 17:34]
    .O(instQdma_io_sys_rst_n_pad_O),
    .I(instQdma_io_sys_rst_n_pad_I)
  );
  MMCME4_ADV_Wrapper mmcmUsrClk ( // @[StaticU280Top.scala 72:33]
    .io_CLKIN1(mmcmUsrClk_io_CLKIN1),
    .io_LOCKED(mmcmUsrClk_io_LOCKED),
    .io_CLKOUT0(mmcmUsrClk_io_CLKOUT0),
    .io_CLKOUT1(mmcmUsrClk_io_CLKOUT1),
    .io_CLKOUT2(mmcmUsrClk_io_CLKOUT2),
    .io_CLKOUT3(mmcmUsrClk_io_CLKOUT3)
  );
  AlveoDynamicTop core ( // @[StaticU280Top.scala 92:26]
    .clock(core_clock),
    .reset(core_reset),
    .io_sysClk(core_io_sysClk),
    .io_cmacClk(core_io_cmacClk),
    .io_serClk(core_io_serClk),
    .io_cmacPin_tx_p(core_io_cmacPin_tx_p),
    .io_cmacPin_tx_n(core_io_cmacPin_tx_n),
    .io_cmacPin_rx_p(core_io_cmacPin_rx_p),
    .io_cmacPin_rx_n(core_io_cmacPin_rx_n),
    .io_cmacPin_gt_clk_p(core_io_cmacPin_gt_clk_p),
    .io_cmacPin_gt_clk_n(core_io_cmacPin_gt_clk_n),
    .io_cmacPin2_tx_p(core_io_cmacPin2_tx_p),
    .io_cmacPin2_tx_n(core_io_cmacPin2_tx_n),
    .io_cmacPin2_rx_p(core_io_cmacPin2_rx_p),
    .io_cmacPin2_rx_n(core_io_cmacPin2_rx_n),
    .io_cmacPin2_gt_clk_p(core_io_cmacPin2_gt_clk_p),
    .io_cmacPin2_gt_clk_n(core_io_cmacPin2_gt_clk_n),
    .io_ddrPort2_clk(core_io_ddrPort2_clk),
    .io_ddrPort2_rst(core_io_ddrPort2_rst),
    .io_ddrPort2_axi_aw_ready(core_io_ddrPort2_axi_aw_ready),
    .io_ddrPort2_axi_aw_valid(core_io_ddrPort2_axi_aw_valid),
    .io_ddrPort2_axi_aw_bits_addr(core_io_ddrPort2_axi_aw_bits_addr),
    .io_ddrPort2_axi_aw_bits_burst(core_io_ddrPort2_axi_aw_bits_burst),
    .io_ddrPort2_axi_aw_bits_cache(core_io_ddrPort2_axi_aw_bits_cache),
    .io_ddrPort2_axi_aw_bits_id(core_io_ddrPort2_axi_aw_bits_id),
    .io_ddrPort2_axi_aw_bits_len(core_io_ddrPort2_axi_aw_bits_len),
    .io_ddrPort2_axi_aw_bits_lock(core_io_ddrPort2_axi_aw_bits_lock),
    .io_ddrPort2_axi_aw_bits_prot(core_io_ddrPort2_axi_aw_bits_prot),
    .io_ddrPort2_axi_aw_bits_qos(core_io_ddrPort2_axi_aw_bits_qos),
    .io_ddrPort2_axi_aw_bits_region(core_io_ddrPort2_axi_aw_bits_region),
    .io_ddrPort2_axi_aw_bits_size(core_io_ddrPort2_axi_aw_bits_size),
    .io_ddrPort2_axi_ar_ready(core_io_ddrPort2_axi_ar_ready),
    .io_ddrPort2_axi_ar_valid(core_io_ddrPort2_axi_ar_valid),
    .io_ddrPort2_axi_ar_bits_addr(core_io_ddrPort2_axi_ar_bits_addr),
    .io_ddrPort2_axi_ar_bits_burst(core_io_ddrPort2_axi_ar_bits_burst),
    .io_ddrPort2_axi_ar_bits_cache(core_io_ddrPort2_axi_ar_bits_cache),
    .io_ddrPort2_axi_ar_bits_id(core_io_ddrPort2_axi_ar_bits_id),
    .io_ddrPort2_axi_ar_bits_len(core_io_ddrPort2_axi_ar_bits_len),
    .io_ddrPort2_axi_ar_bits_lock(core_io_ddrPort2_axi_ar_bits_lock),
    .io_ddrPort2_axi_ar_bits_prot(core_io_ddrPort2_axi_ar_bits_prot),
    .io_ddrPort2_axi_ar_bits_qos(core_io_ddrPort2_axi_ar_bits_qos),
    .io_ddrPort2_axi_ar_bits_region(core_io_ddrPort2_axi_ar_bits_region),
    .io_ddrPort2_axi_ar_bits_size(core_io_ddrPort2_axi_ar_bits_size),
    .io_ddrPort2_axi_w_ready(core_io_ddrPort2_axi_w_ready),
    .io_ddrPort2_axi_w_valid(core_io_ddrPort2_axi_w_valid),
    .io_ddrPort2_axi_w_bits_data(core_io_ddrPort2_axi_w_bits_data),
    .io_ddrPort2_axi_w_bits_last(core_io_ddrPort2_axi_w_bits_last),
    .io_ddrPort2_axi_w_bits_strb(core_io_ddrPort2_axi_w_bits_strb),
    .io_ddrPort2_axi_r_ready(core_io_ddrPort2_axi_r_ready),
    .io_ddrPort2_axi_r_valid(core_io_ddrPort2_axi_r_valid),
    .io_ddrPort2_axi_r_bits_data(core_io_ddrPort2_axi_r_bits_data),
    .io_ddrPort2_axi_r_bits_last(core_io_ddrPort2_axi_r_bits_last),
    .io_ddrPort2_axi_r_bits_resp(core_io_ddrPort2_axi_r_bits_resp),
    .io_ddrPort2_axi_r_bits_id(core_io_ddrPort2_axi_r_bits_id),
    .io_ddrPort2_axi_b_ready(core_io_ddrPort2_axi_b_ready),
    .io_ddrPort2_axi_b_valid(core_io_ddrPort2_axi_b_valid),
    .io_ddrPort2_axi_b_bits_id(core_io_ddrPort2_axi_b_bits_id),
    .io_ddrPort2_axi_b_bits_resp(core_io_ddrPort2_axi_b_bits_resp),
    .io_qdma_axi_aclk(core_io_qdma_axi_aclk),
    .io_qdma_axi_aresetn(core_io_qdma_axi_aresetn),
    .io_qdma_m_axib_awid(core_io_qdma_m_axib_awid),
    .io_qdma_m_axib_awaddr(core_io_qdma_m_axib_awaddr),
    .io_qdma_m_axib_awlen(core_io_qdma_m_axib_awlen),
    .io_qdma_m_axib_awsize(core_io_qdma_m_axib_awsize),
    .io_qdma_m_axib_awburst(core_io_qdma_m_axib_awburst),
    .io_qdma_m_axib_awprot(core_io_qdma_m_axib_awprot),
    .io_qdma_m_axib_awlock(core_io_qdma_m_axib_awlock),
    .io_qdma_m_axib_awcache(core_io_qdma_m_axib_awcache),
    .io_qdma_m_axib_awvalid(core_io_qdma_m_axib_awvalid),
    .io_qdma_m_axib_awready(core_io_qdma_m_axib_awready),
    .io_qdma_m_axib_wdata(core_io_qdma_m_axib_wdata),
    .io_qdma_m_axib_wstrb(core_io_qdma_m_axib_wstrb),
    .io_qdma_m_axib_wlast(core_io_qdma_m_axib_wlast),
    .io_qdma_m_axib_wvalid(core_io_qdma_m_axib_wvalid),
    .io_qdma_m_axib_wready(core_io_qdma_m_axib_wready),
    .io_qdma_m_axib_bid(core_io_qdma_m_axib_bid),
    .io_qdma_m_axib_bresp(core_io_qdma_m_axib_bresp),
    .io_qdma_m_axib_bvalid(core_io_qdma_m_axib_bvalid),
    .io_qdma_m_axib_bready(core_io_qdma_m_axib_bready),
    .io_qdma_m_axib_arid(core_io_qdma_m_axib_arid),
    .io_qdma_m_axib_araddr(core_io_qdma_m_axib_araddr),
    .io_qdma_m_axib_arlen(core_io_qdma_m_axib_arlen),
    .io_qdma_m_axib_arsize(core_io_qdma_m_axib_arsize),
    .io_qdma_m_axib_arburst(core_io_qdma_m_axib_arburst),
    .io_qdma_m_axib_arprot(core_io_qdma_m_axib_arprot),
    .io_qdma_m_axib_arlock(core_io_qdma_m_axib_arlock),
    .io_qdma_m_axib_arcache(core_io_qdma_m_axib_arcache),
    .io_qdma_m_axib_arvalid(core_io_qdma_m_axib_arvalid),
    .io_qdma_m_axib_arready(core_io_qdma_m_axib_arready),
    .io_qdma_m_axib_rid(core_io_qdma_m_axib_rid),
    .io_qdma_m_axib_rdata(core_io_qdma_m_axib_rdata),
    .io_qdma_m_axib_rresp(core_io_qdma_m_axib_rresp),
    .io_qdma_m_axib_rlast(core_io_qdma_m_axib_rlast),
    .io_qdma_m_axib_rvalid(core_io_qdma_m_axib_rvalid),
    .io_qdma_m_axib_rready(core_io_qdma_m_axib_rready),
    .io_qdma_m_axil_awaddr(core_io_qdma_m_axil_awaddr),
    .io_qdma_m_axil_awvalid(core_io_qdma_m_axil_awvalid),
    .io_qdma_m_axil_awready(core_io_qdma_m_axil_awready),
    .io_qdma_m_axil_wdata(core_io_qdma_m_axil_wdata),
    .io_qdma_m_axil_wstrb(core_io_qdma_m_axil_wstrb),
    .io_qdma_m_axil_wvalid(core_io_qdma_m_axil_wvalid),
    .io_qdma_m_axil_wready(core_io_qdma_m_axil_wready),
    .io_qdma_m_axil_bresp(core_io_qdma_m_axil_bresp),
    .io_qdma_m_axil_bvalid(core_io_qdma_m_axil_bvalid),
    .io_qdma_m_axil_bready(core_io_qdma_m_axil_bready),
    .io_qdma_m_axil_araddr(core_io_qdma_m_axil_araddr),
    .io_qdma_m_axil_arvalid(core_io_qdma_m_axil_arvalid),
    .io_qdma_m_axil_arready(core_io_qdma_m_axil_arready),
    .io_qdma_m_axil_rdata(core_io_qdma_m_axil_rdata),
    .io_qdma_m_axil_rresp(core_io_qdma_m_axil_rresp),
    .io_qdma_m_axil_rvalid(core_io_qdma_m_axil_rvalid),
    .io_qdma_m_axil_rready(core_io_qdma_m_axil_rready),
    .io_qdma_soft_reset_n(core_io_qdma_soft_reset_n),
    .io_qdma_h2c_byp_in_st_addr(core_io_qdma_h2c_byp_in_st_addr),
    .io_qdma_h2c_byp_in_st_len(core_io_qdma_h2c_byp_in_st_len),
    .io_qdma_h2c_byp_in_st_eop(core_io_qdma_h2c_byp_in_st_eop),
    .io_qdma_h2c_byp_in_st_sop(core_io_qdma_h2c_byp_in_st_sop),
    .io_qdma_h2c_byp_in_st_mrkr_req(core_io_qdma_h2c_byp_in_st_mrkr_req),
    .io_qdma_h2c_byp_in_st_sdi(core_io_qdma_h2c_byp_in_st_sdi),
    .io_qdma_h2c_byp_in_st_qid(core_io_qdma_h2c_byp_in_st_qid),
    .io_qdma_h2c_byp_in_st_error(core_io_qdma_h2c_byp_in_st_error),
    .io_qdma_h2c_byp_in_st_func(core_io_qdma_h2c_byp_in_st_func),
    .io_qdma_h2c_byp_in_st_cidx(core_io_qdma_h2c_byp_in_st_cidx),
    .io_qdma_h2c_byp_in_st_port_id(core_io_qdma_h2c_byp_in_st_port_id),
    .io_qdma_h2c_byp_in_st_no_dma(core_io_qdma_h2c_byp_in_st_no_dma),
    .io_qdma_h2c_byp_in_st_vld(core_io_qdma_h2c_byp_in_st_vld),
    .io_qdma_h2c_byp_in_st_rdy(core_io_qdma_h2c_byp_in_st_rdy),
    .io_qdma_c2h_byp_in_st_csh_addr(core_io_qdma_c2h_byp_in_st_csh_addr),
    .io_qdma_c2h_byp_in_st_csh_qid(core_io_qdma_c2h_byp_in_st_csh_qid),
    .io_qdma_c2h_byp_in_st_csh_error(core_io_qdma_c2h_byp_in_st_csh_error),
    .io_qdma_c2h_byp_in_st_csh_func(core_io_qdma_c2h_byp_in_st_csh_func),
    .io_qdma_c2h_byp_in_st_csh_port_id(core_io_qdma_c2h_byp_in_st_csh_port_id),
    .io_qdma_c2h_byp_in_st_csh_pfch_tag(core_io_qdma_c2h_byp_in_st_csh_pfch_tag),
    .io_qdma_c2h_byp_in_st_csh_vld(core_io_qdma_c2h_byp_in_st_csh_vld),
    .io_qdma_c2h_byp_in_st_csh_rdy(core_io_qdma_c2h_byp_in_st_csh_rdy),
    .io_qdma_s_axis_c2h_tdata(core_io_qdma_s_axis_c2h_tdata),
    .io_qdma_s_axis_c2h_tcrc(core_io_qdma_s_axis_c2h_tcrc),
    .io_qdma_s_axis_c2h_ctrl_marker(core_io_qdma_s_axis_c2h_ctrl_marker),
    .io_qdma_s_axis_c2h_ctrl_ecc(core_io_qdma_s_axis_c2h_ctrl_ecc),
    .io_qdma_s_axis_c2h_ctrl_len(core_io_qdma_s_axis_c2h_ctrl_len),
    .io_qdma_s_axis_c2h_ctrl_port_id(core_io_qdma_s_axis_c2h_ctrl_port_id),
    .io_qdma_s_axis_c2h_ctrl_qid(core_io_qdma_s_axis_c2h_ctrl_qid),
    .io_qdma_s_axis_c2h_ctrl_has_cmpt(core_io_qdma_s_axis_c2h_ctrl_has_cmpt),
    .io_qdma_s_axis_c2h_mty(core_io_qdma_s_axis_c2h_mty),
    .io_qdma_s_axis_c2h_tlast(core_io_qdma_s_axis_c2h_tlast),
    .io_qdma_s_axis_c2h_tvalid(core_io_qdma_s_axis_c2h_tvalid),
    .io_qdma_s_axis_c2h_tready(core_io_qdma_s_axis_c2h_tready),
    .io_qdma_m_axis_h2c_tdata(core_io_qdma_m_axis_h2c_tdata),
    .io_qdma_m_axis_h2c_tcrc(core_io_qdma_m_axis_h2c_tcrc),
    .io_qdma_m_axis_h2c_tuser_qid(core_io_qdma_m_axis_h2c_tuser_qid),
    .io_qdma_m_axis_h2c_tuser_port_id(core_io_qdma_m_axis_h2c_tuser_port_id),
    .io_qdma_m_axis_h2c_tuser_err(core_io_qdma_m_axis_h2c_tuser_err),
    .io_qdma_m_axis_h2c_tuser_mdata(core_io_qdma_m_axis_h2c_tuser_mdata),
    .io_qdma_m_axis_h2c_tuser_mty(core_io_qdma_m_axis_h2c_tuser_mty),
    .io_qdma_m_axis_h2c_tuser_zero_byte(core_io_qdma_m_axis_h2c_tuser_zero_byte),
    .io_qdma_m_axis_h2c_tlast(core_io_qdma_m_axis_h2c_tlast),
    .io_qdma_m_axis_h2c_tvalid(core_io_qdma_m_axis_h2c_tvalid),
    .io_qdma_m_axis_h2c_tready(core_io_qdma_m_axis_h2c_tready),
    .io_qdma_axis_c2h_status_drop(core_io_qdma_axis_c2h_status_drop),
    .io_qdma_axis_c2h_status_last(core_io_qdma_axis_c2h_status_last),
    .io_qdma_axis_c2h_status_cmp(core_io_qdma_axis_c2h_status_cmp),
    .io_qdma_axis_c2h_status_valid(core_io_qdma_axis_c2h_status_valid),
    .io_qdma_axis_c2h_status_qid(core_io_qdma_axis_c2h_status_qid),
    .io_qdma_s_axis_c2h_cmpt_tdata(core_io_qdma_s_axis_c2h_cmpt_tdata),
    .io_qdma_s_axis_c2h_cmpt_size(core_io_qdma_s_axis_c2h_cmpt_size),
    .io_qdma_s_axis_c2h_cmpt_dpar(core_io_qdma_s_axis_c2h_cmpt_dpar),
    .io_qdma_s_axis_c2h_cmpt_tvalid(core_io_qdma_s_axis_c2h_cmpt_tvalid),
    .io_qdma_s_axis_c2h_cmpt_tready(core_io_qdma_s_axis_c2h_cmpt_tready),
    .io_qdma_s_axis_c2h_cmpt_ctrl_qid(core_io_qdma_s_axis_c2h_cmpt_ctrl_qid),
    .io_qdma_s_axis_c2h_cmpt_ctrl_cmpt_type(core_io_qdma_s_axis_c2h_cmpt_ctrl_cmpt_type),
    .io_qdma_s_axis_c2h_cmpt_ctrl_wait_pld_pkt_id(core_io_qdma_s_axis_c2h_cmpt_ctrl_wait_pld_pkt_id),
    .io_qdma_s_axis_c2h_cmpt_ctrl_no_wrb_marker(core_io_qdma_s_axis_c2h_cmpt_ctrl_no_wrb_marker),
    .io_qdma_s_axis_c2h_cmpt_ctrl_port_id(core_io_qdma_s_axis_c2h_cmpt_ctrl_port_id),
    .io_qdma_s_axis_c2h_cmpt_ctrl_marker(core_io_qdma_s_axis_c2h_cmpt_ctrl_marker),
    .io_qdma_s_axis_c2h_cmpt_ctrl_user_trig(core_io_qdma_s_axis_c2h_cmpt_ctrl_user_trig),
    .io_qdma_s_axis_c2h_cmpt_ctrl_col_idx(core_io_qdma_s_axis_c2h_cmpt_ctrl_col_idx),
    .io_qdma_s_axis_c2h_cmpt_ctrl_err_idx(core_io_qdma_s_axis_c2h_cmpt_ctrl_err_idx),
    .io_qdma_h2c_byp_out_rdy(core_io_qdma_h2c_byp_out_rdy),
    .io_qdma_c2h_byp_out_rdy(core_io_qdma_c2h_byp_out_rdy),
    .io_qdma_tm_dsc_sts_rdy(core_io_qdma_tm_dsc_sts_rdy),
    .io_qdma_dsc_crdt_in_vld(core_io_qdma_dsc_crdt_in_vld),
    .io_qdma_dsc_crdt_in_rdy(core_io_qdma_dsc_crdt_in_rdy),
    .io_qdma_dsc_crdt_in_dir(core_io_qdma_dsc_crdt_in_dir),
    .io_qdma_dsc_crdt_in_fence(core_io_qdma_dsc_crdt_in_fence),
    .io_qdma_dsc_crdt_in_qid(core_io_qdma_dsc_crdt_in_qid),
    .io_qdma_dsc_crdt_in_crdt(core_io_qdma_dsc_crdt_in_crdt),
    .io_qdma_qsts_out_rdy(core_io_qdma_qsts_out_rdy),
    .io_qdma_usr_irq_in_vld(core_io_qdma_usr_irq_in_vld),
    .io_qdma_usr_irq_in_vec(core_io_qdma_usr_irq_in_vec),
    .io_qdma_usr_irq_in_fnc(core_io_qdma_usr_irq_in_fnc),
    .io_qdma_usr_irq_out_ack(core_io_qdma_usr_irq_out_ack),
    .io_qdma_usr_irq_out_fail(core_io_qdma_usr_irq_out_fail),
    .S_BSCAN_drck(core_S_BSCAN_drck),
    .S_BSCAN_shift(core_S_BSCAN_shift),
    .S_BSCAN_tdi(core_S_BSCAN_tdi),
    .S_BSCAN_update(core_S_BSCAN_update),
    .S_BSCAN_sel(core_S_BSCAN_sel),
    .S_BSCAN_tdo(core_S_BSCAN_tdo),
    .S_BSCAN_tms(core_S_BSCAN_tms),
    .S_BSCAN_tck(core_S_BSCAN_tck),
    .S_BSCAN_runtest(core_S_BSCAN_runtest),
    .S_BSCAN_reset(core_S_BSCAN_reset),
    .S_BSCAN_capture(core_S_BSCAN_capture),
    .S_BSCAN_bscanid_en(core_S_BSCAN_bscanid_en)
  );
  DDR_DRIVER ddrInst2 ( // @[StaticU280Top.scala 179:46]
    .io_ddrpin_ddr0_sys_100M_p(ddrInst2_io_ddrpin_ddr0_sys_100M_p),
    .io_ddrpin_ddr0_sys_100M_n(ddrInst2_io_ddrpin_ddr0_sys_100M_n),
    .io_ddrpin_act_n(ddrInst2_io_ddrpin_act_n),
    .io_ddrpin_adr(ddrInst2_io_ddrpin_adr),
    .io_ddrpin_ba(ddrInst2_io_ddrpin_ba),
    .io_ddrpin_bg(ddrInst2_io_ddrpin_bg),
    .io_ddrpin_cke(ddrInst2_io_ddrpin_cke),
    .io_ddrpin_odt(ddrInst2_io_ddrpin_odt),
    .io_ddrpin_cs_n(ddrInst2_io_ddrpin_cs_n),
    .io_ddrpin_ck_t(ddrInst2_io_ddrpin_ck_t),
    .io_ddrpin_ck_c(ddrInst2_io_ddrpin_ck_c),
    .io_ddrpin_reset_n(ddrInst2_io_ddrpin_reset_n),
    .io_ddrpin_parity(ddrInst2_io_ddrpin_parity),
    .io_ddrpin_dq(ddrPin2_dq),
    .io_ddrpin_dqs_t(ddrPin2_dqs_t),
    .io_ddrpin_dqs_c(ddrPin2_dqs_c),
    .io_user_clk(ddrInst2_io_user_clk),
    .io_user_rst(ddrInst2_io_user_rst),
    .io_axi_aw_ready(ddrInst2_io_axi_aw_ready),
    .io_axi_aw_valid(ddrInst2_io_axi_aw_valid),
    .io_axi_aw_bits_addr(ddrInst2_io_axi_aw_bits_addr),
    .io_axi_aw_bits_burst(ddrInst2_io_axi_aw_bits_burst),
    .io_axi_aw_bits_cache(ddrInst2_io_axi_aw_bits_cache),
    .io_axi_aw_bits_id(ddrInst2_io_axi_aw_bits_id),
    .io_axi_aw_bits_len(ddrInst2_io_axi_aw_bits_len),
    .io_axi_aw_bits_lock(ddrInst2_io_axi_aw_bits_lock),
    .io_axi_aw_bits_prot(ddrInst2_io_axi_aw_bits_prot),
    .io_axi_aw_bits_qos(ddrInst2_io_axi_aw_bits_qos),
    .io_axi_aw_bits_size(ddrInst2_io_axi_aw_bits_size),
    .io_axi_ar_ready(ddrInst2_io_axi_ar_ready),
    .io_axi_ar_valid(ddrInst2_io_axi_ar_valid),
    .io_axi_ar_bits_addr(ddrInst2_io_axi_ar_bits_addr),
    .io_axi_ar_bits_burst(ddrInst2_io_axi_ar_bits_burst),
    .io_axi_ar_bits_cache(ddrInst2_io_axi_ar_bits_cache),
    .io_axi_ar_bits_id(ddrInst2_io_axi_ar_bits_id),
    .io_axi_ar_bits_len(ddrInst2_io_axi_ar_bits_len),
    .io_axi_ar_bits_lock(ddrInst2_io_axi_ar_bits_lock),
    .io_axi_ar_bits_prot(ddrInst2_io_axi_ar_bits_prot),
    .io_axi_ar_bits_qos(ddrInst2_io_axi_ar_bits_qos),
    .io_axi_ar_bits_size(ddrInst2_io_axi_ar_bits_size),
    .io_axi_w_ready(ddrInst2_io_axi_w_ready),
    .io_axi_w_valid(ddrInst2_io_axi_w_valid),
    .io_axi_w_bits_data(ddrInst2_io_axi_w_bits_data),
    .io_axi_w_bits_last(ddrInst2_io_axi_w_bits_last),
    .io_axi_w_bits_strb(ddrInst2_io_axi_w_bits_strb),
    .io_axi_r_ready(ddrInst2_io_axi_r_ready),
    .io_axi_r_valid(ddrInst2_io_axi_r_valid),
    .io_axi_r_bits_data(ddrInst2_io_axi_r_bits_data),
    .io_axi_r_bits_last(ddrInst2_io_axi_r_bits_last),
    .io_axi_r_bits_resp(ddrInst2_io_axi_r_bits_resp),
    .io_axi_r_bits_id(ddrInst2_io_axi_r_bits_id),
    .io_axi_b_ready(ddrInst2_io_axi_b_ready),
    .io_axi_b_valid(ddrInst2_io_axi_b_valid),
    .io_axi_b_bits_id(ddrInst2_io_axi_b_bits_id),
    .io_axi_b_bits_resp(ddrInst2_io_axi_b_bits_resp)
  );
  assign qdmaPin_tx_p = instQdma_pci_exp_txp[7:0]; // @[StaticU280Top.scala 68:33]
  assign qdmaPin_tx_n = instQdma_pci_exp_txn[7:0]; // @[StaticU280Top.scala 67:33]
  assign cmacPin_tx_p = core_io_cmacPin_tx_p; // @[StaticU280Top.scala 108:73]
  assign cmacPin_tx_n = core_io_cmacPin_tx_n; // @[StaticU280Top.scala 109:73]
  assign cmacPin2_tx_p = core_io_cmacPin2_tx_p; // @[StaticU280Top.scala 117:65]
  assign cmacPin2_tx_n = core_io_cmacPin2_tx_n; // @[StaticU280Top.scala 118:65]
  assign ddrPin2_act_n = ddrInst2_io_ddrpin_act_n; // @[StaticU280Top.scala 182:49]
  assign ddrPin2_adr = ddrInst2_io_ddrpin_adr; // @[StaticU280Top.scala 182:49]
  assign ddrPin2_ba = ddrInst2_io_ddrpin_ba; // @[StaticU280Top.scala 182:49]
  assign ddrPin2_bg = ddrInst2_io_ddrpin_bg; // @[StaticU280Top.scala 182:49]
  assign ddrPin2_cke = ddrInst2_io_ddrpin_cke; // @[StaticU280Top.scala 182:49]
  assign ddrPin2_odt = ddrInst2_io_ddrpin_odt; // @[StaticU280Top.scala 182:49]
  assign ddrPin2_cs_n = ddrInst2_io_ddrpin_cs_n; // @[StaticU280Top.scala 182:49]
  assign ddrPin2_ck_t = ddrInst2_io_ddrpin_ck_t; // @[StaticU280Top.scala 182:49]
  assign ddrPin2_ck_c = ddrInst2_io_ddrpin_ck_c; // @[StaticU280Top.scala 182:49]
  assign ddrPin2_reset_n = ddrInst2_io_ddrpin_reset_n; // @[StaticU280Top.scala 182:49]
  assign ddrPin2_parity = ddrInst2_io_ddrpin_parity; // @[StaticU280Top.scala 182:49]
  assign hbmCattrip = 1'h0; // @[StaticU280Top.scala 44:25]
  assign sysClk_pad_I = sysClkP; // @[Buf.scala 52:26]
  assign sysClk_pad_IB = sysClkN; // @[Buf.scala 53:27]
  assign sysClk_pad_1_I = sysClk_pad_O; // @[Buf.scala 34:26]
  assign instQdma_sys_rst_n = instQdma_io_sys_rst_n_pad_O; // @[StaticU280Top.scala 63:33]
  assign instQdma_sys_clk = ibufds_gte4_inst_ODIV2; // @[StaticU280Top.scala 64:41]
  assign instQdma_sys_clk_gt = ibufds_gte4_inst_O; // @[StaticU280Top.scala 65:33]
  assign instQdma_pci_exp_rxn = {{8'd0}, qdmaPin_rx_n}; // @[StaticU280Top.scala 69:33]
  assign instQdma_pci_exp_rxp = {{8'd0}, qdmaPin_rx_p}; // @[StaticU280Top.scala 70:33]
  assign instQdma_m_axib_awready = core_io_qdma_m_axib_awready; // @[StaticU280Top.scala 242:70]
  assign instQdma_m_axib_wready = core_io_qdma_m_axib_wready; // @[StaticU280Top.scala 247:70]
  assign instQdma_m_axib_bid = core_io_qdma_m_axib_bid; // @[StaticU280Top.scala 248:70]
  assign instQdma_m_axib_bresp = core_io_qdma_m_axib_bresp; // @[StaticU280Top.scala 249:70]
  assign instQdma_m_axib_bvalid = core_io_qdma_m_axib_bvalid; // @[StaticU280Top.scala 250:70]
  assign instQdma_m_axib_arready = core_io_qdma_m_axib_arready; // @[StaticU280Top.scala 261:70]
  assign instQdma_m_axib_rid = core_io_qdma_m_axib_rid; // @[StaticU280Top.scala 262:70]
  assign instQdma_m_axib_rdata = core_io_qdma_m_axib_rdata; // @[StaticU280Top.scala 263:70]
  assign instQdma_m_axib_rresp = core_io_qdma_m_axib_rresp; // @[StaticU280Top.scala 264:70]
  assign instQdma_m_axib_rlast = core_io_qdma_m_axib_rlast; // @[StaticU280Top.scala 265:70]
  assign instQdma_m_axib_rvalid = core_io_qdma_m_axib_rvalid; // @[StaticU280Top.scala 266:70]
  assign instQdma_m_axil_awready = core_io_qdma_m_axil_awready; // @[StaticU280Top.scala 270:70]
  assign instQdma_m_axil_wready = core_io_qdma_m_axil_wready; // @[StaticU280Top.scala 274:70]
  assign instQdma_m_axil_bresp = core_io_qdma_m_axil_bresp; // @[StaticU280Top.scala 275:70]
  assign instQdma_m_axil_bvalid = core_io_qdma_m_axil_bvalid; // @[StaticU280Top.scala 276:70]
  assign instQdma_m_axil_arready = core_io_qdma_m_axil_arready; // @[StaticU280Top.scala 280:70]
  assign instQdma_m_axil_rdata = core_io_qdma_m_axil_rdata; // @[StaticU280Top.scala 281:70]
  assign instQdma_m_axil_rresp = core_io_qdma_m_axil_rresp; // @[StaticU280Top.scala 282:70]
  assign instQdma_m_axil_rvalid = core_io_qdma_m_axil_rvalid; // @[StaticU280Top.scala 283:70]
  assign instQdma_soft_reset_n = core_io_qdma_soft_reset_n; // @[StaticU280Top.scala 285:70]
  assign instQdma_h2c_byp_in_st_addr = core_io_qdma_h2c_byp_in_st_addr; // @[StaticU280Top.scala 286:70]
  assign instQdma_h2c_byp_in_st_len = core_io_qdma_h2c_byp_in_st_len; // @[StaticU280Top.scala 287:70]
  assign instQdma_h2c_byp_in_st_eop = core_io_qdma_h2c_byp_in_st_eop; // @[StaticU280Top.scala 288:70]
  assign instQdma_h2c_byp_in_st_sop = core_io_qdma_h2c_byp_in_st_sop; // @[StaticU280Top.scala 289:70]
  assign instQdma_h2c_byp_in_st_mrkr_req = core_io_qdma_h2c_byp_in_st_mrkr_req; // @[StaticU280Top.scala 290:70]
  assign instQdma_h2c_byp_in_st_sdi = core_io_qdma_h2c_byp_in_st_sdi; // @[StaticU280Top.scala 291:70]
  assign instQdma_h2c_byp_in_st_qid = core_io_qdma_h2c_byp_in_st_qid; // @[StaticU280Top.scala 292:70]
  assign instQdma_h2c_byp_in_st_error = core_io_qdma_h2c_byp_in_st_error; // @[StaticU280Top.scala 293:70]
  assign instQdma_h2c_byp_in_st_func = core_io_qdma_h2c_byp_in_st_func; // @[StaticU280Top.scala 294:70]
  assign instQdma_h2c_byp_in_st_cidx = core_io_qdma_h2c_byp_in_st_cidx; // @[StaticU280Top.scala 295:70]
  assign instQdma_h2c_byp_in_st_port_id = core_io_qdma_h2c_byp_in_st_port_id; // @[StaticU280Top.scala 296:70]
  assign instQdma_h2c_byp_in_st_no_dma = core_io_qdma_h2c_byp_in_st_no_dma; // @[StaticU280Top.scala 297:70]
  assign instQdma_h2c_byp_in_st_vld = core_io_qdma_h2c_byp_in_st_vld; // @[StaticU280Top.scala 298:70]
  assign instQdma_c2h_byp_in_st_csh_addr = core_io_qdma_c2h_byp_in_st_csh_addr; // @[StaticU280Top.scala 300:70]
  assign instQdma_c2h_byp_in_st_csh_qid = core_io_qdma_c2h_byp_in_st_csh_qid; // @[StaticU280Top.scala 301:70]
  assign instQdma_c2h_byp_in_st_csh_error = core_io_qdma_c2h_byp_in_st_csh_error; // @[StaticU280Top.scala 302:70]
  assign instQdma_c2h_byp_in_st_csh_func = core_io_qdma_c2h_byp_in_st_csh_func; // @[StaticU280Top.scala 303:70]
  assign instQdma_c2h_byp_in_st_csh_port_id = core_io_qdma_c2h_byp_in_st_csh_port_id; // @[StaticU280Top.scala 304:70]
  assign instQdma_c2h_byp_in_st_csh_pfch_tag = core_io_qdma_c2h_byp_in_st_csh_pfch_tag; // @[StaticU280Top.scala 305:70]
  assign instQdma_c2h_byp_in_st_csh_vld = core_io_qdma_c2h_byp_in_st_csh_vld; // @[StaticU280Top.scala 306:70]
  assign instQdma_s_axis_c2h_tdata = core_io_qdma_s_axis_c2h_tdata; // @[StaticU280Top.scala 308:70]
  assign instQdma_s_axis_c2h_tcrc = core_io_qdma_s_axis_c2h_tcrc; // @[StaticU280Top.scala 309:70]
  assign instQdma_s_axis_c2h_ctrl_marker = core_io_qdma_s_axis_c2h_ctrl_marker; // @[StaticU280Top.scala 310:70]
  assign instQdma_s_axis_c2h_ctrl_ecc = core_io_qdma_s_axis_c2h_ctrl_ecc; // @[StaticU280Top.scala 311:70]
  assign instQdma_s_axis_c2h_ctrl_len = core_io_qdma_s_axis_c2h_ctrl_len; // @[StaticU280Top.scala 312:70]
  assign instQdma_s_axis_c2h_ctrl_port_id = core_io_qdma_s_axis_c2h_ctrl_port_id; // @[StaticU280Top.scala 313:70]
  assign instQdma_s_axis_c2h_ctrl_qid = core_io_qdma_s_axis_c2h_ctrl_qid; // @[StaticU280Top.scala 314:70]
  assign instQdma_s_axis_c2h_ctrl_has_cmpt = core_io_qdma_s_axis_c2h_ctrl_has_cmpt; // @[StaticU280Top.scala 315:70]
  assign instQdma_s_axis_c2h_mty = core_io_qdma_s_axis_c2h_mty; // @[StaticU280Top.scala 316:70]
  assign instQdma_s_axis_c2h_tlast = core_io_qdma_s_axis_c2h_tlast; // @[StaticU280Top.scala 317:70]
  assign instQdma_s_axis_c2h_tvalid = core_io_qdma_s_axis_c2h_tvalid; // @[StaticU280Top.scala 318:70]
  assign instQdma_m_axis_h2c_tready = core_io_qdma_m_axis_h2c_tready; // @[StaticU280Top.scala 330:70]
  assign instQdma_s_axis_c2h_cmpt_tdata = core_io_qdma_s_axis_c2h_cmpt_tdata; // @[StaticU280Top.scala 336:70]
  assign instQdma_s_axis_c2h_cmpt_size = core_io_qdma_s_axis_c2h_cmpt_size; // @[StaticU280Top.scala 337:70]
  assign instQdma_s_axis_c2h_cmpt_dpar = core_io_qdma_s_axis_c2h_cmpt_dpar; // @[StaticU280Top.scala 338:70]
  assign instQdma_s_axis_c2h_cmpt_tvalid = core_io_qdma_s_axis_c2h_cmpt_tvalid; // @[StaticU280Top.scala 339:70]
  assign instQdma_s_axis_c2h_cmpt_ctrl_qid = core_io_qdma_s_axis_c2h_cmpt_ctrl_qid; // @[StaticU280Top.scala 341:70]
  assign instQdma_s_axis_c2h_cmpt_ctrl_cmpt_type = core_io_qdma_s_axis_c2h_cmpt_ctrl_cmpt_type; // @[StaticU280Top.scala 342:70]
  assign instQdma_s_axis_c2h_cmpt_ctrl_wait_pld_pkt_id = core_io_qdma_s_axis_c2h_cmpt_ctrl_wait_pld_pkt_id; // @[StaticU280Top.scala 343:70]
  assign instQdma_s_axis_c2h_cmpt_ctrl_no_wrb_marker = core_io_qdma_s_axis_c2h_cmpt_ctrl_no_wrb_marker; // @[StaticU280Top.scala 344:70]
  assign instQdma_s_axis_c2h_cmpt_ctrl_port_id = core_io_qdma_s_axis_c2h_cmpt_ctrl_port_id; // @[StaticU280Top.scala 345:70]
  assign instQdma_s_axis_c2h_cmpt_ctrl_marker = core_io_qdma_s_axis_c2h_cmpt_ctrl_marker; // @[StaticU280Top.scala 346:70]
  assign instQdma_s_axis_c2h_cmpt_ctrl_user_trig = core_io_qdma_s_axis_c2h_cmpt_ctrl_user_trig; // @[StaticU280Top.scala 347:70]
  assign instQdma_s_axis_c2h_cmpt_ctrl_col_idx = core_io_qdma_s_axis_c2h_cmpt_ctrl_col_idx; // @[StaticU280Top.scala 348:70]
  assign instQdma_s_axis_c2h_cmpt_ctrl_err_idx = core_io_qdma_s_axis_c2h_cmpt_ctrl_err_idx; // @[StaticU280Top.scala 349:70]
  assign instQdma_h2c_byp_out_rdy = core_io_qdma_h2c_byp_out_rdy; // @[StaticU280Top.scala 350:70]
  assign instQdma_c2h_byp_out_rdy = core_io_qdma_c2h_byp_out_rdy; // @[StaticU280Top.scala 351:70]
  assign instQdma_tm_dsc_sts_rdy = core_io_qdma_tm_dsc_sts_rdy; // @[StaticU280Top.scala 352:70]
  assign instQdma_dsc_crdt_in_vld = core_io_qdma_dsc_crdt_in_vld; // @[StaticU280Top.scala 353:70]
  assign instQdma_dsc_crdt_in_dir = core_io_qdma_dsc_crdt_in_dir; // @[StaticU280Top.scala 355:70]
  assign instQdma_dsc_crdt_in_fence = core_io_qdma_dsc_crdt_in_fence; // @[StaticU280Top.scala 356:70]
  assign instQdma_dsc_crdt_in_qid = core_io_qdma_dsc_crdt_in_qid; // @[StaticU280Top.scala 357:70]
  assign instQdma_dsc_crdt_in_crdt = core_io_qdma_dsc_crdt_in_crdt; // @[StaticU280Top.scala 358:70]
  assign instQdma_qsts_out_rdy = core_io_qdma_qsts_out_rdy; // @[StaticU280Top.scala 359:70]
  assign instQdma_usr_irq_in_vld = core_io_qdma_usr_irq_in_vld; // @[StaticU280Top.scala 360:70]
  assign instQdma_usr_irq_in_vec = core_io_qdma_usr_irq_in_vec; // @[StaticU280Top.scala 361:70]
  assign instQdma_usr_irq_in_fnc = core_io_qdma_usr_irq_in_fnc; // @[StaticU280Top.scala 362:70]
  assign ibufds_gte4_inst_CEB = 1'h0; // @[StaticU280Top.scala 59:41]
  assign ibufds_gte4_inst_I = qdmaPin_sys_clk_p; // @[StaticU280Top.scala 58:41]
  assign ibufds_gte4_inst_IB = qdmaPin_sys_clk_n; // @[StaticU280Top.scala 57:41]
  assign instQdma_io_sys_rst_n_pad_I = qdmaPin_sys_rst_n; // @[Buf.scala 18:26]
  assign mmcmUsrClk_io_CLKIN1 = sysClk_pad_1_O; // @[StaticU280Top.scala 82:33]
  assign core_clock = mmcmUsrClk_io_CLKOUT0; // @[StaticU280Top.scala 101:44]
  assign core_reset = ~userRstn; // @[StaticU280Top.scala 102:36]
  assign core_io_sysClk = mmcmUsrClk_io_CLKOUT2; // @[StaticU280Top.scala 103:83]
  assign core_io_cmacClk = mmcmUsrClk_io_CLKOUT1; // @[StaticU280Top.scala 104:84]
  assign core_io_serClk = mmcmUsrClk_io_CLKOUT3; // @[StaticU280Top.scala 105:83]
  assign core_io_cmacPin_rx_p = cmacPin_rx_p; // @[StaticU280Top.scala 110:73]
  assign core_io_cmacPin_rx_n = cmacPin_rx_n; // @[StaticU280Top.scala 111:73]
  assign core_io_cmacPin_gt_clk_p = cmacPin_gt_clk_p; // @[StaticU280Top.scala 112:89]
  assign core_io_cmacPin_gt_clk_n = cmacPin_gt_clk_n; // @[StaticU280Top.scala 113:89]
  assign core_io_cmacPin2_rx_p = cmacPin2_rx_p; // @[StaticU280Top.scala 119:65]
  assign core_io_cmacPin2_rx_n = cmacPin2_rx_n; // @[StaticU280Top.scala 120:65]
  assign core_io_cmacPin2_gt_clk_p = cmacPin2_gt_clk_p; // @[StaticU280Top.scala 121:90]
  assign core_io_cmacPin2_gt_clk_n = cmacPin2_gt_clk_n; // @[StaticU280Top.scala 122:90]
  assign core_io_ddrPort2_clk = ddrInst2_io_user_clk; // @[StaticU280Top.scala 183:81]
  assign core_io_ddrPort2_rst = ddrInst2_io_user_rst; // @[StaticU280Top.scala 184:57]
  assign core_io_ddrPort2_axi_aw_ready = ddrInst2_io_axi_aw_ready; // @[StaticU280Top.scala 185:69]
  assign core_io_ddrPort2_axi_ar_ready = ddrInst2_io_axi_ar_ready; // @[StaticU280Top.scala 198:69]
  assign core_io_ddrPort2_axi_w_ready = ddrInst2_io_axi_w_ready; // @[StaticU280Top.scala 211:69]
  assign core_io_ddrPort2_axi_r_valid = ddrInst2_io_axi_r_valid; // @[StaticU280Top.scala 218:69]
  assign core_io_ddrPort2_axi_r_bits_data = ddrInst2_io_axi_r_bits_data; // @[StaticU280Top.scala 219:69]
  assign core_io_ddrPort2_axi_r_bits_last = ddrInst2_io_axi_r_bits_last; // @[StaticU280Top.scala 220:69]
  assign core_io_ddrPort2_axi_r_bits_resp = ddrInst2_io_axi_r_bits_resp; // @[StaticU280Top.scala 221:69]
  assign core_io_ddrPort2_axi_r_bits_id = ddrInst2_io_axi_r_bits_id; // @[StaticU280Top.scala 222:69]
  assign core_io_ddrPort2_axi_b_valid = ddrInst2_io_axi_b_valid; // @[StaticU280Top.scala 224:69]
  assign core_io_ddrPort2_axi_b_bits_id = ddrInst2_io_axi_b_bits_id; // @[StaticU280Top.scala 225:69]
  assign core_io_ddrPort2_axi_b_bits_resp = ddrInst2_io_axi_b_bits_resp; // @[StaticU280Top.scala 226:69]
  assign core_io_qdma_axi_aclk = instQdma_axi_aclk; // @[StaticU280Top.scala 231:122]
  assign core_io_qdma_axi_aresetn = instQdma_axi_aresetn; // @[StaticU280Top.scala 232:98]
  assign core_io_qdma_m_axib_awid = instQdma_m_axib_awid; // @[StaticU280Top.scala 233:70]
  assign core_io_qdma_m_axib_awaddr = instQdma_m_axib_awaddr; // @[StaticU280Top.scala 234:70]
  assign core_io_qdma_m_axib_awlen = instQdma_m_axib_awlen; // @[StaticU280Top.scala 235:70]
  assign core_io_qdma_m_axib_awsize = instQdma_m_axib_awsize; // @[StaticU280Top.scala 236:70]
  assign core_io_qdma_m_axib_awburst = instQdma_m_axib_awburst; // @[StaticU280Top.scala 237:70]
  assign core_io_qdma_m_axib_awprot = instQdma_m_axib_awprot; // @[StaticU280Top.scala 238:70]
  assign core_io_qdma_m_axib_awlock = instQdma_m_axib_awlock; // @[StaticU280Top.scala 239:70]
  assign core_io_qdma_m_axib_awcache = instQdma_m_axib_awcache; // @[StaticU280Top.scala 240:70]
  assign core_io_qdma_m_axib_awvalid = instQdma_m_axib_awvalid; // @[StaticU280Top.scala 241:70]
  assign core_io_qdma_m_axib_wdata = instQdma_m_axib_wdata; // @[StaticU280Top.scala 243:70]
  assign core_io_qdma_m_axib_wstrb = instQdma_m_axib_wstrb; // @[StaticU280Top.scala 244:70]
  assign core_io_qdma_m_axib_wlast = instQdma_m_axib_wlast; // @[StaticU280Top.scala 245:70]
  assign core_io_qdma_m_axib_wvalid = instQdma_m_axib_wvalid; // @[StaticU280Top.scala 246:70]
  assign core_io_qdma_m_axib_bready = instQdma_m_axib_bready; // @[StaticU280Top.scala 251:70]
  assign core_io_qdma_m_axib_arid = instQdma_m_axib_arid; // @[StaticU280Top.scala 252:70]
  assign core_io_qdma_m_axib_araddr = instQdma_m_axib_araddr; // @[StaticU280Top.scala 253:70]
  assign core_io_qdma_m_axib_arlen = instQdma_m_axib_arlen; // @[StaticU280Top.scala 254:70]
  assign core_io_qdma_m_axib_arsize = instQdma_m_axib_arsize; // @[StaticU280Top.scala 255:70]
  assign core_io_qdma_m_axib_arburst = instQdma_m_axib_arburst; // @[StaticU280Top.scala 256:70]
  assign core_io_qdma_m_axib_arprot = instQdma_m_axib_arprot; // @[StaticU280Top.scala 257:70]
  assign core_io_qdma_m_axib_arlock = instQdma_m_axib_arlock; // @[StaticU280Top.scala 258:70]
  assign core_io_qdma_m_axib_arcache = instQdma_m_axib_arcache; // @[StaticU280Top.scala 259:70]
  assign core_io_qdma_m_axib_arvalid = instQdma_m_axib_arvalid; // @[StaticU280Top.scala 260:70]
  assign core_io_qdma_m_axib_rready = instQdma_m_axib_rready; // @[StaticU280Top.scala 267:70]
  assign core_io_qdma_m_axil_awaddr = instQdma_m_axil_awaddr; // @[StaticU280Top.scala 268:70]
  assign core_io_qdma_m_axil_awvalid = instQdma_m_axil_awvalid; // @[StaticU280Top.scala 269:70]
  assign core_io_qdma_m_axil_wdata = instQdma_m_axil_wdata; // @[StaticU280Top.scala 271:70]
  assign core_io_qdma_m_axil_wstrb = instQdma_m_axil_wstrb; // @[StaticU280Top.scala 272:70]
  assign core_io_qdma_m_axil_wvalid = instQdma_m_axil_wvalid; // @[StaticU280Top.scala 273:70]
  assign core_io_qdma_m_axil_bready = instQdma_m_axil_bready; // @[StaticU280Top.scala 277:70]
  assign core_io_qdma_m_axil_araddr = instQdma_m_axil_araddr; // @[StaticU280Top.scala 278:70]
  assign core_io_qdma_m_axil_arvalid = instQdma_m_axil_arvalid; // @[StaticU280Top.scala 279:70]
  assign core_io_qdma_m_axil_rready = instQdma_m_axil_rready; // @[StaticU280Top.scala 284:70]
  assign core_io_qdma_h2c_byp_in_st_rdy = instQdma_h2c_byp_in_st_rdy; // @[StaticU280Top.scala 299:70]
  assign core_io_qdma_c2h_byp_in_st_csh_rdy = instQdma_c2h_byp_in_st_csh_rdy; // @[StaticU280Top.scala 307:70]
  assign core_io_qdma_s_axis_c2h_tready = instQdma_s_axis_c2h_tready; // @[StaticU280Top.scala 319:70]
  assign core_io_qdma_m_axis_h2c_tdata = instQdma_m_axis_h2c_tdata; // @[StaticU280Top.scala 320:70]
  assign core_io_qdma_m_axis_h2c_tcrc = instQdma_m_axis_h2c_tcrc; // @[StaticU280Top.scala 321:70]
  assign core_io_qdma_m_axis_h2c_tuser_qid = instQdma_m_axis_h2c_tuser_qid; // @[StaticU280Top.scala 322:70]
  assign core_io_qdma_m_axis_h2c_tuser_port_id = instQdma_m_axis_h2c_tuser_port_id; // @[StaticU280Top.scala 323:70]
  assign core_io_qdma_m_axis_h2c_tuser_err = instQdma_m_axis_h2c_tuser_err; // @[StaticU280Top.scala 324:70]
  assign core_io_qdma_m_axis_h2c_tuser_mdata = instQdma_m_axis_h2c_tuser_mdata; // @[StaticU280Top.scala 325:70]
  assign core_io_qdma_m_axis_h2c_tuser_mty = instQdma_m_axis_h2c_tuser_mty; // @[StaticU280Top.scala 326:70]
  assign core_io_qdma_m_axis_h2c_tuser_zero_byte = instQdma_m_axis_h2c_tuser_zero_byte; // @[StaticU280Top.scala 327:70]
  assign core_io_qdma_m_axis_h2c_tlast = instQdma_m_axis_h2c_tlast; // @[StaticU280Top.scala 328:70]
  assign core_io_qdma_m_axis_h2c_tvalid = instQdma_m_axis_h2c_tvalid; // @[StaticU280Top.scala 329:70]
  assign core_io_qdma_axis_c2h_status_drop = instQdma_axis_c2h_status_drop; // @[StaticU280Top.scala 331:70]
  assign core_io_qdma_axis_c2h_status_last = instQdma_axis_c2h_status_last; // @[StaticU280Top.scala 332:70]
  assign core_io_qdma_axis_c2h_status_cmp = instQdma_axis_c2h_status_cmp; // @[StaticU280Top.scala 333:70]
  assign core_io_qdma_axis_c2h_status_valid = instQdma_axis_c2h_status_valid; // @[StaticU280Top.scala 334:70]
  assign core_io_qdma_axis_c2h_status_qid = instQdma_axis_c2h_status_qid; // @[StaticU280Top.scala 335:70]
  assign core_io_qdma_s_axis_c2h_cmpt_tready = instQdma_s_axis_c2h_cmpt_tready; // @[StaticU280Top.scala 340:70]
  assign core_io_qdma_dsc_crdt_in_rdy = instQdma_dsc_crdt_in_rdy; // @[StaticU280Top.scala 354:70]
  assign core_io_qdma_usr_irq_out_ack = instQdma_usr_irq_out_ack; // @[StaticU280Top.scala 363:70]
  assign core_io_qdma_usr_irq_out_fail = instQdma_usr_irq_out_fail; // @[StaticU280Top.scala 364:70]
  assign core_S_BSCAN_drck = 1'h0;
  assign core_S_BSCAN_shift = 1'h0;
  assign core_S_BSCAN_tdi = 1'h0;
  assign core_S_BSCAN_update = 1'h0;
  assign core_S_BSCAN_sel = 1'h0;
  assign core_S_BSCAN_tms = 1'h0;
  assign core_S_BSCAN_tck = 1'h0;
  assign core_S_BSCAN_runtest = 1'h0;
  assign core_S_BSCAN_reset = 1'h0;
  assign core_S_BSCAN_capture = 1'h0;
  assign core_S_BSCAN_bscanid_en = 1'h0;
  assign ddrInst2_io_ddrpin_ddr0_sys_100M_p = ddrPin2_ddr0_sys_100M_p; // @[StaticU280Top.scala 182:49]
  assign ddrInst2_io_ddrpin_ddr0_sys_100M_n = ddrPin2_ddr0_sys_100M_n; // @[StaticU280Top.scala 182:49]
  assign ddrInst2_io_axi_aw_valid = core_io_ddrPort2_axi_aw_valid; // @[StaticU280Top.scala 186:69]
  assign ddrInst2_io_axi_aw_bits_addr = core_io_ddrPort2_axi_aw_bits_addr; // @[StaticU280Top.scala 187:69]
  assign ddrInst2_io_axi_aw_bits_burst = core_io_ddrPort2_axi_aw_bits_burst; // @[StaticU280Top.scala 188:69]
  assign ddrInst2_io_axi_aw_bits_cache = core_io_ddrPort2_axi_aw_bits_cache; // @[StaticU280Top.scala 189:69]
  assign ddrInst2_io_axi_aw_bits_id = core_io_ddrPort2_axi_aw_bits_id; // @[StaticU280Top.scala 190:69]
  assign ddrInst2_io_axi_aw_bits_len = core_io_ddrPort2_axi_aw_bits_len; // @[StaticU280Top.scala 191:69]
  assign ddrInst2_io_axi_aw_bits_lock = core_io_ddrPort2_axi_aw_bits_lock; // @[StaticU280Top.scala 192:69]
  assign ddrInst2_io_axi_aw_bits_prot = core_io_ddrPort2_axi_aw_bits_prot; // @[StaticU280Top.scala 193:69]
  assign ddrInst2_io_axi_aw_bits_qos = core_io_ddrPort2_axi_aw_bits_qos; // @[StaticU280Top.scala 194:69]
  assign ddrInst2_io_axi_aw_bits_size = core_io_ddrPort2_axi_aw_bits_size; // @[StaticU280Top.scala 196:69]
  assign ddrInst2_io_axi_ar_valid = core_io_ddrPort2_axi_ar_valid; // @[StaticU280Top.scala 199:69]
  assign ddrInst2_io_axi_ar_bits_addr = core_io_ddrPort2_axi_ar_bits_addr; // @[StaticU280Top.scala 200:69]
  assign ddrInst2_io_axi_ar_bits_burst = core_io_ddrPort2_axi_ar_bits_burst; // @[StaticU280Top.scala 201:69]
  assign ddrInst2_io_axi_ar_bits_cache = core_io_ddrPort2_axi_ar_bits_cache; // @[StaticU280Top.scala 202:69]
  assign ddrInst2_io_axi_ar_bits_id = core_io_ddrPort2_axi_ar_bits_id; // @[StaticU280Top.scala 203:69]
  assign ddrInst2_io_axi_ar_bits_len = core_io_ddrPort2_axi_ar_bits_len; // @[StaticU280Top.scala 204:69]
  assign ddrInst2_io_axi_ar_bits_lock = core_io_ddrPort2_axi_ar_bits_lock; // @[StaticU280Top.scala 205:69]
  assign ddrInst2_io_axi_ar_bits_prot = core_io_ddrPort2_axi_ar_bits_prot; // @[StaticU280Top.scala 206:69]
  assign ddrInst2_io_axi_ar_bits_qos = core_io_ddrPort2_axi_ar_bits_qos; // @[StaticU280Top.scala 207:69]
  assign ddrInst2_io_axi_ar_bits_size = core_io_ddrPort2_axi_ar_bits_size; // @[StaticU280Top.scala 209:69]
  assign ddrInst2_io_axi_w_valid = core_io_ddrPort2_axi_w_valid; // @[StaticU280Top.scala 212:69]
  assign ddrInst2_io_axi_w_bits_data = core_io_ddrPort2_axi_w_bits_data; // @[StaticU280Top.scala 213:69]
  assign ddrInst2_io_axi_w_bits_last = core_io_ddrPort2_axi_w_bits_last; // @[StaticU280Top.scala 214:69]
  assign ddrInst2_io_axi_w_bits_strb = core_io_ddrPort2_axi_w_bits_strb; // @[StaticU280Top.scala 215:69]
  assign ddrInst2_io_axi_r_ready = core_io_ddrPort2_axi_r_ready; // @[StaticU280Top.scala 217:69]
  assign ddrInst2_io_axi_b_ready = core_io_ddrPort2_axi_b_ready; // @[StaticU280Top.scala 223:69]
endmodule
