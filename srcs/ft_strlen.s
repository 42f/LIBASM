section .text
	global ft_strlen

ft_strlen:
	push rbp
	mov rbp, rsp

	mov r8, rdi
	xor rax, rax	; set rax to 0 for scan instruction
	mov rcx, -1		; set rcx to max with all bits at 1
	repnz scasb		; let the cpu loop until ZF is set when meeting '\0'
	dec rdi			; dec of 1 memory block to move to the last char instead of the '\0'
	sub rdi, r8		; find the len by subtracting last char 
					;position to starting point of the string
	mov rax, rdi	; put it in rax for return
	
	mov rsp, rbp
	pop rbp
	ret
