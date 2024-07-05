# Set Up NFS on the Head Node and Automatically Mount SSD

### Step 1: Set Up NFS Server on the Head Node (192.168.1.Y)

1. **Install NFS Server:**
    
    ```bash
    sudo apt-get update
    sudo apt-get install nfs-kernel-server
    ```
    
2. **Create a Shared Directory:**
    
    ```bash
    sudo mkdir -p /mnt/ssd/shared
    ```
    
3. **Set Permissions for the Shared Directory:**
    
    ```bash
    sudo chown -R yuwei:yuwei /mnt/ssd/shared
    sudo chmod 755 /mnt/ssd/shared
    ```
    
4. **Configure NFS Exports:**
Open the exports file:
    
    ```bash
    sudo nano /etc/exports
    ```
    
    Add the following lines to share the directory with the other nodes on your network. Replay X with your compute node IP:
    
    ```bash
    /mnt/ssd/shared 192.168.1.X(rw,sync,no_subtree_check)
    /mnt/ssd/shared 192.168.1.X(rw,sync,no_subtree_check)
    /mnt/ssd/shared 192.168.1.X(rw,sync,no_subtree_check)
    /mnt/ssd/shared 192.168.1.X(rw,sync,no_subtree_check
    ```
    
    Save and close the file.
    
5. **Export the Shared Directory:**
    
    ```bash
    sudo exportfs -a
    ```
    
6. **Restart NFS Server:**
    
    ```bash
    sudo systemctl restart nfs-kernel-server
    ```
    

### Step 2: Automatically Mount SSD on the Head Node

1. **Edit the `fstab` file:**
    
    ```bash
    sudo nano /etc/fstab
    ```
    
2. **Add the mount configuration:**
    
    ```bash
    /dev/sda1 /mnt/ssd ext4 defaults 0 0
    ```
    
3. **Save and close the file.**
4. **Test the `fstab` configuration:**
    
    ```bash
    sudo mount -a
    ```
    
5. **Verify the mount:**
    
    ```bash
    df -h
    ```
    

### Part 2: Automatically Mount NFS Share on Worker Nodes

### Step 1: Set Up NFS Clients on Each Worker Node

For each worker node (192.168.1.X, 192.168.1.X, 192.168.1.X, 192.168.1.X), follow these steps:

1. **Install NFS Common Package:**
    
    ```bash
    sudo apt-get update
    sudo apt-get install nfs-common
    ```
    
2. **Create a Mount Point:**
    
    ```bash
    sudo mkdir -p /home/yuwei/shared
    ```
    
3. **Mount the NFS Share:**
    
    Replay Y with your compute node IP
    
    ```bash
    sudo mount 192.168.1.Y:/mnt/ssd/shared /home/yuwei/shared
    ```
    
4. **Verify the Mount:**
    
    ```bash
    df -h
    ```
    

### Step 2: Automatically Mount NFS Share on Startup

1. **Edit the `fstab` file:**
    
    ```bash
    sudo nano /etc/fstab
    ```
    
2. **Add the NFS mount configuration:**
    
    Replay Y with your compute node IP
    
    ```bash
    192.168.1.Y:/mnt/ssd/shared /home/yuwei/shared nfs defaults 0 0
    ```
    
3. **Save and close the file.**
4. **Test the `fstab` configuration:**
    
    ```bash
    sudo mount -a
    ```
    
5. **Verify the mount:**
    
    ```bash
    df -h
    ```
    

### Verification and Testing

1. **Reboot all machines:**
    
    ```bash
    sudo reboot
    ```
    
2. **Verify the mounts on the Head Node and each Worker Node:**
    
    ```bash
    df -h
    ```
    
    Confirm that the mount point `/mnt/ssd` is correctly mounted on the head node and that `/home/yuwei/shared` is correctly mounted on each worker node.
    

## Result:

1. **Headnode**:
    
    ![Screenshot 2024-07-05 at 2.39.28 PM.png](Set%20Up%20NFS%20on%20the%20Head%20Node%20and%20Automatically%20Moun%20b4a42e06926f41b2879b071a03875902/089dc92d-c9f7-4dfc-a230-ecf453a7afc5.png)
    
2. **Compute nodes:**
    
    ![Screenshot 2024-07-05 at 2.39.40 PM.png](Set%20Up%20NFS%20on%20the%20Head%20Node%20and%20Automatically%20Moun%20b4a42e06926f41b2879b071a03875902/Screenshot_2024-07-05_at_2.39.40_PM.png)