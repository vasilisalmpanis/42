// SPDX-License-Identifier: GPL-2.0+

#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/miscdevice.h>

MODULE_AUTHOR("valmpanis");
MODULE_DESCRIPTION("Keylogger");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

#define PL2_IRQ 1

//const char *id = "valmpani-keyboard";
DEFINE_MUTEX(keyboard_mutex);

static ssize_t misc_read(struct file *file, char __user *buf, size_t count, loff_t *off)
{
	return 0;
}

static ssize_t misc_write(struct file *file, const char __user *buf, size_t count, loff_t *off)
{
	return 0;
}

static int misc_open(struct inode *inode, struct file *file)
{
	mutex_lock(&keyboard_mutex);
	return 0;
}

static int misc_release(struct inode *inode, struct file *file)
{
	mutex_unlock(&keyboard_mutex);
	return 0;
}

static struct file_operations fops = {
	.read		= misc_read,
	.write		= misc_write,
	.open		= misc_open,
	.release	= misc_release
};

static struct miscdevice keyboard_device = {
	.minor		= MISC_DYNAMIC_MINOR,
	.name		= "valmpani-keyboard",
	.fops		= &fops,
};


static int __init main(void)
{
	misc_register(&keyboard_device);
	return 0;
}

static void __exit cleanup(void)
{
	misc_deregister(&keyboard_device);
	pr_info("cleanup\n");
}

module_init(main);
module_exit(cleanup);
