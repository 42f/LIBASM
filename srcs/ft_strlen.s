section .text
	global ft_strlen

ft_strlen:
	mov rsi,rdi 		;store address of the argument (str) in rsi and rax
	mov rax, rdi		

len_loop:				;loop until rsi is on '\0' and only inc rsi doing so
	cmp byte [rsi], 0
	je end
	inc rsi
	jmp len_loop

end:					;substract the starting address stored in rax and the location of rsi (== '\0')
	sub rsi, rax
	mov rax, rsi		;mov the result in rax to return
	ret
