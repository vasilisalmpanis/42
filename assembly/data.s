	.section .data
	// declaring a variable
	// declaring a string
hello: .asciz "hello world"

	// list
list: .long 1,2,3,4

	// char
char: .byte 'a'
	//declaring a num of 4 bytes
num: .long 5
	.globl _start
	.section .text
_start:
	// convention we what is in the left in the register to the right
	// in nasm it is the opposite
	movl $1, %eax
	movl num, %ebx 
	int $0x80

