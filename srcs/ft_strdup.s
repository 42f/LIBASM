section .text
	global ft_strdup
	extern ft_strcpy
	extern ft_strlen
	extern malloc

ft_strdup:

	push rdi		;save rdi (== 1st function argument)
	call ft_strlen	;get len of rdi and increase it by one for malloc
	inc rax

	mov r8, rax	;save len to r8 for later use with ft_strcpy
	mov rdi, rax	;put len to malloc's 1st arg (==rdi)
	call malloc
	cmp rax, 0		;check malloc return
	je ret_error	
	
	mov rdi, rax	;place malloced pointer in ft_strcpy's src argument
	pop rsi			;give rdi to ft_strcpy dest argument
	push rsi		;save rsi to stack for later termination
	call ft_strcpy
	
	mov byte [rdi+r8], 0	;null-terminate string
	mov rax, rdi
	ret

ret_error:
	xor eax, eax
	ret
