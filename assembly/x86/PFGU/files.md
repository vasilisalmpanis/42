# UNIX Files

As we already now UNIX systems handle everything in terms of files
that mean you can read everything as a sequence of bytes

UNIX contains some standard file descriptors.
```text
1. STDIN
2. STDOUT
3. STDERR
```
They are used for reading in what the user inputs and outputting it to the screen  
they can all be closed or dupped to some other file for example you could have input  
from a regular file on the disk.

### buffers
A contiguous memory block that is used to save elements. It could exist in the `.data` section  
or the `.bss` section as initialized to 0.

### .data vs .bss
The `.data` section is for values that will be initialized when the program is inserted and  
`.bss` is not actually included in the executable rather the OS at load time will initialize  
the memory at offset with specific size to zero.


#### Files for this chapter
1. [files.s](./files.s)
