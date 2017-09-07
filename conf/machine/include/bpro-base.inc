include conf/machine/include/bpro-default-settings.inc
include conf/machine/include/bpro-default-versions.inc
include conf/machine/include/bpro-default-providers.inc

IMAGE_FSTYPES ?= "tar.bz2 ext3 bpro-sdimg"

KERNEL_IMAGETYPE ?= "zImage"

MACHINE_FEATURES += "vfat ext2 touchscreen alsa bluetooth wifi sdio"

# Banana Pro has no hardware clock
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

MACHINE_EXTRA_RRECOMMENDS += " kernel-modules"

IMAGE_BOOT_FILES ?= " \
                 ${@bb.utils.contains('KERNEL_IMAGETYPE', 'zImage', '${KERNEL_IMAGETYPE}', '${KERNEL_IMAGETYPE};${SDIMG_KERNELIMAGE}', d)} \
                 ${@bb.utils.contains('KERNEL_IMAGETYPE', 'zImage', 'u-boot.bin;${SDIMG_KERNELIMAGE}', '', d)} \
                 ${@bb.utils.contains('KERNEL_IMAGETYPE', 'zImage', 'boot.scr;boot.scr', '', d)} \
                 "

# The kernel image is installed into the FAT32 boot partition and does not need
# to also be installed into the rootfs.
RDEPENDS_kernel-base = ""
