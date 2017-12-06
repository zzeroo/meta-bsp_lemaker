# mkimage -C none -A arm -T script -d boot.cmd boot.scr
bootdelay=0
# setenv bootargs quiet splash
setenv bootargs console=ttyS0,115200 root=/dev/mmcblk0p2 rootwait panic=10 vt.global_cursor_default=0 quiet splash
# load mmc 0:1 0x41000000 u-boot-splashscreen.bmp
setenv splashimage 41000000
# ${fdtfile} == sun7i-a20-bananapro.dtb
load mmc 0:1 0x43000000 ${fdtfile} || load mmc 0:1 0x43000000 boot/${fdtfile}
load mmc 0:1 0x42000000 zImage || load mmc 0:1 0x42000000 boot/zImage
fdt addr ${fdt_addr} && fdt get value bootargs /chosen bootargs
bootz 0x42000000 - 0x43000000
