// SPDX-License-Identifier: GPL-2.0+

#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/miscdevice.h>
#include <linux/usb.h>
#include <linux/hid.h>
#include <linux/list.h>
#include <linux/interrupt.h>

MODULE_AUTHOR("valmpanis");
MODULE_DESCRIPTION("Keylogger");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

#define PL2_IRQ 1

static LIST_HEAD(keyboard_entry_list);

struct keyboard_entry {
    struct list_head list;
    // add other necessary fields here
};

//const char *id = "valmpani-keyboard";
DEFINE_MUTEX(keyboard_mutex);

static const struct usb_device_id usb_module_id_table[2] = {
	{ USB_INTERFACE_INFO(
			USB_INTERFACE_CLASS_HID,
			USB_INTERFACE_SUBCLASS_BOOT,
			USB_INTERFACE_PROTOCOL_KEYBOARD) },
	{}
};
MODULE_DEVICE_TABLE(usb, usb_module_id_table);

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

static irqreturn_t keyboard_handler(int irw, void *dev_id)
{
	pr_info("called\n");
	return IRQ_HANDLED;
}

static int driver_irq_reg(void)
{
	int ret;
	ret = request_irq(PL2_IRQ, &keyboard_handler, IRQF_SHARED, "Keyloggerrrrr", &keyboard_entry_list);
	if (ret < 0) {
		pr_err("Failed to register interrupt request handler\n");
		//list_del(&entry->list);
		//kfree(entry);
		return ret;
	}
	pr_info("Return value %d\n", ret);
	return 0;
}

static void driver_irq_unregister(void)
{
//	struct keyboard_entry *entry, *tmp;
//
//	list_for_each_entry_safe(entry, tmp, &keyboard_entry_list, list) {
//		pr_info("freeing nodes\n");
//		free_irq(PL2_IRQ, entry);
//		list_del(&entry->list);
//		kfree(entry);
//	}
//
//	pr_info("IRQ unregistered\n");
	free_irq(PL2_IRQ, &keyboard_entry_list);
}


static int __init main(void)
{
	int err;
	err = driver_irq_reg();
	if (err) {
		pr_err("IRQ failed\n");
		return -EFAULT;
	}
	misc_register(&keyboard_device);
	return 0;
}

static void __exit cleanup(void)
{
	driver_irq_unregister();
	misc_deregister(&keyboard_device);
	pr_info("cleanup\n");
}

module_init(main);
module_exit(cleanup);
