# Base this image on bpro-hwup-image
include bpro-hwup-image.bb

IMAGE_FEATURES += "ssh-server-dropbear splash"
