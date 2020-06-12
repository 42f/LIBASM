section .text
	global ft_strcmp

ft_strcmp:
	jmp cmp_loop

inc_loop:
	inc rdi
	inc rsi

cmp_loop:
	repe cmp rsi, rdi
	ret	
;	jne exit_diff
;	cmp [rdi], 0
;	je exit
;	jmp inc_loop

;exit_diff:
;	mov rax, 
;	ret

;exit:
;	ret
