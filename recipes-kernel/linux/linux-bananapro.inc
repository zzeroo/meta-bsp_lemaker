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
