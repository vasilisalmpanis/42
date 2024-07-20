	section .text
	global ft_read
	extern __errno_location
ft_read:
	mov rax, 0
	syscall
	cmp rax, 0
	jl error
	ret

error:
	neg rax
	push rax
	call __errno_location wrt ..plt
	pop rcx
	mov [rax], rcx
	mov rax, -1
	ret
