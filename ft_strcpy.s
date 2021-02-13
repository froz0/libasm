bits 64
global		ft_strcpy

ft_strcpy:
	xor		rcx, rcx

copy_chars:
	cmp		byte [rsi + rcx], 0
	jz		return
	mov		dl, byte [rsi + rcx]
	mov		byte [rdi + rcx], dl
	inc		rcx
	jmp		copy_chars

return:
	mov		byte [rdi + rcx], 0 ; \0 a la fin du string
	mov		rax, rdi
	ret
