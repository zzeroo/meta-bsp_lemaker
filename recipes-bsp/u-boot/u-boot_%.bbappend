# Force to version 2017.01
SRCREV = "a705ebc81b7f91bbd0ef7c634284208342901149"

FILESEXTRAPATHS_prepend := "${THISDIR}/u-boot:"

SRC_URI_append = " \
    file://0001-Bananapro_defconfig.patch \
    "

RDEPENDS_${PN}_append_bananapro = " bpro-u-boot-scr"
