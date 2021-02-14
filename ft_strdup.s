bits 64
global		ft_strdup
extern		ft_strlen
extern		ft_strcpy
extern		malloc

ft_strdup: ;char *ft_strdup(char *rdi);
	call	ft_strlen			; rax = ft_strlen(*s);
	push	rdi					; char *tmp = rdi;
	inc		rax					; rax++; pouur malloc strlen + 1
	mov		rdi, rax			; int rdi = rax
	call	malloc	wrt ..plt	; char *rax = malloc(rdi)
	cmp		rax, 0				; if (!rax) TF = 1
	jz		error				; error()
	mov		rdi, rax			; char *rdi = rax;
	pop		rsi					; char *rsi = tmp;
	call	ft_strcpy			; char *rax = ft_strcpy(rdi, rsi)
	ret							; return (rax)

error:
	ret							; return (rax)
