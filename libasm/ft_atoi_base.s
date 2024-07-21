	global	ft_atoi_base
	global	checkbase
	extern	ft_strlen

checkbase:
	xor	rax, rax	;; start with clear counter
	cmp	rdi, 0		;; check for NULL pointer
	je	checkabase_end	
	call	ft_strlen	;; check that length is bigger than 1
	ret
checkabase_end:
	ret

ft_atoi_base:
	cmp	rdi, 0	
	je	close
	cmp	rsi, 0
	je	close
	push	rdi
	mov	rdi, rsi
	call	checkbase
	pop	rdi
	cmp	rax, 1
	jl	close
	ret


close:
	mov rax, 0
	ret

