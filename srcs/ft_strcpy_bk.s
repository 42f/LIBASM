section .text
	global ft_strcpy

ft_strcpy:
	mov rcx, 0
	push rdi

loop:
	mov dl, byte [rsi + rcx]
	cmp byte [rdi + rcx], 0
	je end
	inc rcx
	jmp loop	

end:
	pop rax
	ret
