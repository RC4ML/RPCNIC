# Connect and Deploy Bitstream

We provide two machines for artifact evaluation. The **FPGA machine** is equiped with a Xilinx U280 FPGA machine, and the second machine is a **Vivado machine**. The FPGA machine is used for the RPCNIC experiment, and the Vivado machine is used for deploying bitstream.

## 1. Connect to Artifact Machine
We already create a sudo user `hpca25` on two machines. The password is `hpca25`, but disable password login for security reasons. You can use the following command to connect to the artifact machine.


1. Download private key `hpca25_id_ed25519` from the submit website.
2. Get the jump server domain name (use `jump` refer as following) from the submit website, we provide IPV4 server and IPV6 server(recommend).
3. `ssh hpca25@jump -p xxx -i hpca25_id_ed25519`
4. Enjoy for testing
5. If you have any questions, please contact us.

## 2. Deploy Bitstream on FPGA

### 2.1 Open Vivado

We already install vivado21 on **Vivado machine**, you should connect to the Vivado machine **by a terminal support X11 forward(important!!)** and open Vivado by typing `vivado` in the terminal. We recommend using **MobaXterm** to connect to the Vivado machine.


### 2.2 Open Hardware Manager

Click `Open Hardware Manager` to open the hardware manager.
![](images/202411301455.png)


### 2.3 Open Target 

First click `Open Target` to open the target, and then click `Open New Target` to open the new target.
![](images/202411301457.png)

Click `Next` to continue.

![](images/202411301458.png)

Type in `192.168.189.16` and `3123` for `Remote server`, and click `Next`.

![](images/202411301500.png)

Then check the name and the type of hardware target, and click `Next`.

![](images/202411301501.png)

Finally we connect to the FPGA.

![](images/202411301502.png)

### 2.4 Program FPGA

Right click the FPGA name `xcu280_u55c_0` and click `Program Device`.
![](images/202411301503.png)

Then choose the bitstream file `bitstream/xxxxx.bit` and click `Program`. You don't need set `Debug probes file`.
![](images/202411301504.png)

### 2.5 Restart machine

After programming the FPGA, you should restart the machine by typing `sudo reboot` in the terminal. And then you can run the RPCNIC experiment on the FPGA machine.