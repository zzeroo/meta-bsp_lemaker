SRCREV = "a705ebc81b7f91bbd0ef7c634284208342901149"

FILESEXTRAPATHS_prepend := "${THISDIR}/u-boot:"

SRC_URI_append = " \
    file://0001-Bananapro_defconfig.patch \
    "

RDEPENDS_${PN}_append_bpro = " bpro-u-boot-scr"

