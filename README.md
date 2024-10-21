# GRUB switch

This is a simple physical switch to control GRUB2 inspired by a [simplar project
for STM32](https://github.com/stecman/hw-boot-selection), but implemented on the
Raspberry Pi Pico (developed on RP2040-Zero, but any Pico should be good).

The code is using an SPDT On-Off-On switch, one side selects Linux, the other
Windows, while in the middle selection, the GRUB menu stays on indefinately -
but this should be very easy to modify.

I needed this, because I have a strange dual boot setup where my monitor usually
turns on with the input that is not the default from my UEFI setup.

## Build and install

An uf2 binary is available as release for easy testing.

Install the [pico-SDK](https://github.com/raspberrypi/pico-sdk), cmake and
arm-eabi-gcc.

Make sure to set the environemnt variable PICO_SDK_PATH to point the folder
where your pico-SDK is (e.g. `export PICO_SDK_PATH=/usr/share/pico-sdk`).

Then continue with the usual cmake setup:

```bash
mkdir build
cd build
cmake ..
make
```

Finally, install the generated `build/grubswitch.uf2` on the Pico. It will
reboot as a FAT16 drive, labeled "GRUB-SWITCH".

The switch should be connected to pin28 and pin29 if the code is used
unmodified.

## Setup GRUB

Copy [49_switch](49_switch) to `/etc/grub.d`. Modify the entry numbers
highlighted with comments. Make sure it's executable and run `update-grub` as
root.

## Modification

The letters set by the switch are defined in [msc_disk.h](src/msc_disk.h). The
switch is read in [main.c](src/main.c). The filesystem and filename are defined
in [msc_dis.c](src/msc_disk.c) - although I wouldn't recommend changing this
unless you have to.

## Inspiration

This project was developed based on the following:

* [The ST implementation of the same
  idea](https://github.com/stecman/hw-boot-selection)
* [Another pico
  implementation](https://www.hackster.io/Madrajib/hardware-boot-select-switch-using-pico-a3e3d5)
  I just didn't like that it's a documentation on how to modify an example
* [A nice demonstration project of USB
  MSC](https://github.com/brendena/pico_drag_n_drop_programmer) with a lot of
  links and explanation video.
