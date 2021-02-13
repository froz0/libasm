bits 64
global		ft_strlen	; On declare ft_strlen pour que
						; elle soit accessible de l'exterieur

ft_strlen:				;flag strlen sera call en premier puis en decendant
	xor		rcx, rcx

count_char:
						;cmp-> compare. byte dit que le saut se fait de 8 bit en 8 bit. rdi --> arg 1 rcx notre compteur. TF=1 si true
	cmp		byte [rdi + rcx], 0 
	jz		return		; saut saut a return si TF=1; TF est le resultat de l'operation cmp/ jmp conditionel
	inc		rcx			; incrementation de rcx/ rcx++
	jmp		count_char	; on jmp a count_char sans condition

return:
	mov		rax, rcx	; rax: valeur a retourner, rcx: notre compteur: on copy rcx -> rax
	ret					; return rax
