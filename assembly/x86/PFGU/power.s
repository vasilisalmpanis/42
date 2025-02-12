	.section .data

	.section .text
	.globl _start
_start:
	# Power takes 2 arguments, power and base
	pushl $0 # first argument
	pushl $3 # second argument
	call power
	add $8, %esp
	mov %eax, %ebx
	mov $1, %eax
	int $0x80

.type power, @function
power:
	pushl %ebp
	mov %esp, %ebp
	subl $4, %esp #save room for local variables
	movl 8(%ebp), %ebx # first argument
	movl 12(%ebp), %ecx # second argument

	movl %ebx, -4(%ebp) # store the first argument
	cmpl $0, %ecx
	je zero_power

power_loop_start:
	cmpl $1, %ecx
	je end_power
	movl -4(%ebp), %eax
	imull %ebx, %eax
	movl %eax, -4(%ebp)
	decl %ecx
	jmp power_loop_start

end_power:
	movl -4(%ebp), %eax
	movl %ebp, %esp
	popl %ebp
	ret
zero_power:
	movl %ebx, %eax
	movl %ebp, %esp
	popl %ebp
	ret
