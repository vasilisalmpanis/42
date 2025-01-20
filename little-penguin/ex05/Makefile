# SPDX-License-Identifier: GPL-2.0

obj-m := hello-world.o

all:
	make -C /lib/modules/6.10.0-rc3-valmpani/build M=$(PWD) modules

clean:
	make -C /lib/modules/6.10.0-rc3-valmpani/build M=$(PWD) clean
