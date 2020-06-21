section .text
	global ft_atoi_base
	extern ft_check_base_validity
	extern ft_skip_chars
	extern ft_convert
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
	
	call ft_check_base_validity
	pop rsi
	pop rdi
	cmp rax, 0
	je return_error
	
	call ft_skip_chars
	cmp rax, 0
	je return_error
	
	push rax
	mov rdi, rsi
	call ft_strlen
	mov rdx, rax

	pop rdi
	call ft_convert			; convert, takes rdi=str, rsi=base, rdx=base_len
	jmp return
	
return_valid:
	xor rax, rax
	inc rax
	jmp return	

return_error:
	xor rax, rax

return:
	mov rsp, rbp
	pop rbp
	ret
