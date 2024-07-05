# SPDX-License-Identifier: GPL-2.0+
obj-m += drivers-and-interrupts.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
