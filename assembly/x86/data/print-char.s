.section .data
my_char: .byte 'A'           # Declare a single character 'A'

.section .text
.global _start

_start:
    movl $4, %eax            # Syscall number for write
    movl $1, %ebx            # File descriptor (1 = stdout)
    leal my_char, %ecx       # Address of the character
    movl $1, %edx            # Length of data to write (1 byte)
    int $0x80                # Trigger the system call

    movl $1, %eax            # Syscall number for exit
    xorl %ebx, %ebx          # Exit status (0)
    int $0x80                # Trigger the system call
