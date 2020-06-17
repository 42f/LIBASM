section .text
	global ft_strcpy
	extern ft_strlen

ft_strcpy:

	push rdi
	push rsi
	mov rdi, rsi			;place rsi in rdi to make

	call ft_strlen			;the first arg for ft_strlen

	pop rsi
	pop rdi
	push rdi				;save rdi in stack to return it later

	inc rax					;inc rax (== len result) to include '\0'
	mov rcx, rax			;use len as counter for rep prefix
	rep movsb				;mov RCX bytes from rsi to rdi
	pop rax 				;pop the address of rdi into rax to return
	ret
