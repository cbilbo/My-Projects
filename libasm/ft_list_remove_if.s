global		_ft_list_remove_if	; rdi = **begin_list, rsi = data_ref
								; rdx = cmp(list->data, data_ref), rcx = free_fct(data)
extern		_free

section		.text

_ft_list_remove_if:
	xor			rax, rax
	push		rsp
	push		r15
	push		r14
	push		r13
	push		r12
	mov			r15, rdi			;r15 = **begin_list
	push		rbx
	push		rbp
	mov			rbx, [rdi]			;rbx = *begin_list = list
	mov			r14, rsi			;r14 = data_ref
	mov			r13, rdx
	mov			r12, rcx
	push		rsi
	push		rcx
	push		rdx
	cmp			rdi, 0
	jz			.return
	cmp			rsi, 0
	jz			.return
	cmp			rdx, 0
	jz			.return
	cmp			rcx, 0
	jz			.return
	jmp			.check_list

	.check_list:
		cmp			rbx, 0
		jz			.check_first_list
		mov			rbp, [rbx+8]		;rbp = list->next
		cmp			rbp, 0
		jz			.check_first_list
		mov			rdi, [rbp]			;rdi = rbp->data
		mov			rdx, r13
		mov			rsi, r14
		push		rbx
		call		rdx
		pop			rbx
		cmp			rax, 0
		jz			.del_one
		mov			rbx, rbp
		jmp			.check_list

			.del_one:
				mov			rdi, [rbp]
				push		rdi
				call		r12
				pop			rdi
				push		r11
				mov			r11, [rbp+8]
				mov			[rbx+8], r11
				pop			r11
				mov			rdi, rbp
				push		rdi
				call		_free
				pop			rdi
				jmp			.check_list

	.check_first_list:
		mov			rbx, [r15]
		cmp			rbx, 0
		jz			.return
		mov			rbp, [rbx+8]
		mov			rdi, [rbx]
		mov			rsi, r14
		mov			rdx, r13
		push		rbx
		call		rdx
		pop			rbx
		cmp			rax, 0
		jne			.return
		mov			rdi, [rbx]
		push		rdi
		call		r12
		pop			rdi
		mov			rdi, rbx
		push		rdi
		call		_free
		pop			rdi
		mov			rbx, rbp
		jmp			.return


.return:
	mov			[r15], rbx
	mov			rdi, r15
	pop			rdx
	pop			rcx
	pop			rsi
	pop			rbp
	pop			rbx
	pop			r12
	pop			r13
	pop			r14
	pop			r15
	pop			rsp
	ret