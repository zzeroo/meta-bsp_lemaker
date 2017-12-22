include conf/machine/include/bpro-default-settings.inc
include conf/machine/include/bpro-default-versions.inc
include conf/machine/include/bpro-default-providers.inc

IMAGE_FSTYPES ?= "tar.bz2 sdcard"

KERNEL_IMAGETYPE ?= "zImage"

MACHINE_FEATURES += "vfat wifi"

MACHINE_EXTRA_RRECOMMENDS += " kernel-modules"

IMAGE_BOOT_FILES ?= " \
                 ${@bb.utils.contains('KERNEL_IMAGETYPE', 'zImage', '${KERNEL_IMAGETYPE}', '${KERNEL_IMAGETYPE};${SDIMG_KERNELIMAGE}', d)} \
                 ${@bb.utils.contains('KERNEL_IMAGETYPE', 'zImage', 'u-boot.bin;${SDIMG_KERNELIMAGE}', '', d)} \
                 ${@bb.utils.contains('KERNEL_IMAGETYPE', 'zImage', 'boot.scr;boot.scr', '', d)} \
                 "


# https://community.nxp.com/docs/DOC-105521
IMAGE_ROOTFS_EXTRA_SPACE = "100000"
IMAGE_OVERHEAD_FACTOR = "1.5"

# The kernel image is installed into the FAT32 boot partition and does not need
# to also be installed into the rootfs.
RDEPENDS_kernel-base = ""

SERIAL_CONSOLE ?= "115200 ttyS0"

SPL_BINARY="u-boot-sunxi-with-spl.bin"
UBOOT_MACHINE = "Bananapro_defconfig"
KERNEL_DEVICETREE = "sun7i-a20-bananapro.dtb"
