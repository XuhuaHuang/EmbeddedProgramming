# ARM Assembly on WSL — Starter Project

This project demonstrates how to write, assemble, and run a simple ARM Assembly program using **WSL (Windows Subsystem for Linux)**.

## Requirements

Install the required toolchain and emulator in WSL:

```bash
sudo apt update
sudo apt install gcc-arm-linux-gnueabi binutils-arm-linux-gnueabi qemu-user -y
```

## Build and run

From the project root:

```bash
make
make run
```

Expected output:

```vbnet
Hello from ARM Assembly on WSL!
```
