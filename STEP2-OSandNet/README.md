# OS&Net Setup

## Operating System Setup

For the Byte-Pi-Cluster, we use Raspberry Pi OS (formerly Raspbian). Below are the steps to set up the operating system and configure the network.

### Step 1: Flash the OS Image

1. **Download Raspberry Pi OS:**
    - Use a tool like Raspeberry Pi Imager to select and download the OS image to the MicroSD card.
        
        ![Screenshot 2024-07-05 at 10.42.55 AM.png](OS&Net%20Setup%2052d1f5e122b9429c815f22f5da50f7b7/Screenshot_2024-07-05_at_10.42.55_AM.png)
        
2. **OS Customisation**
    - Setup hostname, username, wifi and local settings
        
        ![Screenshot 2024-07-05 at 10.45.09 AM.png](OS&Net%20Setup%2052d1f5e122b9429c815f22f5da50f7b7/Screenshot_2024-07-05_at_10.45.09_AM.png)
        
    - Setup public key for SSH
        
        ![Screenshot 2024-07-05 at 10.45.22 AM.png](OS&Net%20Setup%2052d1f5e122b9429c815f22f5da50f7b7/Screenshot_2024-07-05_at_10.45.22_AM.png)
        
3. **Flash the OS to the MicroSD Card:**
    - Click ‘NEXT’ to flash the OS into SD card.
    - Do samething for all 5 Pi, change hostname for each Pi.

### Step 2: Initial Setup

1. **Insert the MicroSD Card:**
    - Insert the flashed MicroSD card into the Raspberry Pi.
2. **Boot the Raspberry Pi:**
    - Connect the Raspberry Pi to the power supply and boot it up.
3. **Access the Raspberry Pi:**
    - Use SSH to access the Raspberry Pi. You can find the IP address assigned by your router
    - SSH into the Raspberry Pi:
    
    ```bash
    ssh <usrname>@<hostname>.local
    ```
    

### Step 3: Network Configuration

1. **Static IP Configuration:**
    - Edit the DHCP client configuration to assign a static IP address to each Raspberry Pi.
        
        ```bash
        sudo apt-get update
        sudo apt-get install dhcpcd5
        sudo nano /etc/dhcpcd.conf
        ```
        
    - Add the following lines to configure a static IP address (replace `X` with the appropriate number for each node):
        
        ```bash
        interface eth0
        static ip_address=192.168.1.X/24
        static routers=192.168.1.1
        static domain_name_servers=192.168.1.1
        ```
        
    - Disable WIFI, add the following lines (Optional) for all compute node, do not change disable wifi for headnode:
        
        ```bash
        sudo nano /boot/firmware/config.txt
        ```
        
    - Open the /boot/firmware/config.txt file:
        
        ```bash
        # Disable WiFi    
        dtoverlay=disable-wifi
        ```
        
    - Save and close the file, restart dhcpd.
        
        ```bash
        sudo systemctl restart dhcpcd
        ```
        
    - Check for wifi0, if not that means success.
        
        ```bash
        ifconfig 
        ```
        
2. **Hostname Configuration:**
    - Change the hostname to identify each Raspberry Pi.
        
        ```bash
        sudo nano /etc/hostname
        ```
        
    - Replace the current hostname with a unique name (e.g., `pi001`, `pi002`, etc.).
    - Save and close the file.
    - Edit the hosts file to reflect the new hostname.
        
        ```bash
        sudo nano /etc/hosts
        ```
        
    - Replace the old hostname with the new one.
    - Save and close the file.
3. **Reboot the Raspberry Pi:**
    - Reboot the Raspberry Pi to apply the changes.
        
        ```bash
        sudo reboot
        ```
        

### Step 4: Configuring the Head Node for Network Forwarding

1. **Enable IP Forwarding for head node:**
    - Open the `/etc/sysctl.conf` file:
        
        ```bash
        sudo nano /etc/sysctl.conf
        ```
        
    - Find the following line and uncomment it (if it is commented), or add this line:
        
        ```bash
        net.ipv4.ip_forward=1
        ```
        
    - Save and close the file.
    - Enable IP forwarding immediately:
        
        ```bash
        sudo sysctl -w net.ipv4.ip_forward=1
        ```
        
2. **Enable IP Forwarding for head node:**
    - Set up iptables rules for network address translation to allow traffic to be forwarded through the head node. Assume your head node uses the `eth0` interface to connect to the external network and the `eth1` interface to connect to the internal network (other Raspberry Pi nodes).
        
        ```bash
        sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
        ```
        
    - Allow traffic forwarding through the `eth1` interface:
        
        ```bash
        sudo iptables -A FORWARD -i eth1 -o eth0 -j ACCEPT
        sudo iptables -A FORWARD -i eth0 -o eth1 -m state --state RELATED,ESTABLISHED -j ACCEPT
        ```
        
3. **Enable IP Forwarding for head node:**
    - Install the `iptables-persistent` package to save and restore iptables rules on reboot:
        
        ```bash
        sudo apt-get install iptables-persistent
        ```
        
    - Save the current iptables rules:
        
        ```bash
        sudo netfilter-persistent save
        ```
        
4. **Update Other Nodes**
    - Edit the `/etc/dhcpcd.conf` file:
        
        ```bash
        sudo nano /etc/dhcpcd.conf
        ```
        
    - Add or modify the following content:
        - Replace `X` with the unique IP address of each node.
        - Replac `Y` with headnode’s IP
        
        ```bash
        interface eth0
        static ip_address=192.168.1.X/24
        static routers=192.168.1.Y
        static domain_name_servers=192.168.1.Y
        ```
        
5. **Reboot**
    - Reboot to enable forwarding
        
        ```bash
        sudo reboot
        ```
        
6. **Test IP forwarding:**
    - Ping IP of each compute nodes
        
        ```bash
        ping 192.168.1.X
        ```
        
    - Ping [google.com](http://google.com) on each compute node
        
        ```bash
        ping google.com
        ```
        

### Step 5: SSH Key Authentication

1. **Generate SSH Keys:**
    - On your local machine, generate an SSH key pair if you haven't already:
        
        ```bash
        ssh-keygen -t rsa -b 4096
        ```
        
2. **Copy SSH Key to Raspberry Pi:**
    - Copy the public key to the Raspberry Pi:
        
        ```bash
        ssh-copy-id pi@<RaspberryPi_IP_Address>
        ```
        
3. **Verify SSH Key Authentication:**
    - SSH into the Raspberry Pi without a password:
        
        ```bash
        ssh pi@<RaspberryPi_IP_Address>
        ```