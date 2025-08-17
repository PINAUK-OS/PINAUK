# PINAUK
PINAUK Is Not an Another Unix Kernel

Yeah, it uses UEFI-SIMPLE.

Its license is in the LICENSE file.

## Join the project's Discord!
[Discord](https://discord.gg/pDyJuJy3hK)

## What is PINAUK?
PINAUK means "**P**INAUK **I**s **N**ot an **A**nother **U**nix **K**ernel".

This is a kernel written in C for UEFI.

You can also contribute to this project as written in the CONTRIBUTING file.

## Building and running
You can either build and run through Visual Studio or using ```make``` or non-Windows platforms (in Linux or in MinGW).

The recommended way is through [Visual Studio](https://github.com/PINAUK-OS/PINAUK/tree/main?tab=readme-ov-file#how-to-build-and-run).

The more experimental (**and UNTESTED**) method is with [```make```](https://github.com/PINAUK-OS/PINAUK/tree/main?tab=readme-ov-file#how-to-build-and-run-with-make).
***
***
***
***
***

## How to build and run with ```make```

### Prerequesites
- gcc/make
- QEMU v2.7 or later
- git
- wget, unzip
### Building
You need to initialize the git submodule either through git commandline with:
```bash
git submodule init
git submodule update
```
Or, if using a UI client (such as TortoiseGit) by selecting Submodule Update in the context menu.
If using MinGW or Linux, issue the following from a command prompt:
```bash
make
```
If needed you can also add ARCH=<arch> and CROSS_COMPILE=<tuple>, e.g.:
```bash
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-
make ARCH=aa64 CROSS_COMPILE=aarch64-linux-gnu-
make ARCH=riscv64 CROSS_COMPILE=riscv64-linux-gnu-
```
where <arch> can be x64, ia32, arm, aa64 or riscv64.

You can also add qemu as your make target to run the application under QEMU, in which case a relevant UEFI firmware (OVMF for x86 or QEMU_EFI for Arm) will be automatically downloaded to run PINAUK against it.









## How to build and run?
Follow those instructions to ensure the kernel builds correctly:
### Prerequisites
1. [Microsoft Visual Studio 2022](https://visualstudio.microsoft.com/)
2. A Git client such as [GitHub Desktop](https://desktop.github.com/download/)
3. [QEMU](http://www.qemu.org) __v2.7 or later__ (NB: You can find QEMU Windows binaries [here](https://qemu.weilnetz.de/w64/))
### Compilation and testing (VISUAL STUDIO)
#### Testing in an emulated environment (requires prerequisite #3)
If you are using Visual Studio, press ```F5``` to build and run the kernel in QEMU.
***
***
***
***
***
If you need to test it on real hardware:
#### Testing on real hardware
##### Via a script (Windows-only)
1. **COMPILE** the project following [Testing on real hardware](https://github.com/PINAUK-OS/PINAUK/edit/main/README.md#testing-in-an-emulated-environment-requires-prerequisite-3)
2. Use the ```burnToFlash.bat``` to build.
> [!CAUTION]
> **DOUBLE- AND TRIPLE-CHECK WHAT YOU HAVE INPUTED! THE SCRIPT MAKES _ABSOLUTELY ZERO CHECKS_ AND INPUTING INCORRECT DATA WILL RESULT IN A DATA LOSS!!! YOU'VE BEEN WARNED.**
##### Manually
1. Get a USB stick
2. Format is as FAT32
3. Copy the built binaries folder onto it (the entire image folder's contents (subfolders), not just the binaries).

The resulting structure should look like:

BOOT/EFI/BOOTX64.EFI (or BOOTIA32.EFI,depends on built architecture)

4. Boot from the drive
### Note about ARM/ARM64 support
Edit your current VS installation in VS Installer -> Add individual components "MSVC v142 - VS 2019 C++ ARM build tools (v14.22)" for ARM and "MSVC v142 - VS 2019 C++ ARM64 build tools (v14.22)" for ARM64.
