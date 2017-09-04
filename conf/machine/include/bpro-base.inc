include conf/machine/include/bpro-default-settings.inc
include conf/machine/include/bpro-default-versions.inc
include conf/machine/include/bpro-default-providers.inc

SOC_FAMILY = "bpro"
include conf/machine/include/soc-family.inc

IMAGE_FSTYPES ?= "tar.bz2 ext3 bpro-sdimg"

KERNEL_IMAGETYPE ?= "Image"

MACHINE_FEATURES += "vfat ext2 touchscreen alsa bluetooth wifi sdio"

# Banana Pro has no hardware clock
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

MACHINE_EXTRA_RRECOMMENDS += " kernel-modules"

def make_dtb_boot_files(d):
    # Generate IMAGE_BOOT_FILES entries for device tree files listed in
    # KERNEL_DEVICETREE.
    alldtbs = d.getVar('KERNEL_DEVICETREE')
    imgtyp = d.getVar('KERNEL_IMAGETYPE')

    def transform(dtb):
        if dtb.endswith('dtb'):
            # eg: whatever/bcm2708-rpi-b.dtb has:
            #     DEPLOYDIR file: ${KERNEL_IMAGETYPE}-bcm2708-rpi-b.dtb
            #     destination: bcm2708-rpi-b.dtb
            base = os.path.basename(dtb)
            src = '{}-{}'.format(imgtyp, base)
            dst = base
            return '{};{}'.format(src, dst)
        elif dtb.endswith('dtbo'):
            # overlay dtb:
            # eg: overlays/hifiberry-amp.dtbo has:
            #     DEPLOYDIR file: ${KERNEL_IMAGETYPE}-hifiberry-amp.dtbo
            #     destination: overlays/hifiberry-amp.dtbo
            base = os.path.basename(dtb)
            src = '{}-{}'.format(imgtyp, base)
            dst = dtb
            return '{};{}'.format(src, dtb)

    return ' '.join([transform(dtb) for dtb in alldtbs.split(' ') if dtb])


IMAGE_BOOT_FILES ?= " \
                 ${@make_dtb_boot_files(d)} \
                 ${@bb.utils.contains('KERNEL_IMAGETYPE', 'zImage', '${KERNEL_IMAGETYPE}', '${KERNEL_IMAGETYPE};${SDIMG_KERNELIMAGE}', d)} \
                 ${@bb.utils.contains('KERNEL_IMAGETYPE', 'zImage', 'u-boot.bin;${SDIMG_KERNELIMAGE}', '', d)} \
                 ${@bb.utils.contains('KERNEL_IMAGETYPE', 'zImage', 'boot.scr;boot.scr', '', d)} \
                 "

# The kernel image is installed into the FAT32 boot partition and does not need
# to also be installed into the rootfs.
RDEPENDS_kernel-base = ""
