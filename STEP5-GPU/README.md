# AMDGPU Cross Compilation

Note: amdgpu support with RX580 still have a driver issue: 

```bash
[    7.072134] amdgpu: probe of 0000:01:00.0 failed with error -110
```

## Kernal:

The uploaded repository is a cross-compiled kernel with AMD GPU support. This kernel is based on the Linux kernel in the Raspberry Pi repository and run on Pi 5:

 [https://github.com/raspberrypi/linux](https://github.com/raspberrypi/linux)

(Don’t copy this with your board, it should not work.)

### Hardware connect:

1. Conenct your GPU to Stand Bracket (PCIE to M.2)
    
    ![1.jpg](AMDGPU%20Cross%20Compilation%20951e0a621e0a42d6bf1b579a5563c5c4/1.jpg)
    
2. Connect Pi5 to M.2 HAT 
    
    ![2.jpg](AMDGPU%20Cross%20Compilation%20951e0a621e0a42d6bf1b579a5563c5c4/e2663a79-f487-4fb1-9406-c94dcef70463.png)
    
3. Connect Stand Bracket M.2  adapter to Raspberry Pi 5 M.2 HAT
    
    ![3791720189141_.pic.jpg](AMDGPU%20Cross%20Compilation%20951e0a621e0a42d6bf1b579a5563c5c4/3791720189141_.pic.jpg)
    
4. Connect power based on the tutorial of your Stand Bracket Board
    
    ![3801720189143_.pic.jpg](AMDGPU%20Cross%20Compilation%20951e0a621e0a42d6bf1b579a5563c5c4/3801720189143_.pic.jpg)
    

### Env Setup

1. Update OS and install necessary package, install tools needed to compile the kernel:
    
    ```bash
    sudo apt-get upgrade
    sudo apt-get install git bc bison flex libssl-dev make libc6-dev libncurses5-dev crossbuild-essential-arm64
    ```
    
2. Download kernal source code
    
    ```bash
    git clone --depth=1 https://github.com/raspberrypi/linux
    cd linux
    ```
    

### Setup Kernal

1. Config kernal
Use default Pi setting，and add amdgpu support on it
    
    ```bash
    KERNEL=kernel8
    make bcm2711_defconfig
    ```
    
2.  Modify kernel to add AMDGPU support
Enable amdgpu support in kernal：
    
    ```bash
    make menuconfig
    ```
    
    In configuration menu，navigate to the following options and enable them：
    
    - `Device Drivers -> Graphics support -> Direct Rendering Manager (XFree86 4.1.0 and higher DRI support) -> AMD GPU`
    - enable all relevent setting for amdgpu

### Kermal Compilation

1. make
    
    ```bash
    make -j$(nproc) Image.gz modules dtbs
    ```
    
2. modules install
    
    ```bash
    sudo make modules_install
    ```
    

### Deploy kernal

1. install kernal and modules
Copy compiled kernal and modules into `/boot/firmware` folder：
    
    ```bash
    sudo cp arch/arm64/boot/Image.gz /boot/firmware/kernel8.img
    sudo cp arch/arm64/boot/dts/broadcom/*.dtb /boot/firmware/
    sudo cp arch/arm64/boot/dts/overlays/*.dtb* /boot/firmware/overlays/
    sudo cp arch/arm64/boot/dts/overlays/README /boot/firmware/overlays/
    ```
    

### Update `config.txt`

1. **nano `/boot/firmware/config.txt`**
Add following line into `/boot/firmware/config.txt` to enable amdgpu：
    
    ```bash
    dtoverlay=vc4-kms-v3d
    ```
    

### Test

1. **Restart Raspberry Pi**
    
    ```bash
    sudo reboot
    ```
    
2. **Verify AMDGPU**
After restart, verify is AMDGPU works well：
    
    ```bash
    dmesg | grep amdgpu
    ```
    

## References:

[https://www.raspberrypi.com/documentation/computers/linux_kernel.html](https://www.raspberrypi.com/documentation/computers/linux_kernel.html)

[https://pipci.jeffgeerling.com/cards_gpu/sapphire-radeon-rx550-2gb.html](https://pipci.jeffgeerling.com/cards_gpu/sapphire-radeon-rx550-2gb.html)