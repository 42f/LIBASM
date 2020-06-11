section .text
	global ft_strlen

ft_strlen:
	mov rsi,rdi 
	mov rax, 0

len_loop:
	mov cl, [rsi]
	cmp cl, 0
	je end
	inc rax
	inc rsi
	jmp len_loop

end:
	ret
