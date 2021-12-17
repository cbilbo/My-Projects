global		_ft_list_size

section		.text

_ft_list_size:
	mov		rcx, -1
	mov		rbx, rdi
	push	rdi

	.incr:	inc	rcx
		cmp	rbx, 0
		je	.return
		mov	rbx, [rbx+8]
		jmp	.incr

.return:
	pop	rdi
	mov rax, rcx
	ret