%include "x86_64_flags.s"

section .text
	global ft_strcmp

next_char:
	inc rdi
	inc rsi

ft_strcmp:
	cmp byte [rdi], 0		; check for 0 in source and dest
	jz end_loop
	cmp byte [rsi], 0
	jz end_loop
	mov r12b, [rsi]			; place dest byte in lower r12
	cmp r12b, [rdi]			; compare dest and src byte
	je next_char			; loop to increment pointer

end_loop:
	mov al, [rdi]			; end the loop at the end of source or dest 
	cmp al, [rsi]
	jne ret_not_equal
	xor rax, rax			; exit with zero if both string ended
	ret

ret_not_equal:
	pushfq					; push eflags to stack
	pop rax
	and rax, FLAG_SF		; get eflags in rax then logical AND to keep the SF
	cmp rax, 0
	je ret_one				; return -1 if SF is on	
	mov rax, -1
	ret

ret_one:
	mov rax, 1				; return +1 if SF is off
	ret
