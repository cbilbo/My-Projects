global		_ft_strdup
extern		_malloc
extern		_ft_strcpy
extern		_ft_strlen


section		.text

_ft_strdup:
	cmp		rdi, 0
	je		.error
	push	rdi
	call	_ft_strlen
	inc 	rax
	mov		rdi, rax
	call	_malloc
	cmp		rax, 0
	jz		.error
	mov		rdi, rax
	pop		rsi
	call	_ft_strcpy
	ret

	.error:
		xor rax, rax
		ret