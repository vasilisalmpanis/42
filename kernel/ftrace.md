# Ftrace

```C
#include <linux/ftrace.h>

struct ftrace_ops ops = {
      .func                    = my_callback_func,
      .flags                   = MY_FTRACE_FLAGS
      .private                 = any_private_data_structure,
};

void callback_func(unsigned long ip, unsigned long parent_ip,
                   struct ftrace_ops *op, struct pt_regs *regs);

static int __init init_func()
{
    ret = ftrace_set_filter(&ops, "schedule", strlen("schedule"), 0);

    /* To clear the filter
    *  ftrace_set_filter(&ops, NULL, 0, 1);
    *
    *  To set by ip if known.
    *  ret = ftrace_set_filter_ip(&ops, ip, 0, 0);
    */
    if (ret)
        return ret;
    register_ftrace_function(&ops);
    unregister_ftrace_function(&ops);
}
```

Protecting from recursive calls
```C
void callback_func(unsigned long ip, unsigned long parent_ip,
                   struct ftrace_ops *op, struct pt_regs *regs)
{
    int bit;

    bit = ftrace_test_recursion_trylock(ip, parent_ip);
    if (bit < 0)
        return;

    // In case of accessing RCU protected data
    if (!rcu_is_watching())
        return;

    // Your code

    ftrace_test_recursion_unlock(bit);
}
```

[Flags](https://docs.kernel.org/trace/ftrace-uses.html)
