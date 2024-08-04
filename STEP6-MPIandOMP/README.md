# MPIandOMP

### External SSH (if not setup before)

Append IP and hostname of other nodes to /etc/hosts:

```bash
sudo nano /etc/hosts 

# append to end of /etc/hosts 
192.168.1.10    pi000
192.168.1.11    pi001
192.168.1.12    pi002
192.168.1.13    pi003
192.168.1.14    pi004
```

Setting up SSH for passwordless login.

```bash
# For each nodes do following:
ssh-keygen -t rsa

# For headnode
ssh-copy-id yuwei@pi001
ssh-copy-id yuwei@pi002
ssh-copy-id yuwei@pi003
ssh-copy-id yuwei@pi004

# For pi001
ssh-copy-id yuwei@pi000
ssh-copy-id yuwei@pi002
ssh-copy-id yuwei@pi003
ssh-copy-id yuwei@pi004

# For pi002
ssh-copy-id yuwei@pi001
ssh-copy-id yuwei@pi000
ssh-copy-id yuwei@pi003
ssh-copy-id yuwei@pi004

# For pi003
ssh-copy-id yuwei@pi001
ssh-copy-id yuwei@pi002
ssh-copy-id yuwei@pi000
ssh-copy-id yuwei@pi004

# For pi004
ssh-copy-id yuwei@pi001
ssh-copy-id yuwei@pi002
ssh-copy-id yuwei@pi003
ssh-copy-id yuwei@pi000
```

 **If not work,** copy public key by scp on headnode:

```bash
# pi001
ssh yuwei@pi001 "cat ~/.ssh/id_rsa.pub" | ssh yuwei@pi002 "cat >> ~/.ssh/authorized_keys"
ssh yuwei@pi001 "cat ~/.ssh/id_rsa.pub" | ssh yuwei@pi003 "cat >> ~/.ssh/authorized_keys"
ssh yuwei@pi001 "cat ~/.ssh/id_rsa.pub" | ssh yuwei@pi004 "cat >> ~/.ssh/authorized_keys"

# pi002
ssh yuwei@pi002 "cat ~/.ssh/id_rsa.pub" | ssh yuwei@pi001 "cat >> ~/.ssh/authorized_keys"
ssh yuwei@pi002 "cat ~/.ssh/id_rsa.pub" | ssh yuwei@pi003 "cat >> ~/.ssh/authorized_keys"
ssh yuwei@pi002 "cat ~/.ssh/id_rsa.pub" | ssh yuwei@pi004 "cat >> ~/.ssh/authorized_keys"

# pi003
ssh yuwei@pi003 "cat ~/.ssh/id_rsa.pub" | ssh yuwei@pi001 "cat >> ~/.ssh/authorized_keys"
ssh yuwei@pi003 "cat ~/.ssh/id_rsa.pub" | ssh yuwei@pi002 "cat >> ~/.ssh/authorized_keys"
ssh yuwei@pi003 "cat ~/.ssh/id_rsa.pub" | ssh yuwei@pi004 "cat >> ~/.ssh/authorized_keys"

# pi004
ssh yuwei@pi004 "cat ~/.ssh/id_rsa.pub" | ssh yuwei@pi001 "cat >> ~/.ssh/authorized_keys"
ssh yuwei@pi004 "cat ~/.ssh/id_rsa.pub" | ssh yuwei@pi002 "cat >> ~/.ssh/authorized_keys"
ssh yuwei@pi004 "cat ~/.ssh/id_rsa.pub" | ssh yuwei@pi003 "cat >> ~/.ssh/authorized_keys"
```

authority to .ssh and authorized_keys:

```bash
chmod 700 ~/.ssh
chmod 600 ~/.ssh/authorized_keys
```

Authentication for each nodes:

```bash
sudo nano /etc/ssh/sshd_config

# add following to sshd_config:
PasswordAuthentication yes
PubkeyAuthentication yes
AuthorizedKeysFile .ssh/authorized_keys

sudo systemctl restart ssh
```

**After All, please check the SSH connection between all nodes:**

```bash
# eg: executee following on each node
ssh pi000
ssh pi001
ssh pi002
ssh pi003
ssh pi004
```

If some of them failed, we can manually copy public key:

```bash
# On source node
cat ~/.ssh/id_rsa.pub

# On destination node, paste the public key
nano ~/.ssh/authorized_keys
# ctrl + v
```

### MPI(**Message Passing Interface**)

Install OpenMPI

```bash
sudo apt-get update
sudo apt-get install -y openmpi-bin openmpi-common libopenmpi-dev
```

Verify Installation

```bash
mpirun --version
# output similar to the following: 
# mpirun (Open MPI) x.y.z
```

Create host file in shareable files system

```bash
touch /mnt/ssd/mpi/
nano mpi_hosts 
```

Set MPI hostfile path:

```bash
# MPI Host Path
export OMPI_MCA_orte_default_hostfile=/mnt/ssd/mpi/mpi_hosts
```

Add following to the host file:

```bash
# PI 4 and 5 have 4 CPU cores
pi000 slots=4
pi001 slots=4
pi002 slots=4
pi003 slots=4
pi004 slots=4
```

Commands:

```bash
# use the uploaded file
mpicc mpi_hello.c -o /mnt/ssd/mpi/mpi_hello
mpirun -np 20 /mnt/ssd/mpi/mpi_hello
```

Result looks like:

```bash
Hello world from processor 0 out of 16 processors
Hello world from processor 1 out of 16 processors
Hello world from processor 2 out of 16 processors
Hello world from processor 3 out of 16 processors
...
```

### OMP(OpenMP)

Install gcc

```bash
# use the uploaded file
sudo apt-get update
sudo apt-get install -y gcc g++
```

Commands:

```bash
gcc -fopenmp omp_hello.c -o omp_hello
./omp_hello
```