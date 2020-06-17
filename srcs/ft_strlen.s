section .text
	global ft_strlen

ft_strlen:
	mov rax, rdi		; put string address in rax	

len_loop:				;loop until rax is on '\0' and only inc rax doing so
	cmp byte [rax], 0
	je end
	inc rax
	jmp len_loop

end:					;substract rdi address (stored in 
	sub rax, rdi
	ret
