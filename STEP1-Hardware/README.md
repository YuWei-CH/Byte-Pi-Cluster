# Hardware Setup

## Hardware Components

The Byte-Pi-Cluster consists of the following hardware components:

### Headnode & Compute Nodes (4 * Pi **board**)

- **Model:** Raspberry Pi 4 Model B
- **CPU:** Quad-core Cortex-A72 (ARM v8) 64-bit SoC @ 1.5GHz
- **RAM:** 4GB
- **Storage:** 32GB MicroSD card
- **Extra Storage:** 500GB Extreme Portable SSD, USB-C, USB 3.2 Gen 2
- **Power Supply:** Anker 60W 6 Port Charging Station

### GPU Compute Node (1 * Pi **board**)

- **Model:** Raspberry Pi 5
- **CPU:** Broadcom BCM2712 quad-core Arm Cortex A76 processor @ 2.4GHz
- **RAM:** 8GB
- **Storage:** 64GB MicroSD card
- **Power Supply:** 27W USB-C Power Supply

### Network

- **Switch:** NETGEAR 8 Port PoE Gigabit Ethernet Plus Switch (GS308EP)
- **Cables:** 6 * CAT6 Ethernet cables

### Cases and Cooling

- **Cluster Case(Pi 4 Model B):** GeeekPi Cluster Case for Raspberry Pi 4 Model B, Pi Case with Cooling Fan and Heatsinks
- **Heatsinks and Fans(Pi 5):** Aluminum heatsinks for CPU and RAM and 5V cooling fans
- **Case(Pi 5):** Transparent acrylic case
- **Charge Cables:** 5 * 1 Foot Short USB C Cord Fast Charge 5 Pack Durable USB A to USB Type C 3A
- **Rack:** Free Amazon paper box !!!

### GPU Components

- **M.2 HAT:** GeeekPi N04 M.2 NVMe to PCIe Adapter for Raspberry Pi 5
- **GPU:** RX 580 8GB Graphics Card (or other GPU you have)
- **GPU Stand Bracket:** ADT-LINK M.2 Key M NVMe External Graphics Card Stand Bracket with PCIe3.0 x4 Riser Cable
- **Power supply:** Any ATX PC power supply that fit your GPU choice

## Hardware Setup

1. **Prepare Raspberry Pi Nodes:**
    - Attach heatsinks to each Raspberry Pi
    - Setup Pi4 cluster by the tutorial from cluster case provider
        
        ![3811720189145_.pic.jpg](Hardware%20Setup%209781235bcce541829a5758a85a53239c/47bff0f7-11c9-4cea-bd9b-eeb4220e8ce2.png)
        
    - Glue the raspberry pi 5 fan to the M.2 HAT
    - Connect Pi 5 to the M.2 HAT
        
        ![3791720189141_.pic.jpg](Hardware%20Setup%209781235bcce541829a5758a85a53239c/8858bd51-faad-4f01-862b-e036c86897a4.png)
        
    - Connect the Raspberry Pi to the power supply and the network switch using Ethernet cables
        
        ![3781720189139_.pic.jpg](Hardware%20Setup%209781235bcce541829a5758a85a53239c/fe953ddd-c68f-47ef-9c85-7121bb39213a.png)
        
- Connect the GPU to Stand Bracket with provider’s tutorial
    
    ![3821720189146_.pic.jpg](Hardware%20Setup%209781235bcce541829a5758a85a53239c/3821720189146_.pic.jpg)
    
- Place all the parts into the rack
    
    ![3801720189143_.pic.jpg](Hardware%20Setup%209781235bcce541829a5758a85a53239c/3801720189143_.pic.jpg)
    
- Cut out the connector and heat sink on the rack
    
    ![3801720189143_.pic.jpg](Hardware%20Setup%209781235bcce541829a5758a85a53239c/3801720189143_.pic%201.jpg)