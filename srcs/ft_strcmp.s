section .text
	global ft_strcmp

ft_strcmp:
	push rbp
	mov rbp, rsp
	jmp cmp_loop

next_char:
	inc rdi
	inc rsi

cmp_loop:
	cmp byte [rdi], 0		; check for 0 in source and dest
	jz end_loop
	cmp byte [rsi], 0
	jz end_loop
	mov r8b, [rsi]			; place dest byte in lower r12
	cmp r8b, [rdi]			; compare dest and src byte
	je next_char			; loop to increment pointer

end_loop:
	mov al, [rdi]			; end the loop at the end of source or dest 
	cmp al, [rsi]
	jne return_invalid

return_invalid:				; substract the two different char to get return value
	sub al, [rsi]
	movsx rax, al			; extend the sign to all the register
	jmp return

return_valid:
	xor rax, rax			; return 0 if no difference after reaching the first '\0

return:
	mov rsp, rbp
	pop rbp
	ret
