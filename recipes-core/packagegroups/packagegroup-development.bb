DESCRIPTION = "Development Packagegroup"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

inherit packagegroup

COMPATIBLE_MACHINE = "^bananapro$"

RDEPENDS_${PN} = "\
    vim \
    curl \
"

# RRECOMMENDS_${PN} = "\
#     bigbuckbunny-1080p \
#     bigbuckbunny-480p \
#     bigbuckbunny-720p \
#     ${MACHINE_EXTRA_RRECOMMENDS} \
# "
