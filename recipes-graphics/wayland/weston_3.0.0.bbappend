FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI += "file://0001-fix-fbdev-backend.patch"


PR = "r1"

EXTRA_OECONF_append_bananapro = "\
		WESTON_NATIVE_BACKEND=fbdev-backend.so \
"
