# Byte Pi Cluster

## Overview

The Byte Pi Cluster is a Raspberry Pi-based mini cluster designed for distributed computing and educational purposes. This project aims to provide a platform for learning about clustering, distributed systems, and high-performance computing using low-cost, readily available hardware.

 **Figures:**

![3801720189143_.pic.jpg](Byte%20Pi%20Cluster%20b5e87014792a40479015049cb773c96e/3801720189143_.pic.jpg)

![3771720189137_.pic.jpg](Byte%20Pi%20Cluster%20b5e87014792a40479015049cb773c96e/275e437b-a549-4af5-9e3a-8109abf61e69.png)

## Features

- **Scalable Architecture**: Easily expand the cluster by adding more Raspberry Pi nodes.
- **Centralized Management**: A headnode for managing the cluster and deploying tasks.
- **Network File System (NFS)**: Shared storage among all nodes for seamless data access.
- **Static IP Configuration**: Ensures reliable network connectivity and simplifies management.
- **FRP**: Secure access to each node by headnode. And headnode can be access with FRP service.

## Hardware Configuration

- **Headnode**: Raspberry Pi 4 with 4GB RAM, acting as the master node.
- **Compute Nodes**: Multiple Raspberry Pi 4 devices with 4GB RAM. And a Raspberry Pi 5 devices with 8GB RAM connect with a RX580 GPU
- **Networking**: All nodes connected via a network switch.
- **Storage**: External 500GB SSD connected to the headnode, shared across the cluster via NFS.
- **GPU**: AMD RX580 provides better image&video processing capabilities as well as a potential general-purpose computing power boost.

## Software Setup

- **Operating System**: Raspbian OS on all nodes.
- **NFS**: Network File System for shared storage.
- **Static IPs**: Each node is assigned a static IP for consistent network configuration.
- **SSH**: Enabled on all nodes for secure access and management.
- **FRP:** Allowed public network access without have public IP.
- **GPU Support:** GPU acceleration (currently support amd polaris).

## Usage

1. **Setup**: Follow the setup instructions to configure the Raspberry Pi nodes and connect them to the network.
2. **Deployment**: Use the headnode to deploy tasks and manage the cluster.
3. **Expansion**: Add new nodes to the cluster as needed by configuring their static IPs and connecting them to the network.

## Future TODO:

1. K8 / SLURM: I want a cluster management or scheduler system
2. TinyLLM: Maybe we can do some inference work here.
3. Distributed Training Framework: Is it possible to finetune a LLM use Pi? I may need someting to figure out.

## Contact

If you have any questions or need further assistance, you can use Github Issues to raise issues. I'll get back to you as soon as I can. And If you have any good idea or something want to let me know, please feel free to contact me:

- **Name**: Yuwei Sun / 孙钰伟 (my Chinese name)
- **Email**: [ys4680@nyu.edu](mailto:ys4680@nyu.edu)

## Thanks

Thanks for these outstanding open source projects:

- **Pi OS linux kernal:** [https://github.com/raspberrypi/linux](https://github.com/raspberrypi/linux)
- **FRP(fast reverse proxy):** [https://github.com/fatedier/frp](https://github.com/fatedier/frp)
- **Raspberry Pi PCI Express device compatibility database:** [https://pipci.jeffgeerling.com/](https://pipci.jeffgeerling.com/)
- …….

### Have a nice day !!!