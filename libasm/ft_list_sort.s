global		_ft_list_sort

extern		_ft_list_size

section		.text


_ft_list_sort:
	push		rdi
	push		rsi
	push		r15
	push		r14
	push		r13
	push		rbx
	push		rbp
	push		rcx
	push		rdx
	mov			r15, rdi
	mov			r14, rsi
	mov			rdi, [rdi]
	call		_ft_list_size
	mov			r13, rax
	cmp			r13, 0
	jz			.return
	cmp			r15, 0
	jz			.return
	cmp			r14, 0
	jz			.return

	xor			rcx, rcx
	jmp			.bubble

	.bubble:	inc	rcx
		cmp			rcx, r13
		jg			.return
		mov			rbx, [r15]
		cmp			rbx, 0
		jz			.return
		xor			rdx, rdx
		jmp			.check_next_el

		.check_next_el:
			mov			rbp, [rbx+8]
			cmp			rbp, 0
			jz			.bubble
			mov			rdi, [rbx]
			mov			rsi, [rbp]
			push		rbx
			push		rbp
			call		r14
			pop			rbp
			pop			rbx
			;mov			rdi, rbx
			;mov			rsi, rbp
			cmp			rax, 0
			jg			.sort
			mov			rbx, [rbx+8]
			jmp			.check_next_el


	.return:
		pop			rdx
		pop			rcx
		pop			rbp
		pop			rbx
		pop			r13
		pop			r14
		pop			r15
		pop			rsi
		pop			rdi
		ret


			.sort:
				push		r8
				push		r9
				mov			r8, [rbx]
				mov			r9, [rbp]
				mov			[rbx], r9
				mov			[rbp], r8
				pop			r9
				pop			r8
				mov			rbx, [rbx+8]
				jmp			.check_next_el







