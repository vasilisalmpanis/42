	section .text
	global ft_strcpy
	extern ft_strlen
ft_strcpy:
	mov rax, rdi
next:
	mov r9, [rsi]
	mov [rdi], r9
	cmp r9, 0
	je close
	inc rsi
	inc rdi
	jmp next
close:
	ret
