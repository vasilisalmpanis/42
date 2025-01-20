// SPDX-License-Identifier: GPL-2.0-only
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/device.h>
#include <linux/usb.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A simple hello world kernel module");
MODULE_AUTHOR("valmpani");

static int __init usbkbd_init(void)
{
	pr_info("Keyboard plugged in\n");
	return 0;
}

static void __exit usbkbd_exit(void)
{
	pr_info("Keyboard unplugged\n");
}

module_init(usbkbd_init);
module_exit(usbkbd_exit);
