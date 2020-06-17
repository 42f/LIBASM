%ifndef X86_64_MACROS
 %define X86_64_MACROS
; FT_PUTSTR_FD, arg 1 is string, arg 2 is fd

%macro ft_putstr_fd 2
	ft_strlen %1		
	push rax

	mov rax, SYS_WRITE
	mov rdi, %2
	mov rsi, %1
	pop rdx
	syscall
%endmacro


; FT_STRLEN

%macro ft_strlen 1
	mov rax, 0
	mov rsi, %1

%%len_loop:
	mov cl, [rsi]
	cmp cl, 0
	je %%end
	inc rax
	inc rsi
	jmp %%len_loop

%%end:
%endmacro

; SYS_CALL EXIT CLEANER

%macro exit 1
	mov rax, SYS_EXIT
	mov rdi, %1
	syscall
%endmacro

%endif
