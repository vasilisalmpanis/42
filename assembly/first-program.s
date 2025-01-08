	.globl _start
	.section .text
_start: // start of execution
	// move long into eax   
	// in at&t syntax registers go with %
	// and literals need $1 otherwise they are treated as addresses
	movl $1, %eax 
	movl $1, %ebx     
	int $0x80        
