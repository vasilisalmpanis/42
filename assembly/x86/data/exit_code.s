	.section .data
num: .byte 0x1
num2: .byte 0x2

	.section .text
	.globl exit_code	
exit_code:
	mov num, %eax
	mov num2,%ebx
	mov $1, %eax
	int $0x80

