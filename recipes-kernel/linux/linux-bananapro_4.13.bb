inherit kernel
require recipes-kernel/linux/linux-yocto.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}_${PV}:"

LINUX_VERSION ?= "4.13"

SRCREV_machine="569dbb88e80deb68974ef6fdd6a13edb9d686261"
SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=git;nocheckout=1;name=machine"

LINUX_VERSION_EXTENSION_append = "-custom"

COMPATIBLE_MACHINE = "bananapro"

SRC_URI += "file://defconfig.cfg"
SRC_URI += "file://0001-touch.patch"
