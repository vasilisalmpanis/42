	.section .data

	.section .text
	.globl _start
	.globl factorial
_start:
	pushl $4		# first argument

	call factorial

	movl %eax, %ebx
	movl $1, %eax
	int $0x80

.type factorial,@function
factorial:
	pushl %ebp
	mov %esp, %ebp

	movl 8(%ebp), %eax
	cmpl $1, %eax
	je end_factorial
	decl %eax
	pushl %eax
	call factorial
	movl 8(%ebp), %ebx	# eax has the result of our operation so we restore the original value into ebx
	imull %ebx, %eax 	# we multiply the result of factorial and store in eax, which is where the results
				# of functions go

end_factorial:
	movl %ebp, %esp
	popl %ebp
	ret
