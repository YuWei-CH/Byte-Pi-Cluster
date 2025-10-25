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
