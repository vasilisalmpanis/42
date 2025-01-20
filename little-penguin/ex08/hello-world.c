// SPDX-License-Identifier: GPL-2.0
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Louis Solofrizzo <louis@ne02ptzero.me>");
MODULE_DESCRIPTION("Useless module");

char str[PAGE_SIZE + 1];
char *tmp;

static DEFINE_MUTEX(lock);

static ssize_t myfd_read(struct file *fp, char __user *user,
		size_t size, loff_t *offs)
{
	size_t t, i, ret_eval;

	tmp = kmalloc(PAGE_SIZE + 1, GFP_KERNEL);
	if (!tmp)
		return -ENOMEM;
	memset(tmp, 0, PAGE_SIZE + 1);

	mutex_lock(&lock);
	for (i = strlen(str) - 1, t = 0; i < strlen(str); i--, t++)
		tmp[t] = str[i];
	mutex_unlock(&lock);

	ret_eval = simple_read_from_buffer(user, size, offs, tmp, strlen(tmp));
	kfree(tmp);
	return ret_eval;
}

static ssize_t myfd_write(struct file *fp, const char __user *user,
		size_t size, loff_t *offs)
{
	ssize_t res;

	mutex_lock(&lock);
	res = simple_write_to_buffer(str, PAGE_SIZE, offs, user, size);
	str[size + 1] = '\0';
	mutex_unlock(&lock);
	return res;
}

static const struct file_operations myfd_fops = {
	.read = &myfd_read,
	.write = &myfd_write
};

static struct miscdevice myfd_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "reverse",
	.fops = &myfd_fops
};


static int __init myfd_init(void)
{
	int retval;

	retval = misc_register(&myfd_device);
	return 0;
}

static void __exit myfd_cleanup(void)
{
	misc_deregister(&myfd_device);
}

module_init(myfd_init);
module_exit(myfd_cleanup);
