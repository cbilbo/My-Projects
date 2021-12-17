global		_ft_strcpy

section		.text

_ft_strcpy:
	push	rdi
	push	rsi
	push	rcx
	mov		rcx, -1
	jmp		.incr

	.incr:	inc	rcx
		cmp		byte [rsi+rcx], 0
		jz		.return
		mov		al,  [rsi+rcx]
		mov		byte [rdi+rcx], al
		jmp		.incr

.return:
	mov		byte [rdi+rcx], 0
	pop		rcx
	pop		rsi
	pop		rdi
	mov		rax, rdi
	ret