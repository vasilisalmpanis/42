// SPDX-License-Identifier: GPL-2.0-only
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A simple hello world kernel module");
MODULE_AUTHOR("valmpani");

static int __init hello_init(void)
{
	pr_info("Hello world !\n");
	return 0;
}

static void __exit hello_exit(void)
{
	pr_info("Cleaning up module\n");
}

module_init(hello_init);
module_exit(hello_exit);
