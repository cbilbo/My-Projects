global		_ft_strcmp

section		.text

_ft_strcmp:
	push	rcx
	mov		rcx, -1


	.incr:	inc rcx
		mov		al, [rdi+rcx]
		mov		bl, [rsi+rcx]
		cmp		al, byte 0
		je		.return
		cmp		bl, byte 0
		je		.return
		cmp		al, bl
		jne		.return
		jmp		.incr

.return:
	sub		al, bl
	pop		rcx
	movsx	rax, al
	ret
