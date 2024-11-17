# AMDGPU Local&Cross Compilation

Note: There are some useful links:

https://www.jeffgeerling.com/blog/2024/use-external-gpu-on-raspberry-pi-5-4k-gaming

[https://www.raspberrypi.com/documentation/computers/linux_kernel.html#cross-compiled-install](https://www.raspberrypi.com/documentation/computers/linux_kernel.html#cross-compiled-install)

https://www.jeffgeerling.com/blog/2023/forcing-pci-express-gen-30-speeds-on-pi-5

https://gist.github.com/Coreforge/195a75c19061063266de523051d988c4

[https://github.com/geerlingguy/linux/pull/8](https://github.com/geerlingguy/linux/pull/8)

[https://github.com/geerlingguy/raspberry-pi-pcie-devices/issues/680](https://github.com/geerlingguy/raspberry-pi-pcie-devices/issues/680)

## Kernal:

A linux kernal should be used in compilation with AMD GPU support. This kernel is based on the Linux kernel in the Raspberry Pi repository and run on Pi 5 (I am tested work with rpi-6.6.y):

You can find latest version here: [https://github.com/raspberrypi/linux](https://github.com/raspberrypi/linux)

For my, with Jeff’s tutorial, it works on RPI Linux 6.6.54 version. And I have make a copy of that version:

 https://github.com/YuWei-CH/RPI-kernal-with-amdgpu

### Hardware connect:

1. Conenct your GPU to Stand Bracket (PCIE to M.2)
    
    ![1.jpg](AMDGPU%20Local&Cross%20Compilation%20951e0a621e0a42d6bf1b579a5563c5c4/1.jpg)
    
2. Connect Pi5 to M.2 HAT 
    
    ![2.jpg](AMDGPU%20Local&Cross%20Compilation%20951e0a621e0a42d6bf1b579a5563c5c4/e2663a79-f487-4fb1-9406-c94dcef70463.png)
    
3. Connect Stand Bracket M.2  adapter to Raspberry Pi 5 M.2 HAT
    
    ![3791720189141_.pic.jpg](AMDGPU%20Local&Cross%20Compilation%20951e0a621e0a42d6bf1b579a5563c5c4/3791720189141_.pic.jpg)
    
4. Connect power based on the tutorial of your Stand Bracket Board
    
    ![3801720189143_.pic.jpg](AMDGPU%20Local&Cross%20Compilation%20951e0a621e0a42d6bf1b579a5563c5c4/3801720189143_.pic.jpg)
    
5. To force Gen 3 speed on the Pi 5's PCI Express bus, you need to edit /boot/firmware/config.txt and add the following line at the **bottom**:
    
    ```bash
    dtparam=pciex1_gen=3
    ```
    
6. You should be able to find you GPU by `lspci`
    
    ```bash
    lspci
    ```
    

## Local Compilation (On your RPI)

### Env Setup

1. Update OS and install necessary package, install tools needed to compile the kernel:
    
    ```bash
    sudo apt-get upgrade
    sudo apt install git
    sudo apt install bc bison flex libssl-dev make
    ```
    
2. Download kernal source code ()
    
    ```bash
    git clone --depth=1 https://github.com/raspberrypi/linux
    cd linux
    ```
    
3. In all honesty I recommend you use this to ensure you can replicate my experiment 100%.
    
    ```bash
    https://github.com/YuWei-CH/RPI-kernal-with-amdgpu
    ```
    

### Setup Kernal

1. Add amdgpu patchset
    
    ```bash
    wget -O amdgpu-pi5.patch https://github.com/geerlingguy/linux/pull/8.patch
    git apply -v amdgpu-pi5.patch 
    # You should see it apply successfully
    ```
    
2. Before you start recompiling the Linux kernel (following the rest of the instructions in the Pi kernel guide), you should also patch in Coreforge's optimized `memcpy` library:
    
    ```bash
    wget https://gist.githubusercontent.com/Coreforge/91da3d410ec7eb0ef5bc8dee24b91359/raw/b4848d1da9fff0cfcf7b601713efac1909e408e8/memcpy_unaligned.c
    
    gcc -shared -fPIC -o memcpy.so memcpy_unaligned.c
    sudo mv memcpy.so /usr/local/lib/memcpy.so
    sudo nano /etc/ld.so.preload
    
    # Put the following line inside ld.so.preload:
    /usr/local/lib/memcpy.so
    ```
    
3. Install lib dev
    
    ```bash
    sudo apt install libncurses-dev
    ```
    

### Kermal Compilation

1. Prepare the default configuration
    
    ```bash
    cd linux
    KERNEL=kernel_2712
    make bcm2712_defconfig
    ```
    
2. Modify kernel to add AMDGPU support
Enable amdgpu support in kernal：
    
    ```bash
    make menuconfig
    ```
    
    ![image.png](AMDGPU%20Local&Cross%20Compilation%20951e0a621e0a42d6bf1b579a5563c5c4/eb3c6e8b-8beb-4d06-9c5d-b1aa08a61762.png)
    
    In configuration menu，navigate to the following options and enable them：
    
    - `Device Drivers -> Graphics support -> Direct Rendering Manager (XFree86 4.1.0 and higher DRI support)`
    - `Device Drivers -> Graphics support -> Direct Rendering Manager (XFree86 4.1.0 and higher DRI support) -> AMD GPU`
    - `Kernel Features > Page Size > 4 KB (for Box86 compatibility)`
    - `Kernel Features > Kernel support for 32-bit EL0 > Fix up misaligned multi-word loads and stores in user space`
    - `Kernel Features > Fix up misaligned loads and stores from userspace for 64bit code`
    - `Device Drivers > Graphics support > Direct Rendering Manager (XFree86 4.1.0 and higher DRI support) > Force Architecture can write-combine memory`
3. To adjust `LOCALVERSION`, change the following line in `.config`:
    
    ```bash
    CONFIG_LOCALVERSION="-v7l-MY_CUSTOM_KERNEL"
    ```
    
4. make (use 1.5x of RPI-5 number of processors)
    
    ```bash
    sudo make -j6 Image.gz modules dtbs
    ```
    
5. modules install
    
    ```bash
    sudo make -j6 modules_install
    ```
    

### Deploy kernal

After installed kernal and modules:

1. Make a copy of current image
    
    ```bash
    sudo cp /boot/firmware/$KERNEL.img /boot/firmware/$KERNEL-backup.img
    ```
    
2. Copy compiled kernal and modules into `/boot/firmware` folder：
    
    ```bash
    sudo cp arch/arm64/boot/Image.gz /boot/firmware/$KERNEL.img
    sudo cp arch/arm64/boot/dts/broadcom/*.dtb /boot/firmware/
    sudo cp arch/arm64/boot/dts/overlays/*.dtb* /boot/firmware/overlays/
    sudo cp arch/arm64/boot/dts/overlays/README /boot/firmware/overlays/
    ```
    
3. Install AMD firmware
    
    ```bash
    sudo apt install firmware-amd-graphics
    ```
    

### Test

1. Restart Raspberry Pi
    
    ```bash
    sudo reboot
    ```
    
2. Verify AMDGPU
After restart, verify is AMDGPU works well：
    
    ```bash
    dmesg | grep amdgpu
    ```
    
3. You should be able to view your amdgpu through `nvtop` (Interesting right?)
    
    ![Screenshot 2024-11-17 at 12.31.48 PM.png](AMDGPU%20Local&Cross%20Compilation%20951e0a621e0a42d6bf1b579a5563c5c4/Screenshot_2024-11-17_at_12.31.48_PM.png)
    

## Cross Compilation (On another computer)

 **Basically, I found the easiest way is using a Ubuntu OS for cross compilation**

### Prepare

1. Install required dependencies and toolchain
    
    ```bash
    sudo apt install bc bison flex libssl-dev make libc6-dev libncurses5-dev
    # for 64bit
    sudo apt install crossbuild-essential-arm64
    ```
    
2. Build configuration
    
    ```bash
    cd linux
    KERNEL=kernel_2712
    make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- bcm2712_defconfig
    ```
    
3. Modify kernel to add AMDGPU support
Enable amdgpu support in kernal：
    
    ```bash
    make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- menuconfig
    ```
    
    In configuration menu，navigate to the following options and enable them：
    
    - `Device Drivers -> Graphics support -> Direct Rendering Manager (XFree86 4.1.0 and higher DRI support)`
    - `Device Drivers -> Graphics support -> Direct Rendering Manager (XFree86 4.1.0 and higher DRI support) -> AMD GPU`
    - `Kernel Features > Page Size > 4 KB (for Box86 compatibility)`
    - `Kernel Features > Kernel support for 32-bit EL0 > Fix up misaligned multi-word loads and stores in user space`
    - `Kernel Features > Fix up misaligned loads and stores from userspace for 64bit code`
    - `Device Drivers > Graphics support > Direct Rendering Manager (XFree86 4.1.0 and higher DRI support) > Force Architecture can write-combine memory`
4. To adjust `LOCALVERSION`, change the following line in `.config`:
    
    ```bash
    CONFIG_LOCALVERSION="-v7l-MY_CUSTOM_KERNEL"
    ```
    
5. Build 
    
    ```bash
    make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- Image modules dtbs
    ```
    

### Install the kernel

Having built the kernel, you need to copy it onto your Raspberry Pi boot media (likely an SD card or SSD) and install the modules.

1.  Find your boot media
    
    Run `lsblk`. Then, connect your boot media. Run `lsblk` again; the new device represents your boot media. You should see output similar to the following:
    
    First, mount these partitions as `mnt/boot` and `mnt/root`, adjusting the partition letter to match the location of your boot media: 
    
    ```bash
    mkdir mnt
    mkdir mnt/root
    sudo mount /dev/sdb2 mnt/root
    ```
    
2. install the kernel modules onto the boot media: (on 12 cores)
    
    ```bash
    # For 64-bit kernal
    sudo env PATH=$PATH make -j12 ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- INSTALL_MOD_PATH=mnt/root modules_install
    ```
    
3. Umount 
    
    ```bash
    sudo umount mnt/root
    ```
    

### Now you can back to **Deploy kernal** in local compilation and do the rest steps