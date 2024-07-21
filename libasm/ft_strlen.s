	section .text
	global ft_strlen
ft_strlen:
	xor rax, rax
next:
	cmp rdi, 0
	je close
	cmp [rdi], byte 0
	je close
	inc rax
	inc rdi
	jmp next

close:
	ret
