section .text
	global ft_atoi_base_computation

; ##### COMPUTES THE FINAL RESULT OF ATOI_BASE 
; first param = rdi = rank in base
; second param = rsi = position in str (starting at the end)
; third param = rdx = base lenght

ft_atoi_base_computation:
								
	push rbp
	mov rbp, rsp
	push r9

	mov r9, rdx
	xor rax, rax
	inc rax
	cmp rsi, 0
	je compute_zero_power

power_loop:
	mul r9
	dec rsi
	cmp rsi, 0
	jne power_loop
	jmp compute_value
	
compute_zero_power:
	mov rax, rdi
	jmp return

compute_value:
	mul rdi

return:
	pop r9
	mov rsp, rbp
	pop rbp
	ret	
