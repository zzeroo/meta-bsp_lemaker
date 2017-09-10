include conf/machine/include/bpro-default-settings.inc
include conf/machine/include/bpro-default-versions.inc
include conf/machine/include/bpro-default-providers.inc

IMAGE_FSTYPES ?= "tar.bz2 ext3 sdcard"

KERNEL_IMAGETYPE ?= "zImage"

MACHINE_FEATURES += "vfat ext3 wifi"

MACHINE_EXTRA_RRECOMMENDS += " kernel-modules"

IMAGE_BOOT_FILES ?= " \
                 ${@bb.utils.contains('KERNEL_IMAGETYPE', 'zImage', '${KERNEL_IMAGETYPE}', '${KERNEL_IMAGETYPE};${SDIMG_KERNELIMAGE}', d)} \
                 ${@bb.utils.contains('KERNEL_IMAGETYPE', 'zImage', 'u-boot.bin;${SDIMG_KERNELIMAGE}', '', d)} \
                 ${@bb.utils.contains('KERNEL_IMAGETYPE', 'zImage', 'boot.scr;boot.scr', '', d)} \
                 "

# The kernel image is installed into the FAT32 boot partition and does not need
# to also be installed into the rootfs.
RDEPENDS_kernel-base = ""

SERIAL_CONSOLE ?= "115200 ttyS0"

SPL_BINARY="u-boot-sunxi-with-spl.bin"
# UBOOT_ENTRYPOINT = "0x40008000"
# UBOOT_LOADADDRESS = "0x40008000"
# UBOOT_ENV ?= ""
# UBOOT_ENV_SUFFIX ?= "scr"
UBOOT_MACHINE = "Bananapro_defconfig"
# #UBOOT_CONFIG = "Bananapro_defconfig"
