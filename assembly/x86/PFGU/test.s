.section .data
data_items:
	.long 3,5,55,45,32,65,30,0
.section .text
.globl _start
_start:
	xorl %edi, %edi				# zero out the edi register to use it as index.
	movl data_items(, %edi, 4), %eax	# Load to eax the value at data_items, index edi with size of 4 bytes
	movl %eax, %ebx				# move the first element to ebx
start_loop:
	cmpl $0, %eax				# compare eax with 0
	je loop_exit
	incl %edi 				# increment the index
	movl data_items(, %edi, 4), %eax	# jump one int and place the next into eax
	cmpl %eax, %ebx				# compare ebx with eax 
	jle start_loop				# if ebx >= eax, continue loop
	movl %eax, %ebx				# otherwise, update ebx with new maximum
	jmp start_loop				# continue looping
loop_exit:
	movl $1, %eax				# syscall number for exit
	int $0x80				# invoke syscall
