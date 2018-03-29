DESCRIPTION = "Disables the mousepointer under weston"
HOMEPAGE = "https://zzeroo.com"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.GPLv2;md5=751419260aa954499f7abaabaa882bbe"
DEPENDS = "weston"
PR = "r0"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI = " \
		file://weston.ini \
		file://wallpaper-desktop-ra-gas.png \
"

do_install() {
	install -Dm0644 ${WORKDIR}/weston.ini ${D}/etc/xdg/weston/weston.ini
	install -Dm0644 ${WORKDIR}/wallpaper-desktop-ra-gas.png ${D}/usr/share/backgrounds/ra-gas/wallpaper-desktop-ra-gas.png
}

FILES_${PN} += "/etc/xdg/weston/weston.ini"
FILES_${PN} += "/usr/share/backgrounds/ra-gas/wallpaper-desktop-ra-gas.png"
