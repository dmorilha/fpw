#####################################################
# Makefile
obj-m += mydrv.o
mydrv-objs := interface.o cppmod.o kernel_api.o
list-multi := mydrv.o
all: cppmod.o module
module:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
cppmod.o : cppmod.cpp new.h kernel_api.h cppmod.h
## variable expansion:
# $(CC) default Make's C compiler
# $@ target (in this case cppmod.o)
# $< first source (in this case cppmod.cpp)
	$(CC) -c -o $@ -mcmodel=kernel -fpermissive -fno-builtin -fno-exceptions -fno-rtti -nostdinc $<
