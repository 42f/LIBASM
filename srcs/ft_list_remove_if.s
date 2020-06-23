section .text
	global ft_list_remove_if

ft_list_remove_if:
	push rbp
	mov rbp, rsp


return:
	mov rsp, rbp
	pop rbp
	ret
