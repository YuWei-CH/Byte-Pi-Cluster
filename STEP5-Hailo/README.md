# Raspberry Pi 5 + Hailo-8L AI Kit Installation Guide

This guide automates installation of the Hailo-8L AI Accelerator on Ubuntu Server 24.04 / 24.03 LTS (64-bit) for Raspberry Pi 5.
It compiles and installs the kernel driver, sets up firmware, installs HailoRT, fixes device permissions, and verifies operation.
The entire process takes about 10–15 minutes.

## Hardware & System Requirements
- Raspberry Pi 5 (8 GB recommended)
- Raspberry Pi AI Kit (M.2 HAT + Hailo-8L module)
- Ubuntu Server 24.04 / 24.03 LTS (64 bit)
- 5 V / 5 A USB-C power supply
- Internet access

## Install

### Step 1 – Preparation
```bash
sudo apt update && sudo apt upgrade -y
sudo apt install git wget curl build-essential linux-headers-$(uname -r) -y
```
Ensure the M.2 HAT is firmly connected and visible over PCIe:
```bash
sudo lspci -nn | grep -i hailo
# expected: “Hailo Technologies Ltd. Hailo-8 AI Processor”
```
If you see that line, the PCIe link works and you can proceed.

### Step 2 – Automatic Installation Script
Create the installer file:
```bash
nano ~/install_hailo_on_ubuntu.sh
```
Paste the full script below, save and run it.
```bash
chmod +x ~/install_hailo_on_ubuntu.sh
./install_hailo_on_ubuntu.sh
```
Full Installer Script
```bash
#!/usr/bin/env bash
set -euo pipefail

# ============================================================
# Raspberry Pi 5 + Hailo-8L (AI Kit) Installer
# Ubuntu Server 24.04 / 24.03 LTS (arm64)
# Performs: dependencies → driver → firmware → HailoRT → udev → autoload → self-check
# ============================================================

HAILO_DRV_BRANCH="v4.17.0"
HAILO_FW_VER="4.17.0"
HAILORT_DEB_URL="http://archive.raspberrypi.com/debian/pool/main/h/hailort/hailort_${HAILO_FW_VER}_arm64.deb"
HAILORT_DEB_FILE="/tmp/hailort_${HAILO_FW_VER}_arm64.deb"
FW_DST_DIR="/lib/firmware/hailo"
FW_DST_BIN="${FW_DST_DIR}/hailo8_fw.bin"

log()  { echo -e "\033[1;36m[INFO]\033[0m $*"; }
warn() { echo -e "\033[1;33m[WARN]\033[0m $*"; }

# 0) Dependencies
log "Installing build dependencies..."
sudo apt update
sudo apt install -y build-essential git wget curl ca-certificates pkg-config \
  linux-headers-$(uname -r) pciutils udev

# 1) Driver
log "Fetching Hailo driver source (${HAILO_DRV_BRANCH})..."
cd ~
if [[ ! -d hailort-drivers ]]; then
  git clone https://github.com/hailo-ai/hailort-drivers.git --branch "${HAILO_DRV_BRANCH}"
else
  (cd hailort-drivers && git fetch --all && git checkout "${HAILO_DRV_BRANCH}")
fi

log "Building and installing kernel module..."
cd ~/hailort-drivers/linux/pcie
make -j"$(nproc)" all
sudo make install
sudo depmod -a

# 2) Firmware
log "Preparing firmware..."
cd ~/hailort-drivers
./download_firmware.sh || true
sudo mkdir -p "${FW_DST_DIR}"
if [[ -f "hailo8_fw.${HAILO_FW_VER}.bin" ]]; then
  sudo cp -f "hailo8_fw.${HAILO_FW_VER}.bin" "${FW_DST_BIN}"
elif [[ -f "hailo8_fw.bin" ]]; then
  sudo cp -f "hailo8_fw.bin" "${FW_DST_BIN}"
else
  warn "Firmware not found; please ensure ${FW_DST_BIN} exists."
fi

# 3) HailoRT runtime
log "Installing HailoRT runtime..."
if ! dpkg -s hailort >/dev/null 2>&1; then
  wget -O "${HAILORT_DEB_FILE}" "${HAILORT_DEB_URL}"
  sudo apt install -y "${HAILORT_DEB_FILE}"
else
  log "hailort already installed."
fi
sudo ldconfig

# 4) udev rules
log "Configuring udev rules and group (plugdev)..."
echo 'KERNEL=="hailo*", MODE="0660", GROUP="plugdev"' | \
  sudo tee /etc/udev/rules.d/99-hailo.rules >/dev/null
sudo udevadm control --reload-rules
sudo udevadm trigger
if ! id -nG "$USER" | grep -qw plugdev; then
  sudo usermod -aG plugdev "$USER"
  warn "Added $USER to plugdev group — re-login or run 'newgrp plugdev'."
fi

# 5) Load module
log "Loading hailo_pci module..."
sudo modprobe -r hailo_pci 2>/dev/null || true
sudo modprobe hailo_pci || true

# 6) Autoload on boot
echo hailo_pci | sudo tee /etc/modules-load.d/hailo.conf >/dev/null

# 7) Diagnostics
log "Checking PCI devices..."
sudo lspci -nn | grep -i -E 'hailo|1e60' || warn "No Hailo device detected."
log "Checking loaded modules..."
lsmod | grep -i hailo || warn "hailo module not loaded."
log "Checking device node..."
ls -l /dev/hailo* 2>/dev/null || warn "No /dev/hailo* found."
log "Testing HailoRT CLI..."
set +e
hailortcli fw-control identify
CLI_RC=$?
set -e
if [[ $CLI_RC -ne 0 ]]; then
  warn "hailortcli failed (exit $CLI_RC). Run 'newgrp plugdev' and retry."
else
  log "🎉 Hailo-8L operational!"
fi

log "Done! Re-login or run 'newgrp plugdev' before running inference."
```

### Step 3 – Verification
After the script finishes:
```bash
newgrp plugdev
hailortcli fw-control identify
```
You should see:
```
Executing on device: 0000:01:00.0
Board Name: Hailo-8
Device Architecture: HAILO8L
Firmware Version: 4.17.0
...
```

## Test
Pre-install
```bash
sudo apt update
sudo apt install -y \
  libgirepository1.0-dev gobject-introspection \
  libglib2.0-dev libcairo2-dev \
  libgstreamer1.0-dev gir1.2-gstreamer-1.0 \
  gstreamer1.0-plugins-base gstreamer1.0-plugins-good \
  gstreamer1.0-plugins-bad gstreamer1.0-libav \
  gstreamer1.0-gl gstreamer1.0-tools \
  pkg-config build-essential
```
Install Python and test a sample pipeline:
```bash
sudo apt install python3-venv python3-pip -y
git clone https://github.com/hailo-ai/hailo-rpi5-examples.git
cd hailo-rpi5-examples
python3 -m venv --system-site-packages venv_hailo_rpi_examples
source venv_hailo_rpi_examples/bin/activate
pip install -U pip setuptools wheel
pip install -r requirements.txt
chmod +x download_resources.sh
./download_resources.sh
pip install PyGObject
deactivate
source setup_env.sh
source venv_hailo_rpi_examples/bin/activate
python3 basic_pipelines/detection.py --input resources/detection0.mp4
```
If you have a USB camera:
```bash
v4l2-ctl --list-devices
python3 basic_pipelines/detection.py --input /dev/video0
```

## Expected Result
*/dev/hailo0 exists
hailortcli reports firmware info
detection.py runs inference on video or camera