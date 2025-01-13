	.section .data
	# create a byte variable
list: .byte 'A', 'b', 'c'
string: .asciz "hello world\n"

	.section .text
	.globl _start
_start:
	movl $4, %eax   # use the `write` [interrupt-flavor] system call
	movl $1, %ebx   # write to stdout
	movl $string, %ecx # use string "Hello World"
	movl $12, %edx  # write 12 characters

	# make system call
	int $0x80

	movl $1, %eax   # use the `_exit` [interrupt-flavor] system call
	movl $0, %ebx   # error code 0
	int $0x80

# calling convetion on x86
# eax: syscall number
# ebx: first argument
# ecx: second argument
# edx: third argument

