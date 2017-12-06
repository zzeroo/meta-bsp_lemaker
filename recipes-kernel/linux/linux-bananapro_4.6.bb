inherit kernel
require recipes-kernel/linux/linux-yocto.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}_${PV}:"

LINUX_VERSION ?= "4.6"

SRCREV = "a902836aade7b56f8dc31f50f9c6ca6d0fa01e45"
SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git"

SRC_URI += "file://defconfig.cfg"
SRC_URI += "file://0001-lcd.patch"
SRC_URI += "file://0002-led.patch"
SRC_URI += "file://0003-uart2.patch"
