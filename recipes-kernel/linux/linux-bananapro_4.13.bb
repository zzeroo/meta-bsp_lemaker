inherit kernel                                                                                                                                                                
require recipes-kernel/linux/linux-yocto.inc                                                                                                                                  
                                                                                                                                                                              
# Override SRC_URI in a copy of this recipe to point at a different source                                                                                                    
# tree if you do not want to build from Linus' tree.                                                                                                                          
SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=git;nocheckout=1;name=machine"                                                           
                                                                                                                                                                              
LINUX_VERSION ?= "4.6"                                                                                                                                                        
LINUX_VERSION_EXTENSION_append = "-custom"                                                                                                                                    
                                                                                                                                                                              
# Modify SRCREV to a different commit hash in a copy of this recipe to                                                                                                        
# build a different release of the Linux kernel.                                                                                                                              
# tag: v4.2 64291f7db5bd8150a74ad2036f1037e6a0428df2                                                                                                                          
SRCREV_machine="569dbb88e80deb68974ef6fdd6a13edb9d686261"                                                                                                                     

PE = "1"                                                                                                                                                                              
PV = "${LINUX_VERSION}+git${SRCPV}"                                                                                                                                           

KCONFIG_MODE = "--alldefconfig"
KBUILD_DEFCONFIG_bananapro ?= "sunxi_defconfig"
                                                                                                                                                                              
# Override COMPATIBLE_MACHINE to include your machine in a copy of this recipe                                                                                                
# file. Leaving it empty here ensures an early explicit build failure.                                                                                                        
COMPATIBLE_MACHINE = "bananapro" 

SRC_URI += "file://defconfig"
SRC_URI += "file://0001_touch-4.13.patch"