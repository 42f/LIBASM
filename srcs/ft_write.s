section .text
	global ft_write
	extern __errno_location

ft_write:
	mov rax, 1			; syscall id for write
	syscall
	cmp rax, 0			; check return
	jl return_error
	ret

return_error:
	neg rax				; get abs value of syscall return
	mov r8, rax			; store away return for later use
	call __errno_location		;get errno int* address to modify it
	mov [rax], r8
	mov rax, -1
	ret
