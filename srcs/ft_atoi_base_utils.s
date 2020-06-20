section .text
	global ft_check_base_validity

ft_check_base_validity:
	push rbp
	mov r9, rsp
	mov rbp, rsp
	inc rbp				; inc rbp to start cmp in char set

	cmp byte [rdi], 0		; check if char set len >= 2
	je ret_error
	cmp byte [rdi + 1], 0
	je ret_error
	push 0				; push a zero to stop cmp loop

start:
	cmp byte [rdi], 0
	je ret_valid
	xor rcx, rcx		; set rcx to max value for repnz
	dec rcx

	mov al, [rdi]
	push ax		; push char set current char to stack

	mov rsi, rsp		; set repnz starting point at the last pushed char im stack
	inc rdi				; go to next chat set char
	mov r8, rdi			; save char set current position in r8
	repne cmpsb 		; cmp rdi and rsi until zero in the stack
	je ret_error
	mov rdi, r8			; set rdi back to its previous position on char set
	jmp start

	mov rsp, rbp
	pop rbp
	ret

ret_error:
	mov rsp, r9
	pop rbp
	xor rax, rax
	ret

ret_valid:
	mov rsp, rbp
	pop rbp
	xor rax, rax
	inc rax
	ret

	
