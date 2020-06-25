;	 void ft_list_sort(t_list **begin_list, int (*cmp)());
;									rdi			rsi

; r12 = stores the last undeleted element (t_list *)
; r13 = current element (t_list *)
; r14 = next element (t_list *)
; r15 = data of current element (void *)

section .text
	global ft_list_sort

ft_list_sort:
	ret



	push rbp
	mov rbp, rsp

	cmp rdi, 0				; check all argument != NULL
	je return
	mov r12, [rdi]
	cmp r12, 0
	je return
	cmp rsi, 0
	je return

	sub rsp, 32				; CREATE SPACE ON STACK
	mov [rsp], rdx			; save to stack cmp function
	mov [rsp + 8], rcx		; save to stack free function
	mov [rsp + 16], rdi		; save to stack first argument (= pointer to first element)
	mov [rsp + 24], rsi		; save to stack data_ref

							; SET REGISTERS
	mov r12, rdi			; save first element pointer to r12, will be replace by previous element in the loop
	mov r13, [rdi]			; save current element to r13
	mov r14, [r13 + 8]		; save next element's address in r14
	mov r15, [r13]			; dereference current element to access its data
	jmp cmp_loop

next_element:
	
	cmp r14, 0
	je return
	mov r13, r14			; move to next element address
	mov r14, [r13 + 8]		; save current's next element address in r14
	mov r15, [r13]			; dereferenc rdi to access its data

cmp_loop:
	mov rdi, r15			; put data in rdi for cmp function
	mov rsi, [rsp + 24]		; reset data_ref
	call [rsp]				; call cmp function
	cmp rax, 0
	je erase_data
	mov r12, r13			; set current element in r12 before moving to next one
	jmp next_element
	
erase_data:
	mov rdi, r15			; put data in rdi for free function
	call [rsp + 8]			; call the free_fct to free data
	cmp [rsp + 16], r12		; check if current element is the first of the list
	je reattache_first_element
	mov [r12 + 8], r14		; set next elemen in the previou's next pointer : shortcut the current
	mov rdi, r13			; set current element address in rdi for free function
;	call free				; free the element
	jmp next_element	

reattache_first_element:
	mov rax, [rsp + 16]		; get the pointer to the head of list
	mov [rax], r14			; change pointer content to make it point to current's next element
	mov rax, [rax]			; dereference it to access
	jmp next_element	

return:
	mov rdi, [rsp + 16]
	add rsp, 32

	mov rsp, rbp
	pop rbp
	ret
