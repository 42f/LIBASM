section .text
	global ft_strchr

ft_strchr:			; ##### find char (=rdi) in string (=rsi) 
	push rbp
	mov rbp, rsp

	push rdi
	push rsi

	jmp check_loop

check_loop:
	cmp byte [rsi], 0
	je return_invalid
	mov cl, [rsi]
	cmp byte [rdi], cl 			; check similarity
	je return_valid
	inc rsi
	jmp check_loop	

return_invalid:
	xor rax, rax
	jmp return

return_valid:
	mov rax, rsi
	
return:
	pop rdi
	pop rdi
	mov rsp, rbp
	pop rbp
	ret	
