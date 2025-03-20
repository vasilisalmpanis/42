#
#	edi: holds the index
#	ebx: Largest data item found
#	eax: current item
	.section .text
	.globl _start
_start:
	xorl %edi, %edi				# zero out the edi register to use it as index.
.pushsection .data
data_items:
	.long 3,5,55,45,32,65,30,0
.popsection
	movl data_items(, %edi, 4), %eax	# Load to eax the value at data_items, index edi with size of 4 bytes
	movl %eax, %ebx				# move the first element to ebx

start_loop:
	cmpl $0, %eax				# compare eax with 0
	je loop_exit
	incl %edi 				# increment the index
	movl data_items(, %edi, 4), %eax	# jump one int and place the next into eax
	cmpl %ebx, %eax				# compare them, if ebx is <= eax we continue the loop otherwise we have a new max
	jle start_loop
	movl %eax, %ebx
	jmp start_loop				# continue looping

loop_exit:
	movl $1, %eax
	int $0x80
