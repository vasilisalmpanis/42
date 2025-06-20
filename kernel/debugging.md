# Linux Kernel Debug.

1. Debuging the kernel with gdb  
[oracle article](https://blogs.oracle.com/linux/post/live-kernel-debugging-2)

2. Kprobes
[Example of kprobes](./kprobes.md)

> [!WARNING]
> The kernel has to be compiled with debug information for these methods to work.

3. Addr2line
```sh
addr2line -e module.o (0x5)offset
#offset is the instruction that caused the oops
```

4. objdump
```sh
sudo cat /pro/modules
# main 16384 1 - Loading 0xffffffffc1a61000 (OE+)

objdump -dS --adjust-vma=0xffffffffc1a61000 main.ko | less
# We get the lines that caused the oops and we can find that from the dmesg output.
```

5. gdb
```sh
gdb ./vmlinux
list *(do_panic+0x08)
```

6. ftrace
```sh
mount tracefs nodev /sys/kernel/debug/tracing

cd /sys/kernel/debug/tracing/
# set tracer
echo function > current_tracer
cat available_filter_functions | less # and choose the function
echo $function > set_ftrace_filter
echo 1 > tracing_on

cat trace | head -20
```
> [!IMPORTANT]
> you can also do it through a kernel module
> [ftrace](./ftrace.md)

[resources](https://linux-kernel-labs.github.io/refs/heads/master/so2/lec9-debugging.html)
[perf](https://www.brendangregg.com/perf.html)
