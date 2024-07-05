# Complete Guide for Setting Up frp for Remote Access to Raspberry Pi Cluster

**FRP is a fast reverse proxy to help you expose a local server behind a NAT or firewall to the internet.**

**Use FRP for intranet penetration. When you don't have a public IP but want to access this cluster from outside the LAN, frp can help you do so.**

## Part 1: Setting Up frp Server

### Step 1: Download and Install frp Server

1. **Download frp:**
    
    Install ARM64 version
    
    ```bash
    cd ~
    mkdir frps
    cd frps
    wget https://github.com/fatedier/frp/releases/download/v0.58.1/frp_0.58.1_linux_arm64.tar.gz
    ```
    
2. **Extract the files:**
    
    ```bash
    tar -xzf frp_0.58.1_linux_amd64.tar.gz
    ```
    
3. **Navigate to the extracted directory:**
    
    ```bash
    cd frp_0.58.1_linux_amd64
    ```
    

### Step 2: Configure frp Server

1. **Edit the `frps.ini` configuration file:**
    
    ```bash
    nano frps.ini
    ```
    
2. **Add the following configuration:**
    
    ```bash
    [common]
    bind_port = 7000
    dashboard_port = 7500
    dashboard_user = XXX
    dashboard_pwd = XXX
    ```
    

### Step 3: Start frp Server

1. **Start the frp server:**
    
    ```bash
    ./frps -c ./frps.ini
    ```
    

### Step 4: Configure frp Server as a System Service (Optional)

1. **Create a service file:**
    
    ```bash
    sudo nano /etc/systemd/system/frps.service
    ```
    
2. **Add the following content:**
    
    ```bash
    [Unit]
    Description=frp server
    After=network.target
    
    [Service]
    ExecStart=/path/to/frps -c /path/to/frps.ini
    Restart=always
    User=nobody
    Group=nogroup
    
    [Install]
    WantedBy=multi-user.target
    ```
    
    Replace `/path/to/frps` with the actual path to the frps executable and configuration file.
    
3. **Reload systemd configuration and start the service:**
    
    ```bash
    sudo systemctl daemon-reload
    sudo systemctl start frps
    sudo systemctl enable frps
    ```
    

## Part 2: Setting Up frp Client on Raspberry Pi Head Node

### Step 1: Download and Install frp Client

1. **Download frp:**
    
    ```bash
    cd ~
    mkdir frpc
    cd frpc
    wget https://github.com/fatedier/frp/releases/download/v0.58.1/frp_0.58.1_linux_arm64.tar.gz
    ```
    
2. **Extract the files:**
    
    ```bash
    tar -xzf frp_0.58.1_linux_arm64.tar.gz
    ```
    
3. **Navigate to the extracted directory:**
    
    ```bash
    cd frp_0.58.1_linux_arm64
    ```
    

### Step 2: Configure frp Client

1. **Create and edit the `frpc.toml` configuration file:**
    
    ```bash
    nano frpc.toml
    ```
    
2. **Add the following configuration:**
    
    ```toml
    [common]
    server_addr = "your public IP"
    server_port = 7000
    
    [pi-ssh]
    type = "tcp"
    local_ip = "127.0.0.1"
    local_port = 22
    remote_port = XXXX
    ```
    
    Replace `XXX` with your frp server's IP address.
    

### Step 3: Start frp Client

1. **Start the frp client:**
    
    ```bash
    ./frpc -c ./frpc.toml
    ```
    

### Step 4: Configure frp Client as a System Service (Optional)

1. **Create a service file:**
    
    ```bash
    sudo nano /etc/systemd/system/frpc.service
    ```
    
2. **Add the following content:**
    
    ```bash
    [Unit]
    Description=frp client
    After=network.target
    
    [Service]
    ExecStart=/path/to/your/frpc -c /path/to/your/frpc.toml
    Restart=always
    User=<username>
    Group=<username>
    
    [Install]
    WantedBy=multi-user.target
    ```
    
    Replace `/path/to/your/frpc` and `/path/to/your/frpc.toml` with the actual paths to the frpc executable and configuration file.
    
3. **Reload systemd configuration and start the service:**
    
    ```bash
    sudo systemctl daemon-reload
    sudo systemctl start frpc
    sudo systemctl enable frpc
    ```
    

## Part 3: Verify Remote Access

1. **SSH Access:**
From a remote machine, access your Raspberry Pi head node through the frp proxy:
    
    ```bash
    ssh -p <remote-port> <user-name>@<public-IP>
    ```
    

## For the FRP setup I refer to [https://github.com/fatedier/frp](https://github.com/fatedier/frp). Once again a big thanks to all the contributors to frp. Please sponsor if you like this project too.