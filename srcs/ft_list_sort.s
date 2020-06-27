;	 void ft_list_sort(t_list **begin_list, int (*cmp)());
;									rdi			rsi

; r12 = stores the previous element (t_list *)
; r13 = current element (t_list *)
; r14 = next element (t_list *)
; r15 = data of current element (void *)

section .text
	global ft_list_sort

ft_list_sort:
	push rbp
	mov rbp, rsp

	cmp rdi, 0				; check all argument != NULL
	je return
	mov r12, [rdi]
	cmp r12, 0
	je return
	cmp rsi, 0
	je return

	sub rsp, 16				; CREATE SPACE ON STACK
	mov [rsp], rsi			; save to stack cmp function
	mov [rsp + 8], rdi		; save to stack first argument (= pointer to first element)

start_list:
							; SET REGISTERS
	mov r12, [rdi]			; save first element pointer to r12, will be replace by previous element in the loop
	mov r13, [rdi]			; save current element to r13
	mov r14, [r13 + 8]		; save next element's address in r14
	mov r15, [r13]			; dereference current element to access its data
	jmp cmp_loop

next_elem:
	mov r12, r13			; save current as previous
	mov r13, r14			; move to next
	mov r14, [r13 + 8]		; save next element's address in r14
	mov r15, [r13]
	cmp eax, 0
	jl relink_list

cmp_loop:
	cmp r14, 0
	je return
	mov rdi, [r14]			; dereference next elements in rsi to have its data
	mov rsi, r15			; mov current's data into rdi
	call [rsp]				; call cmp function
	jmp next_elem

relink_list:
	mov [r12 + 8], r14		; link previous elem with next elem

	mov rax, [rsp + 8]		; change current element's next value to first element of list
	mov rax, [rax]
	mov [r13 + 8], rax

	mov rax, [rsp + 8]		; update pointer to list start with current element
	mov [rax], r13

	mov rdi, [rsp + 8]		; start from the top and update rdi to reset all register
	jmp start_list	

return:
	mov rdi, [rsp + 8]
	add rsp, 16

	mov rsp, rbp
	pop rbp
	ret
