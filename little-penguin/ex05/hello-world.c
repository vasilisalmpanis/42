// SPDX-License-Identifier: GPL-2.0-only
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/device.h>
#include <linux/usb.h>
#include <linux/miscdevice.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A simple hello world kernel module");
MODULE_AUTHOR("valmpani");

static int cmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str2[i]) {
		if (str1[i] != str2[i])
			return -EINVAL;
		i++;
	}
	return i;
}

static int misc_device_open(struct inode *inode, struct file *file)
{
	pr_info("Misc device was opened\n");
	return 0;
}

static int misc_device_release(struct inode *inodep, struct file *filp)
{
	pr_info("Misc device was closed\n");
	return 0;
}

static ssize_t misc_device_read(struct file *file, char __user *buf,
		size_t len, loff_t *ppos)
{
	char username[20] = "valmpani\n";

	return simple_read_from_buffer(buf, len, ppos, username, 10);
}

static ssize_t misc_device_write(struct file *file, const char __user *buf,
		size_t len, loff_t *ppos)
{
	char kernel_buf[20];

	simple_write_to_buffer(kernel_buf, 19, ppos, buf, len);
	if (strlen(kernel_buf) > 9)
		return -EINVAL;
	if (cmp(kernel_buf, "valmpani") > 0)
		return len;
	else
		return -EINVAL;
}

static const struct file_operations fops = {
	.write		= misc_device_write,
	.read		= misc_device_read,
	.open		= misc_device_open,
	.release	= misc_device_release,
};

static struct miscdevice misc = {
	.minor	= MISC_DYNAMIC_MINOR,
	.name	= "fortytwo",
	.fops	= &fops
};

static int __init my_misc_init(void)
{
	int ret_eval;

	ret_eval = misc_register(&misc);
	if (ret_eval) {
		pr_err("Misc initialization failed\n");
		return ret_eval;
	}
	pr_info("Misc device initialized\n");
	return 0;
}

static void __exit my_misc_exit(void)
{
	misc_deregister(&misc);
	pr_info("Misc device deregistered\n");
}

module_init(my_misc_init);
module_exit(my_misc_exit);

