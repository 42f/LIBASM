;    int ft_list_size(t_list *begin_list);
;								rdi

section .text
	global ft_list_size

ft_list_size:
	push rbp
	mov rbp, rsp
	xor rax, rax		; set return to 0
	cmp rdi, 0			; check if argument != NULL
	je return

next_elem:
	inc rax				; count the current element
	mov r12, [rdi + 8]
	cmp r12, 0			; check if next != NULL
	je return
	mov rdi, [rdi + 8]	; if not, move to next
	jmp next_elem	

return:
	mov rsp, rbp
	pop rbp
	ret
