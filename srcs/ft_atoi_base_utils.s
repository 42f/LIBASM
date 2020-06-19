section .text
	global ft_check_base_validity

ft_check_base_validity:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rax, [rbp + 8]
	ret
