	.section .data
	# Syscalls
	.equ SYS_OPEN, 5
	.equ SYS_WRITE, 4
	.equ SYS_READ, 3
	.equ SYS_CLOSE, 6
	.equ SYS_EXIT, 1

	.equ O_RDONLY, 0
	.equ O_CREAT_WRONGLY_TRUNC, 03101

	.equ STDIN, 0
	.equ STDOUT, 1
	.equ STDERR, 2

	.equ LINUX_SYSCALL, 0x80
	.equ EOF, 0
	.equ NUM_ARGUMENTS, 2

	.section .bss
	.equ BUFFER_SIZE, 500
	.lcomm BUFFER_DATA, BUFFER_SIZE # local common area (not global). .comm (global)

# function takes a block of memory and convert it to upper case, takes address and size

# block of codes that reads, converts and writes

# open the necessary files

	.section .text
	# STACK POSITIONS
	.equ ST_SIZE_RESERVE, 8
	.equ ST_FD_IN, -4
	.equ ST_FD_OUT, -8
	.equ ST_ARGC, 0		#number of arguments
	.equ ST_ARGV_0, 4	#name of program
	.equ ST_ARGV_1, 8	#input file name
	.equ ST_ARGV_2, 12	#output file name
	.globl _start
_start:
	movl %esp, %ebp
	subl $ST_SIZE_RESERVE, %esp # allocate space on the stack for the file descriptors

open_files:
open_fd_in:
	movl $SYS_OPEN, %eax
	movl ST_ARGV_1(%ebp), %ebx
	movl $O_RDONLY, %ecx
	movl $0666, %edx
	int $LINUX_SYSCALL

store_fd_in:
	# save the file descriptor
	movl %eax, ST_FD_IN(%ebp)

open_fd_out:
	movl $SYS_OPEN, %eax
	movl ST_ARGV_2(%ebp), %ebx
	movl $O_CREAT_WRONGLY_TRUNC, %ecx
	movl $0666, %edx
	int $LINUX_SYSCALL

store_fd_out:
	movl %eax, ST_FD_OUT(%ebp)


	# BEGIN MAIN LOOP #
read_loop_begin:
	movl $SYS_READ, %eax
	movl ST_FD_IN(%ebp), %ebx
	movl $BUFFER_DATA, %ecx
	movl $BUFFER_SIZE, %edx
	int $LINUX_SYSCALL

	# if we reached the end exit.
	cmpl $EOF, %eax
	jle end_loop

continue_read_loop:
	pushl $BUFFER_DATA
	pushl %eax
	;call convert_to_upper
	popl %eax
	addl $4, %esp

	;movl %eax, %edx
	;movl $SYS_WRITE, %eax
	;movl ST_FD_OUT(%ebp), %ebx
	;movl $BUFFER_DATA, %ecx
	;int $LINUX_SYSCALL
	jmp read_loop_begin

end_loop:
	# in
	movl $SYS_CLOSE, %eax
	movl ST_FD_IN(%ebp), %ebx
	int $LINUX_SYSCALL
	# out
	movl $SYS_CLOSE, %eax
	movl ST_FD_OUT(%ebp), %ebx
	int $LINUX_SYSCALL
	movl $SYS_EXIT, %eax
	movl $0, %ebx
	int $LINUX_SYSCALL


# Variables
#	eax - beggining of buffer
#	ebx - length of buffer
#	edi - current buffer offset
#	cl - current byte being examined

	.equ LOWERCASE_A, 'a'
	.equ LOWERCASE_Z, 'z'
	.equ UPPER_CONVERSION, 'A' - 'a'

	.equ ST_BUFFER_LEN, 8
	.equ ST_BUFFER, 12

convert_to_upper:
	pushl %ebp
	movl %esp, %ebp

	movl ST_BUFFER(%ebp), %eax
	movl ST_BUFFER_LEN(%ebp), %ebx
	xorl %edi, %edi

	cmpl $0, %ebx
	je end_convert_loop

convert_loop:
	movb (%eax, %edi, 1), %cl
	cmpb $LOWERCASE_A, %cl
	jl next_byte
	cmpb $LOWERCASE_Z, %cl
	jg next_byte

	addb $UPPER_CONVERSION, %cl
	movb %cl, (%eax, %edi, 1)
next_byte:
	incl %edi
	cmpl %edi, %ebx

	jne convert_loop

end_convert_loop:
	movl %ebp, %esp
	popl %ebp
	ret
