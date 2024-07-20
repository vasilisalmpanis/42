	section .text
	global	ft_strdup
	extern 	__errno_location
	extern 	malloc
	extern 	ft_strlen
	extern 	ft_strcpy
ft_strdup:
	; allocate for len + 1
	; check that malloc did not return null
	; copy everything to dest
	push	rdi
	call	ft_strlen wrt ..plt
	inc	rax
	mov	rdi, rax
	call	malloc wrt ..plt
	mov	rdi, rax
	pop	rsi
	call	ft_strcpy wrt ..plt
	ret

cleanup:
	pop	rdi
	ret

