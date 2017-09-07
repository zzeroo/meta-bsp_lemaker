require linux-bpro.inc
inherit linux-bananapro-base

DESCRIPTION = "Linux Kernel for Banana Pro"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

COMPATIBLE_MACHINE = "^bananapro$"

PE = "1"
PV = "${LINUX_VERSION}+git${SRCPV}"

KCONFIG_MODE = "--alldefconfig"
KBUILD_DEFCONFIG_bananapro ?= "sunxi_defconfig"

# CMDLINE for bananapro
CMDLINE ?= "console=ttyS0,115200 root=/dev/mmcblk0p2 rootwait panic=10 vt.global_cursor_default=0"

# Add the kernel debugger over console kernel command line option if enabled
CMDLINE_append = ' ${@base_conditional("ENABLE_KGDB", "1", "kgdboc=ttyS0,115200", "", d)}'

# Disable bananapro logo on boot
CMDLINE_append += ' ${@base_conditional("DISABLE_RPI_BOOT_LOGO", "1", "logo.nologo", "", d)}'

UDEV_GE_141 ?= "1"

# KERNEL_MODULE_AUTOLOAD += "${@bb.utils.contains("MACHINE_FEATURES", "pitft28r", "stmpe-ts", "", d)}"

# Set programmatically some variables during recipe parsing
# See http://www.yoctoproject.org/docs/current/bitbake-user-manual/bitbake-user-manual.html#anonymous-python-functions
python __anonymous () {
    kerneltype = d.getVar('KERNEL_IMAGETYPE')
    kerneldt = get_dts(d, d.getVar('LINUX_VERSION'))
    d.setVar("KERNEL_DEVICETREE", kerneldt)
}

# do_install_prepend() {
#     # install -d ${D}/lib/firmware
# }
#
# do_deploy_append() {
# }
