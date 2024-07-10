#ifndef KEYLOGGER_H
# define KEYLOGGER_H

# include <linux/module.h>
# include <linux/mutex.h>
# include <linux/miscdevice.h>
# include <linux/usb.h>
# include <linux/hid.h>
# include <linux/list.h>
# include <linux/interrupt.h>
# include <asm/io.h>

# define PL2_IRQ 1

# define KEYBOARD_PORT	0x60
# define CTRL_PORT	0x64
# define RELEASED_MASK	0x80

# define PRESSED 1
# define RELEASED 0
# define VOID -1

struct keyboard_entry {
    struct list_head list;
    // add other necessary fields here
};

#endif // !KEYLOGGER_H
