; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *)	
;									rdi				rsi				rdx			rcx
;	(*cmp)(list_ptr->data, data_ref);
;	(*free_fct)(list_ptr->data)

section .text
	global ft_list_remove_if

ft_list_remove_if:
	push rbp
	mov rbp, rsp

	sub rsp, 32
	mov [rsp], rdx			; save to stack cmp function
	mov [rsp + 8], rcx		; save to stack free function
	mov [rsp + 16], rdi		; save to stack first element (head of list)
	mov [rsp + 24], rsi		; save to stack data_ref
	mov r12, [rdi]			; save current element to r12
	mov rdi, [rdi]			; dereference rdi to access first element

	jmp loop_in_list

go_next_elem:
	mov r12, rdi			; check if the current elem is the last ...
	cmp r13, 0
	je return
	mov rdi, r13			; ... if not, store the current to r13 to relink the list if the next has to be deleted

loop_in_list:
	mov r13, [rdi + 8]		; store next element's address
	mov rsi, [rsp + 24]		; reset data_ref for strcmp call
	mov r15, rdi			; store pointed address before dereferencing
	mov rdi, [rdi]			; dereferencing pointer

	call [rsp]				; strcmp rdi and rsi to know if the current element has to be removed
	mov rdi, r15			; get original address in rdi
	cmp rax, 0				; check strcmp result
	jne go_next_elem

	mov [r12 + 8], r13		; move the next in the previous one 
	call [rsp + 8]			; free_fct to free data from the current elem

	mov r14, [rsp + 16]		; if the current elem is the first of the list...
	cmp [r14], r15
	je reattache_head
	mov rdi, [rsp + 16]		; restart from the begining
	jmp go_next_elem

reattache_head:
	mov rax, [rsp + 16]		; ... then get the original pointer's address ...
	mov [rax], r13			; ... to dereference it to the value of the current element's "next"
	jmp go_next_elem			

return:
	mov rdi, [rsp + 16]
	add rsp, 32

	mov rsp, rbp
	pop rbp
	ret
