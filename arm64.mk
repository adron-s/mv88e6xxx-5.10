#cross compile для arm
#root
OPENWRT = /home/prog/openwrt/2022-openwrt/openwrt-2022
#где лежат бинарники компилятора(gcc, ldd)
#PATH := $(PATH):$(STAGING_DIR)/bin
#указываем архитекруту
export ARCH = arm64
export STAGING_DIR = ${OPENWRT}/staging_dir/toolchain-aarch64_cortex-a72_gcc-11.2.0_musl/
export CROSS_COMPILE = $(STAGING_DIR)/bin/aarch64-openwrt-linux-

#дальше все как обычно для модуля
#путь к исходнику ядра
KERNEL_DIR = ${OPENWRT}/build_dir/target-aarch64_cortex-a72_musl/linux-mvebu_cortexa72/linux-5.10.92
