// SPDX-License-Identifier: GPL-2.0
#include <linux/module.h>
#include <linux/jiffies.h>
#include <linux/namei.h>
#include <linux/debugfs.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("valmpanis");
MODULE_DESCRIPTION("Task 07 from little-penguin-1");

#define DIR_NAME "fortytwo"

static DEFINE_MUTEX(foo_lock);

static char data_buffer[PAGE_SIZE + 1];

static struct dentry *fortytwo;

static char *username = "valmpani";

static int id_open(struct inode *inode, struct file *file)
{
	pr_info("Id was opened\n");
	return 0;
}
static int id_release(struct inode *inodp, struct file *filp)
{
	pr_info("Id was closed\n");
	return 0;
}
static ssize_t id_read(struct file *file, char __user *buf, size_t len, loff_t *offp)
{
	return simple_read_from_buffer(buf, len, offp, username, strlen(username));
}
static ssize_t id_write(struct file *file, const char __user *buf, size_t len, loff_t *offp)
{
	char kernel_buf[20];

	simple_write_to_buffer(kernel_buf, 19, offp, buf, len);
	if (strlen(kernel_buf) > 9)
		return -EINVAL;
	if (strcmp(kernel_buf, "valmpani") > 0)
		return len;
	else
		return -EINVAL;
}

static const struct file_operations fops = {
	.open = id_open,
	.release = id_release,
	.read = id_read,
	.write = id_write
};

static int foo_open(struct inode *inode, struct file *file)
{
	return 0;
}

static int foo_release(struct inode *inodp, struct file *filp)
{
	return 0;
}

static ssize_t foo_read(struct file *file, char __user *buf, size_t len, loff_t *offp)
{
	size_t ret;

	if (*offp >= strlen(data_buffer))
		return 0;
	mutex_lock(&foo_lock);
	ret = simple_read_from_buffer(buf, len, offp, data_buffer, strlen(data_buffer));
	mutex_unlock(&foo_lock);
	return ret;
}

static ssize_t foo_write(struct file *file, const char __user *buf, size_t len, loff_t *offp)
{
	size_t ret;

	mutex_lock(&foo_lock);
	memset(data_buffer, 0, PAGE_SIZE);
	ret = simple_write_to_buffer(data_buffer, PAGE_SIZE, offp, buf, len);
	mutex_unlock(&foo_lock);
	return ret;
}

static const struct file_operations foo_fops = {
	.open = foo_open,
	.release = foo_release,
	.read = foo_read,
	.write = foo_write
};

static int __init debug_init(void)
{
	memset(data_buffer, 0, PAGE_SIZE + 1);
	fortytwo = debugfs_create_dir(DIR_NAME, NULL);
	if (fortytwo == ERR_PTR(-ENODEV)) {
		pr_err("Debugfs is not enabled in the kernel\n");
		return -1;
	}
	debugfs_create_file("id", 0666, fortytwo, NULL, &fops);
	debugfs_create_u64("jiffies", 0444, fortytwo, (u64 *)&jiffies);
	debugfs_create_file("foo", 0644, fortytwo, NULL, &foo_fops);
	return 0;
}

static void __exit debug_exit(void)
{
	debugfs_remove_recursive(fortytwo);
	pr_info("Fortytwo directory removed\n");
}

module_init(debug_init);
module_exit(debug_exit);
