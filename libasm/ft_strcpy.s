	section .text
	global ft_strcpy
	extern ft_strlen
ft_strcpy:
	mov rax, rdi
	cmp rsi, 0
	je close
next:
	mov r9b, [rsi]
	mov [rdi], r9b
	cmp r9b, 0
	je close
	inc rsi
	inc rdi
	jmp next
close:
	ret
