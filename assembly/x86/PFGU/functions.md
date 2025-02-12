#  Functions

Small pieces of code that perform specialized tasks
that can be modified and individually tested.

Functions have:
* names.
* arguments.
* return values.

We must obey the calling convention of languages if we want to  
write code compatible with them.


# Stack

All functions use the stack to operate.

the top of the stack is actually the bottom memory wise  
because the stack grows downwards.

# calling functions

using the cdecl the functions are pushed onto the stack in reverse order
of declaration and call with also push the old base pointer and the return address

after the function starts we push ebp and set esp to ebp to use the passed arguments
``` bash
call function_name

.type function_name, @function
function_name:
pushl %ebp
movl %esp, %ebp

# here we can use ebp to access variables. Before we return
# we should pop everything we pushed and restore ebp
movl %ebp, %esp #restore the stack
pop %ebp
ret
```

stacklayout after a function call

|ret address  |
|:----------: |
|old ebp      |
|Arg 1(off 8) |
|Arg 2(off 12)|
|...|


### example

```text
int power(int base, int power)

push $base
push $power
call
```
now base is the furthest away for the stack top
that esp points to.

* to access it we need to jump 3 * sizeof(int) = 12  
* in order to make the stack bigger to hold the local variable  
* we use subl that will move the stack pointer downwards.
