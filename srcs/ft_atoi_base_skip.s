section .text
	global ft_atoi_base_skip_chars

ft_atoi_base_skip_chars:			; ##### SKIP ALL CHARS UNTIL SIGN OR DIGIT
	push rbp
	mov rbp, rsp

	cmp byte [rdi], 0			; check if rdi len > 0
	je return_invalid
	jmp check_loop

next_char:
	inc rdi

check_loop:						; skip if + - whitespace
	cmp byte [rdi], 33
	jl next_char
	cmp byte [rdi], 127
	je next_char
	cmp byte [rdi], '+'
	je next_char
	cmp byte [rdi], '-'
	je next_char

return_valid:					; reach only if not + - white space
	mov rax, rdi				; return rdi new address
	jmp return

return_invalid:
	xor rax, rax

return:
	mov rsp, rbp
	pop rbp
	ret	
