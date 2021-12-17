global      _ft_strlen

section     .text
_ft_strlen:
    xor		rax, rax
    cmp     rdi, 0
    jz      .return

    .incr:
        cmp		[rdi+rax], byte 0
        je		.return
        inc		rax
        jmp		.incr

.return:
    ret