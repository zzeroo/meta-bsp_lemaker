# Base this image on bpro-basic-image
include bpro-basic-image.bb

COMPATIBLE_MACHINE = "^bananapro$"

IMAGE_INSTALL_append = " packagegroup-bpro-test"
