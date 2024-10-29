# K3s

### Intro

Several Kubernetes distributions are optimized for edge computing devices, such as K3s and MicroK8s. I prefer K3s, as I’m running Raspberry Pi OS. If you’re using Ubuntu on your Raspberry Pi, MicroK8s could be a better choice.

(There are some useful and helpful link below)

https://ubuntu.com/tutorials/how-to-kubernetes-cluster-on-raspberry-pi#1-overview

https://k3s.io/

### Buikd

for each nodes, include head nodes and compute nodes(someone my prefer call them root node and leave nodes), run

```bash
sudo nano /boot/firmware/cmdline.txt

### and add folloing to the file

cgroup_memory=1 cgroup_enable=memory
```

Update your node

```bash
sudo apt update && sudo apt upgrade -y
```

Install K3s on k3s

```bash
curl -sfL https://get.k3s.io | sh -
```

Get Token for headnode after you install k3s on headnode

```bash
sudo cat /var/lib/rancher/k3s/server/node-token
```

Install k3s for compute nodes

```bash
curl -sfL [https://get.k3s.io](https://get.k3s.io/) | K3S_URL=https://<IP for headnode>:6443 K3S_TOKEN=<Token for headnode> sh -
```

Setup permission and config

```bash
sudo chmod 644 /etc/rancher/k3s/k3s.yaml
export KUBECONFIG=/etc/rancher/k3s/k3s.yaml
echo "export KUBECONFIG=/etc/rancher/k3s/k3s.yaml" >> ~/.bashrc
source ~/.bashrc
```

Confirm that kubectl (K3s’s Kubernetes command-line tool) is working:

```bash
kubectl get nodes
```