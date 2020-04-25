FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://0001-7inch-touchscreen.patch \
    file://0002-leds.patch \
    "
