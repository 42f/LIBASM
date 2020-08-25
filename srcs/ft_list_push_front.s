; 			 void	ft_list_push_front(t_list **begin_list, void *data);

section .text
	global ft_list_push_front
	extern malloc

ft_list_push_front:
	push rbp
	mov rbp, rsp
	
	cmp rdi, 0			; check if argument != NULL
	je return
	
	push rsi
	push rdi
	mov rdi, 16
	call malloc
	pop rdi
	pop rsi
	cmp rax, 0
	je return	
	mov r8, [rdi]		; first function arg in r8 to storage
	mov [rdi], rax		; malloced address from rax to rdi to change original pointer's value
	mov [rax], rsi		; store second function arg in data
	add rax, 8
	mov [rax], r8		; store original element's address in the new next
	jmp return

return:
	mov rsp, rbp
	pop rbp
	ret
