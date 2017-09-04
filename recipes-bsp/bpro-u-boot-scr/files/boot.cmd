# # mkimage -C none -A arm -T script -d boot.cmd boot.scr
# bootdelay=0
# setenv bootargs quiet splash
# # load mmc 0:1 0x41000000 u-boot-splashscreen.bmp
# setenv splashimage 41000000
# load mmc 0:1 0x43000000 ${fdtfile} || load mmc 0:1 0x43000000 boot/${fdtfile}
# load mmc 0:1 0x42000000 zImage || load mmc 0:1 0x42000000 boot/zImage
# bootz 0x42000000 - 0x43000000
fdt addr ${fdt_addr} && fdt get value bootargs /chosen bootargs
fatload mmc 0:1 ${kernel_addr_r} zImage
bootz ${kernel_addr_r} - ${fdt_addr}
