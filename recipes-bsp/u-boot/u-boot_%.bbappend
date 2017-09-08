FILESEXTRAPATHS_prepend := "${THISDIR}/u-boot:"

SRC_URI_append_bpro = " \
    file://0001-Bananapro_defconfig.patch \
    file://0002-sunxi-board.patch \
    "

RDEPENDS_${PN}_append_bananapro = " bpro-u-boot-scr"
