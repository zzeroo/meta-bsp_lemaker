# Base this image on bpro-basic-image
include bpro-basic-image.bb

PR = "r11"

# Auto resize root filesystem on first boot
IMAGE_INSTALL += "resize-rootfs"

COMPATIBLE_MACHINE = "^bananapro$"

IMAGE_INSTALL_append = " packagegroup-development"
