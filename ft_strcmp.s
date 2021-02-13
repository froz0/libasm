bits 64
global		ft_strcmp

ft_strcmp:
	xor		rcx, rcx

cmp_str:
	mov		dl, byte [rdi + rcx]
	cmp		dl, 0
	jz		return
	cmp		dl, byte [rsi + rcx]
	jnz		return
	inc		rcx
	jmp		cmp_str
return:
	movzx		rax, BYTE[rdi + rcx]
	movzx		rdx, BYTE[rsi + rcx]
	sub			rax, rdx
	ret
