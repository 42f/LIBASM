section .text
	global ft_write

ft_write:
	mov rax, 1
	syscall
	cmp rax, 0
	jl return_error
	ret

return_error:
	mov rax, -1
	ret
