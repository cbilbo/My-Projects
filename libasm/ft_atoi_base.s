global		_ft_atoi_base

section		.text

_ft_atoi_base:
	push		rdi
	push		rsi
	push		rbx
	push		rcx
	push		r15
	push		r14
	push		r13
	push		r12
	push		r8
	push		r9
	push		r10
	xor			r10, r10
	mov			r15, rdi
	mov			r14, rsi
	cmp			rdi, 0
	jz			.return
	cmp			rsi, 0
	jz			.return
	mov			r13, -1
	mov			r8, 1
	jmp			.check_args

	.check_args:
		mov			r12, -1
		cmp			r13, -1
		je			.check_base
		cmp			r13, 2
		jl			.return
		jmp			.check_str

		.check_base:	inc r13
			mov			al, [r14+r13]
			cmp			al, 0
			jz			.check_args
			cmp			al, 32
			je			.return
			cmp			al, 43
			je			.return
			cmp			al, 45
			je			.return
			mov			r12, r13
			jmp			.cmp_symb

			.cmp_symb:		inc	r12
				mov			bl, [r14+r12]
				cmp			bl, 0
				jz			.check_base
				cmp			al, bl
				je			.return
				jmp			.cmp_symb

		.check_str:		inc r12
			mov			al, [r15+r12]	; 32 9 11 10 13 12
			cmp			al, 0
			je			.return
			cmp			al, 9
			je			.check_str
			cmp			al, 10
			je			.check_str
			cmp			al, 11
			je			.check_str
			cmp			al, 12		
			je			.check_str
			cmp			al, 13
			je			.check_str
			cmp			al, 32
			je			.check_str
			dec			r12
			jmp			.check_minus

			.check_minus:	inc r12
				mov			r9, r12
				mov			al, [r15+r12]
				cmp			al, 0
				jz			.return
				cmp			al, 43
				je			.check_minus
				cmp			al, 45
				jne			.cmp_args
				neg			r8
				jmp			.check_minus

				.cmp_args:	
					mov			rcx, -1
					mov			al, [r15+r12]
					cmp			al, 0
					jz			.base_number
					inc			r12
					jmp			.check_str_base

					.check_str_base:	inc rcx
						mov			bl, [r14+rcx]
						cmp			al, bl
						je			.cmp_args
						cmp			bl, 0
						jnz			.check_str_base
						dec			r12
						mov			rcx, -1
						jmp			.base_number

	.base_number:	inc	rcx
		cmp			r12, r9
		je			.is_negative
		mov			al, [r15+r9]
		mov			bl, [r14+rcx]
		cmp			al, 0
		jz			.is_negative
		cmp			al, bl
		jne			.base_number
		imul		r10, r13
		add			r10, rcx
		mov			rcx, -1
		inc			r9
		jmp			.base_number

		.is_negative:
			cmp			r8, 1
			je			.return
			neg			r10
			jmp			.return
	
	.return:
		mov			rax, r10
		pop			r10
		pop			r9
		pop			r8
		pop			r12
		pop			r13
		pop			r14
		pop			r15
		pop			rcx
		pop			rbx
		pop			rsi
		pop			rdi
		ret





















