#ifndef KEYLOGGER_H
# define KEYLOGGER_H

# include <linux/module.h>
# include <linux/mutex.h>
# include <linux/miscdevice.h>
# include <linux/usb.h>
# include <linux/hid.h>
# include <linux/list.h>
# include <linux/interrupt.h>
# include <linux/timekeeping.h>
# include <linux/workqueue.h>
# include <asm/io.h>


# define PL2_IRQ 1

# define KEYBOARD_PORT	0x60
# define CTRL_PORT	0x64
# define RELEASED_MASK	0x80

# define PRESSED 1
# define RELEASED 0
# define VOID -1

# define CB_SIZE 10000

# define MISC_SIZE 20

struct key_press {
	char			*name;
	u8			scancode;
	int			status;
	char			ascii;
	struct tm		tm;
	struct list_head	list;
};

struct scan_code {
	u8	scancode;
	char	*name;
};

#endif // !KEYLOGGER_H
