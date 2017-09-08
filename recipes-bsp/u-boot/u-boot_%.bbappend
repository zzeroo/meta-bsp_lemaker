FILESEXTRAPATHS_prepend := "${THISDIR}/u-boot:"

SRC_URI_append = " \
    file://0001-Bananapro_defconfig.patch \
    file://0002-sunxi-board.patch \
    "

RDEPENDS_${PN}_append_bpro = " bpro-u-boot-scr"

DEPENDS += "dtc"
