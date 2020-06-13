section .text
	global ft_strcmp

next_char:
	inc rdi
	inc rsi

ft_strcmp:
	cmp byte [rdi], 0
	jz end_loop
	cmp byte [rsi], 0
	jz end_loop
	mov r12b, [rsi]
	cmp r12b, [rdi]
	je next_char

end_loop:
	mov al, [rdi]
	sub al, [rsi]
	movsx eax, al
	ret
