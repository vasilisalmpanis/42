	section .text
	global ft_strcmp
ft_strcmp:
	xor rax, rax
next:
	mov r9b, [rdi]
	mov r10b, [rsi]
	cmp r9b, r10b
	jne close
	;;test r9b, r9b
	cmp r9b, byte 0
	je close
	inc rdi
	inc rsi
	jmp next


close:
	sub r9b, r10b
	movsx rax, r9b
	ret

