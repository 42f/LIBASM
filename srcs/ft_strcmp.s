section .text
	global ft_strcmp

next_char:
	inc rdi
	inc rsi

ft_strcmp:
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
	jne ret_not_equal
	xor eax, eax			; return 0 if no difference after reaching the first '\0'
	ret

ret_not_equal:				; substract the two different char to get return value
	sub al, [rsi]
	movsx rax, al			; extend the sign to all the register
	ret

