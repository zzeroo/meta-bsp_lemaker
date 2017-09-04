# BananaPro BSP default providers

PREFERRED_PROVIDER_virtual/kernel ?= "linux-bananapro"
PREFERRED_PROVIDER_virtual/egl ?= "${@bb.utils.contains("MACHINE_FEATURES", "mesa", "userland", d)}"
PREFERRED_PROVIDER_virtual/libgles2 ?= "${@bb.utils.contains("MACHINE_FEATURES", "mesa", "userland", d)}"
PREFERRED_PROVIDER_virtual/libgl ?= "${@bb.utils.contains("MACHINE_FEATURES", "mesa", "mesa-gl", d)}"
PREFERRED_PROVIDER_virtual/mesa ?= "${@bb.utils.contains("MACHINE_FEATURES", "mesa", "mesa-gl", d)}"
PREFERRED_PROVIDER_libgbm ?= "${@bb.utils.contains("MACHINE_FEATURES", "mesa", "mesa-gl", d)}"
PREFERRED_PROVIDER_jpeg ?= "jpeg"
