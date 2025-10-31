# Raspberry Pi 5 + Hailo-8L AI Kit Installation Guide

This guide automates installation of the Hailo-8L AI Accelerator on Ubuntu Server 24.04 / 24.03 LTS (64-bit) for Raspberry Pi 5.
It compiles and installs the kernel driver, sets up firmware, installs HailoRT, fixes device permissions, and verifies operation.
The entire process takes about 10–15 minutes.

## Hardware & System Requirements
- Raspberry Pi 5 (8 GB recommended)
- Raspberry Pi AI Kit (M.2 HAT + Hailo-8 module)
- Raspberry Pi OS Bookworm
- 5 V / 5 A USB-C power supply
- Internet access

## Install

### Step 1 – Preparation
```bash
ssudo apt update && sudo apt full-upgrade -y
# Update EEPROM 
sudo rpi-eeprom-update
# If EEPROM too early (earlier than 2024)
sudo raspi-config   # Advanced Options -> Bootloader Version -> newest
sudo rpi-eeprom-update -a
sudo rebootTechnologies Ltd. Hailo-8 AI Processor”
```
If you see that line, the PCIe link works and you can proceed.

### Step 2 – Setup PCIE 3.0
Create the installer file:
```bash
sudo tee -a /boot/firmware/config.txt >/dev/null <<EOF
dtparam=pciex1=on
dtparam=pciex1_gen=3
EOF
sudo reboot
```

### Step 3 – Install HAILO AI
```bash
sudo apt install hailo-all
sudo reboot
```

### Step 4 – Verify hardware
You should see device identification information, such as “Board Name: HAILO-8” or similar output. 
```bash
hailortcli fw-control identify
dmesg | grep -i hailo
ls /dev/hailo*
```

### Build
```bash
git clone https://github.com/hailo-ai/hailo-rpi5-examples.git
cd hailo-rpi5-examples
./install.sh
source venv_hailo_rpi_examples/bin/activate
pip install -U meson ninja
```

## Test
It is essentially a complete object detection demonstration pipeline.
Its function is equivalent to "running the entire Hailo SDK pipeline through", verifying that your driver, HailoRT, TAPPAS, and GStreamer are all functioning correctly.
```bash
source setup_env.sh
python basic_pipelines/detection.py --input /usr/local/hailo/resources/videos/example.mp4
```

## Expected Result
*/dev/hailo0 exists
hailortcli reports firmware info
detection.py runs inference on video or camera