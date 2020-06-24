%include "x86_64_syscall.s"

section .text
	global ft_read
	extern __errno_location

ft_read:
	push rbp
	mov rbp, rsp
	
	mov rax, SYS_READ	; syscall id for read
	syscall
	cmp rax, 0			; check return
	jl return_invalid
	jmp return

return_invalid:
	neg rax				; abs value of return to get positiv errno
	mov r8, rax
	call __errno_location
	mov [rax], r8		; put syscall return value in errno int*
	xor rax, rax		; return -1
	dec rax

return:
	mov rsp, rbp
	pop rbp
	ret
