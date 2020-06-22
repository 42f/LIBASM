%include "x86_64_syscall.s"

section .text
	global ft_write
	extern __errno_location

ft_write:
	push rbp
	mov rbp, rsp

	mov rax, SYS_WRITE	; syscall id for write
	syscall
	cmp rax, 0			; check return
	jl return_invalid
	jmp return

return_invalid:
	neg rax				; get abs value of syscall return
	mov r8, rax			; store away return for later use
	call __errno_location		;get errno int* address to modify it
	mov [rax], r8
	xor rax, rax
	dec rax

return:
	mov rsp, rbp
	pop rbp
	ret
