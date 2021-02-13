bits 64
global		ft_strcpy

ft_strcpy:
	xor		rcx, rcx

copy_chars:
	cmp		byte [rsi + rcx], 0 ;rsi : 2nd parameter
	jz		return
	mov		dl, byte [rsi + rcx] ; dl is a space to store a byte
	mov		byte [rdi + rcx], dl
	inc		rcx
	jmp		copy_chars

return:
	mov		byte [rdi + rcx], 0 ; \0 a la fin du string
	mov		rax, rdi
	ret
