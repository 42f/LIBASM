section .text
	global ft_check_base_validity
	global ft_skip_chars

ft_check_base_validity:			; ##### CHECK THE VALIDITY OF BASE
	push rbp
	mov rbp, rsp

	cmp byte [rdi], 0			; check if base len >= 2
	je return_invalid
	cmp byte [rdi + 1], 0
	je return_invalid

next_char:						; check if base is not over
	mov al, [rdi]

	cmp al, 0
	je return_valid				; if yes it means loop compared every char

	cmp al, '+'
	je return_invalid			; base can't contain + or -
	
	cmp al, '-'
	je return_invalid			; base can't contain + or -

	cmp al, 127
	je return_invalid			; base can't contain white spaces

	cmp al, ' '
	jle return_invalid

	xor rcx, rcx				; reset i = 0 
	
check_loop:						; loop starts
	inc rcx						; i += 1
	
	cmp al, [rdi + rcx]
	je return_invalid			; return error if two char are equal
	
	cmp byte [rdi + rcx], 0
	jne check_loop
	inc rdi						; move to next char in base
	jmp next_char
	

return_valid:
	xor rax, rax
	inc rax	
	jmp return

return_invalid:
	xor rax, rax

return:
	mov rsp, rbp
	pop rbp
	ret	
