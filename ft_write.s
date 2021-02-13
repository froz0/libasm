global	ft_write
extern	__errno_location

ft_write:
	mov		rax, 1			; syscall a write
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
