global		_ft_list_push_front
extern		_malloc

section		.text

_ft_list_push_front:
	xor		rax, rax
	push 	rsp
	push	rdi
	push	rsi
	mov		rdi, 16
	call	_malloc
	cmp		rax, 0
	je		.return
	pop		rsi
	pop		rdi
	mov		[rax], rsi
	mov		rbx, [rdi]
	mov		[rax+8], rbx
	jmp		.return
		

.return:
	mov		[rdi], rax
	pop		rsp
	ret