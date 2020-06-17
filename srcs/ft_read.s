section .text
	global ft_read
	extern error

ft_read:
	mov rax, 0
	syscall
	cmp rax, 0
	jl return_error
	ret

return_error:
	mov error, rax 
	mov rax, -1
	ret
