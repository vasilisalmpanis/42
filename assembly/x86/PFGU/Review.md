# Chapter 2

## Review

* `#` is a comment
* assembly file holds the human readable equivalent of machine code.
* the linked takes the object files and combines it with other necessary libraries  
  to produce the executable.
* ```echo $?``` to check the exit code of the last executed program.
* ```movl $1, %eax``` immediate load value 1 to register eax  
  ```movl1 1, $eax``` load the address one to eax
* register `eax` holds the system call number
* when we access an element in an array, the computer needs to calculate the memory address of that element  
  thats why the start from 0, since the first element is at that address.
* 3634 + 13 * 4 = 3686
* GPR: `eax, ebx, ecx, edx, edi, esi`
* `movl` moves the full 32bits  
  `movb` moves the first byte
* conditional jumb: checks the EFLAGS and jumps.
* plan variables, procedures, how much storage we need, if we need extra memory or just registers are enough

