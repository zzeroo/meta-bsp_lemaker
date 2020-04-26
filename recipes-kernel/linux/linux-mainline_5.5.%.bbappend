FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://fragment.cfg \
    file://0001-7inch-touchscreen.patch \
    file://0002-leds.patch \
    "
