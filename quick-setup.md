# Network
nmcli con show

## Headnode

### etho
sudo nmcli con modify "Wired connection 1" ipv4.method manual ipv4.addresses 192.168.1.10/24 ipv4.gateway "" ipv4.dns "8.8.8.8"

sudo nmcli con down "Wired connection 1"
sudo nmcli con up "Wired connection 1"
ip addr show eth0

### wifi
nmcli con show "preconfigured"

sudo nmcli con modify "preconfigured" ipv4.method auto
sudo nmcli con down "preconfigured"
sudo nmcli con up "preconfigured"

##  Children nodes
nmcli con show

### eth
(update 192.168.1.1x)
hs - 0
01 - 1
02 - 2
03 - 3
04 - 4
ai - 5
sudo nmcli con modify "Wired connection 1" ipv4.method manual ipv4.addresses 192.168.1.15/24 ipv4.gateway 192.168.1.10 ipv4.dns "192.168.1.10 8.8.8.8"

sudo nmcli con down "Wired connection 1"
sudo nmcli con up "Wired connection 1"

ip addr show eth0

## host file
sudo nano /etc/hosts

192.168.1.10 hs001
192.168.1.11 pi001
192.168.1.12 pi002
192.168.1.13 pi003
192.168.1.14 pi004
192.168.1.15 ai001

## NAT
### headnode
sudo nano /etc/sysctl.conf

sudo sysctl -p

sudo iptables -t nat -A POSTROUTING -o wlan0 -j MASQUERADE

sudo iptables -t nat -L

sudo sh -c "iptables-save > /etc/iptables.ipv4.nat"

sudo iptables-restore < /etc/iptables.ipv4.nat

sudo nano /etc/rc.local

## Test
ping -c 4 hs001
ping -c 4 pi003
ping -c 4 ai001

## Disable wifi
(on children nodes)
nmcli con show

sudo nmcli con modify "preconfigured" connection.autoconnect no
sudo nmcli radio wifi off

# FRP
headnode

mkdir && cd system_setting
wget https://github.com/fatedier/frp/releases/download/v0.61.2/frp_0.61.2_linux_arm64.tar.gz
tar -zxvf frp_0.61.2_linux_arm64.tar.gz

cd frp_0.61.2_linux_arm64
nano frpc.toml

### systemd
sudo nano /etc/systemd/system/frpc.service

[Unit]
Description=FRP Client Service
After=network.target

[Service]
Type=simple
User=yuwei
WorkingDirectory=/home/yuwei/system_setting/frp_0.61.2_linux_arm64
ExecStart=/home/yuwei/system_setting/frp_0.61.2_linux_arm64/frpc -c /home/yuwei/system_setting/frp_0.61.2_linux_arm64/frpc.toml
Restart=on-failure

[Install]
WantedBy=multi-user.target

sudo systemctl daemon-reload

sudo systemctl enable frpc
sudo systemctl start frpc


# SSH

## macbook to headnode
After generate ssh key on macbook

ssh-copy-id -i ~/.ssh/id_rsa.pub yuwei@hs001.local

## node to node
ssh-keygen -t rsa -b 4096 -C "ys4680@nyu.edu"

ssh-copy-id yuwei@pi001
ssh-copy-id yuwei@pi002
ssh-copy-id yuwei@pi003
ssh-copy-id yuwei@pi004
ssh-copy-id yuwei@ai001
ssh-copy-id yuwei@hs001

# NFS
(headnode)

### Mount
df -h
lsblk
sudo mkfs.ext4 /dev/sda1 -L SSDDATA

sudo mkdir -p /mnt/ssd
sudo mount /dev/sda1 /mnt/ssd

df -h | grep /mnt/ssd

sudo blkid /dev/sda1

sudo nano /etc/fstab
add: UUID=bebf3676-e2e2-45b2-bf67-99fc836b243c /mnt/ssd ext4 defaults 0 2

### Install NFS
sudo apt-get update
sudo apt-get install nfs-kernel-server

sudo chown -R nobody:nogroup /mnt/ssd
sudo chmod 777 /mnt/ssd

sudo nano /etc/exports
add: /mnt/ssd 192.168.1.0/24(rw,sync,no_subtree_check,no_root_squash)

sudo exportfs -a
sudo systemctl restart nfs-kernel-server

### NFS common
(on each children node)

sudo apt install -y nfs-common
sudo mkdir -p /mnt/sharedssd
sudo mount 192.168.1.10:/mnt/ssd /mnt/sharedssd

# Tool

run_everywhere.sh
./run_everywhere.sh 'sudo apt update && sudo apt install -y htop'

# MPI
(all nodes)

./rrun_everywhere.sh 'sudo apt install -y openmpi-bin openmpi-common libopenmpi-dev'

nano ~/mpi_hosts
hs001 slots=4
pi001 slots=4
pi002 slots=4
pi003 slots=4
pi004 slots=4
ai001 slots=4

mpicc hello.c -o hello
mpirun -np 6 --hostfile ~/mpi_hosts ./hello

mv ~/mpi_hosts ～/sharedssd/mpi_hosts
./run_everywhere.sh "echo '# Set default MPI hostfile' >> ~/.bashrc && echo 'export OMPI_MCA_orte_default_hostfile=~/sharedssd/mpi_hosts' >> ~/.bashrc"

mpirun -np 24 ./hello