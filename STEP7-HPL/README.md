# HPL

### **Please set up MPI first! (STEP6)**

### References:

[https://icl.utk.edu/hpl/](https://icl.utk.edu/hpl/)

[https://top500.org/project/linpack/](https://top500.org/project/linpack/)

**HPL** is a software package that solves a (random) dense linear system in double precision (64 bits) arithmetic on distributed-memory computers. It can thus be regarded as a portable as well as freely available implementation of the High Performance Computing Linpack Benchmark.

The **algorithm** used by HPL can be summarized by the following keywords: Two-dimensional block-cyclic data distribution - Right-looking variant of the LU factorization with row partial pivoting featuring multiple look-ahead depths - Recursive panel factorization with pivot search and column broadcast combined - Various virtual panel broadcast topologies - bandwidth reducing swap-broadcast algorithm - backward substitution with look-ahead of depth 1.

The HPL package provides a testing and timing program to quantify the **accuracy** of the obtained solution as well as the time it took to compute it. The best **performance** achievable by this software on your system depends on a large variety of factors. Nonetheless, with some restrictive assumptions on the interconnection network, the algorithm described here and its attached implementation are **scalable** in the sense that their parallel efficiency is maintained constant with respect to the per processor memory usage.

The HPL software package **requires** the availibility on your system of an implementation of the Message Passing Interface **MPI** (1.1 compliant). An implementation of **either** the Basic Linear Algebra Subprograms **BLAS or** the Vector Signal Image Processing Library **VSIPL** is also needed. Machine-specific as well as generic implementations of [MPI](https://www.netlib.org/benchmark/hpl/links.html#mpi_libs), the [BLAS](https://www.netlib.org/benchmark/hpl/links.html#blas_libs) and [VSIPL](https://www.netlib.org/benchmark/hpl/links.html#vsip_libs) are available for a large variety of systems.

Install essential package for build

```bash
sudo apt-get update
sudo apt-get install -y build-essential gfortran libopenblas-dev libopenmpi-dev
```

Install BLAS (Linear Algebra library)

```bash
sudo apt-get update
sudo apt-get install -y libopenblas-dev
```

Get HPL and unzip gz

```bash
wget https://www.netlib.org/benchmark/hpl/hpl-2.3.tar.gz
tar xzvf XXXXX
```

Make a Make_($Arch) file for **RPI**(raspberry pi)

```bash
cp setup/Make.Linux_PII_CBLAS Make.Linux_ARM
nano Make.Linux_ARM
```

Get the path of mpi, openblas and replace LAdir, LAlib, MPdir, MPinc

```bash
mpicc -show
ldconfig -p | grep openblas
```

**I upload my Make.Linux_ARM as a reference.**

Make. Make sure you have ./xhpl in your testing folder after make step.

```bash
 cp Make.Linux_ARM Makefile
 mv Makefile ..
 cd ..
 make arch=Linux_AR
 ./configure
```

Modify the HPL.dat to fit your machine. I believe these two sites are really good references:

https://www.advancedclustering.com/act_kb/tune-hpl-dat-file/

[https://www.netlib.org/benchmark/hpl/tuning.html](https://www.netlib.org/benchmark/hpl/tuning.html)

```bash
cd testing/
nano HPL.dat
```

For my experience, the Pi cluster is limited by it’s bandwith. ‘***NBs***’ can be a little bit larger, like 192 for 4-6 RPI 4 nodes. And ‘***Ns***’ should based on your PIs RAM. I append my HPL.dat as a reference. And I don’t use GPU for HPL.

```bash
mpiexec -np 20 ./xhpl
# np equals to process number: num of CPU * core/CPU
```