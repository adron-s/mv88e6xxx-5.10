
#make по ':all' собирает сразу модули для x86 и mips
ifndef ARCH
  export ARCH = x86
  export KERNEL_DIR = /lib/modules/$(shell uname -r)/build
endif
ifeq ($(ARCH),arm64)
 include $(PWD)/../arm64.mk
endif

# standard flags for module builds
EXTRA_CFLAGS += -DLINUX -D__KERNEL__ -DMODULE -O2 -pipe -Wall

TARGET=marvell.o
obj-m:=$(TARGET)

TARGETS := $(obj-m:.o=.ko)
ccflags-y += -Wall


all:
#	make x86
	make -j24 arm64
#	make mips
#	make e2k
	@echo ""
	@echo -n "NC ready: "
	cat ./marvell.ko | nc -l -p 1111 -q 1

#CC := gcc -I/tmp/include

LINUX_UAPI_DIR = uapi/
LINUX_KARCH = $(ARCH)

# Use USERINCLUDE when you must reference the UAPI directories only.
#USERINCLUDE    := \
#		-I$(KERNEL_DIR)/arch/$(ARCH)/include/uapi \
#		-Iarch/$(ARCH)/include/generated/uapi \
#		-I$(KERNEL_DIR)/include/uapi \
#		-Iinclude/generated/uapi \
#                -include $(KERNEL_DIR)/include/linux/kconfig.h

#LINUXINCLUDE    := \
#		-I/tmp/include \
#		-I$(KERNEL_DIR)/arch/$(ARCH)/include \
#		-Iarch/$(ARCH)/include/generated/uapi \
#		-Iarch/$(ARCH)/include/generated \
#		-I$(KERNEL_DIR)/include \
#		-Iinclude \
#		$(USERINCLUDE)

arch:
	echo $(LINUXINCLUDE)
	$(MAKE) -C $(KERNEL_DIR) \
	V=1 M=$$PWD \
	modules

x86:
	$(MAKE) arch ARCH=x86

mips:
	$(MAKE) arch ARCH=mips

arm64:
	$(MAKE) arch ARCH=arm64

e2k:
	$(MAKE) arch ARCH=e2k

clean:		
		rm -f .*.cmd *.mod.c *.ko *.o *~ core $(TARGETS)
		rm -fr .tmp_versions .tmp_* Module.symvers modules.order *.mod
