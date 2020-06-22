section .text
	global ft_atoi_base
	extern ft_atoi_base_check_base
	extern ft_atoi_base_skip_chars
	extern ft_atoi_base_convert
	extern ft_strlen

ft_atoi_base:
	push rbp
	mov rbp, rsp

	cmp rdi, 0
	je return_error
	cmp rsi, 0
	je return_error

	push rdi
	push rsi
	mov rdi, rsi
	
	call ft_atoi_base_check_base
	pop rsi
	pop rdi
	cmp rax, 0
	je return_error
	
	call ft_atoi_base_skip_chars
	cmp rax, 0
	je return_error
	
	push rax
	mov rdi, rsi
	call ft_strlen
	mov rdx, rax

	pop rdi
	call ft_atoi_base_convert			; convert, takes rdi=str, rsi=base, rdx=base_len
	jmp return
	
return_error:
	xor rax, rax

return:
	mov rsp, rbp
	pop rbp
	ret
