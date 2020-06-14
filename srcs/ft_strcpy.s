section .text
	global ft_strcpy
	extern ft_strlen

ft_strcpy:
	mov r12, rdi
	push rdi
	push rsi
	call ft_strlen 
	pop rsi
	pop rdi
	push rdi
	inc rax
	mov rcx, rax
	rep movsq
	pop rax
	ret
