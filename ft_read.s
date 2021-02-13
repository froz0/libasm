global	ft_read
extern	__errno_location

ft_read:
	mov		rax, 0			; syscall a read
	syscall
	cmp		rax, 0			; rax < retour syscall
	jl		error			; go error rax < 0
	ret	

error:
	neg		rax			
	mov		rdi, rax		
	call	__errno_location wrt ..plt ; address -> rax
	mov		[rax], rdi		
	mov		rax, -1			
	ret
