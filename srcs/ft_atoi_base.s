section .text
	global ft_atoi_base
	extern ft_check_base_validity

ft_atoi_base:
	cmp rdi, 0
	je return_error
	cmp rsi, 0
	je return_error

	push rdi
	push rsi
	mov rdi, rsi
	call ft_check_base_validity
	pop rsi
	pop rdi
	ret



	cmp rax, 1
	jne return_error


return_error:
	xor rax, rax
	dec rax
	ret
