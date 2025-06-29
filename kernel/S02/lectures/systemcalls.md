# Systemcalls

    Application    
        -> setup information to identify the syscall (syscall num in eax) ->
            -> instruction for context switch + stack switch (user -> kernel)
                -> context (pt_regs) saved on stack  
                    -> enable_irqs  
                        -> execute syscall from syscall table.  
- Preemptive

Syscalls can have max 6 arguments passed.

The trap instruction is used to jump to an interrupt handler(ENTRY_POINT) that is saved in the idt.

An Interrupt frame is stored on the kernel stack by default and then the rest of the registers are pushed  
on the stack in order to restore from when returning back to userspace.  

There are some things that the kernel needs to do to verify arugments comming from userspace.

Pointers:
1. Never allow pointers to kernel-space
2. Check for invalid pointers

Approaches
1. Check the pointer against the user address space before using it, or
2. Avoid checking the pointer and rely on the **MMU** to detect when the pointer is invalid and use the page fault handler to determine that the pointer was invalid

Thats why the linux kernel uses the copy_to_user helpers that record all the instructions in a table that can be checked in an expection happens to determine the  
reason behind the exception.

### VDSO

With VDSO the system call interface is decided by the kernel:

1. a stream of instructions to issue the system call is generated by the kernel in a special memory area (formatted as an ELF shared object)
2. that memory area is mapped towards the end of the user address space
3. libc searches for VDSO and if present will use it to issue the system call


#### Resource:
[labs](https://linux-kernel-labs.github.io/refs/heads/master/so2/lec2-syscalls.html)
