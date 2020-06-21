section .text
	global ft_atoi_base_convert
	extern ft_strchr
	extern ft_atoi_base_computation

ft_atoi_base_convert:		; ##### CONVERT STR TO INT, rdi = str, rsi = base, rdx = base_len 
	push rbp
	mov rbp, rsp

	push rdi
	push rsi

	xor rcx, rcx				; set rcx to zero, rcx = offset on str
	xor r8, r8					; set r8 to zero, r8 = char count on str, backwards
	xor r9, r9					; set r9 to zero, r9 = accumulation of icomputations, a.k.a the inal result
	jmp loop_get_str_end
	
next_char:
	inc rcx 

loop_get_str_end:
	cmp byte [rdi + rcx], 0 			; str is over if any of the following
	je get_first_position
	cmp byte [rdi + rcx], 33
	jl get_first_position 
	cmp byte [rdi + rcx], 127
	je get_first_position 
	cmp byte [rdi + rcx], '+'
	je get_first_position 
	cmp byte [rdi + rcx], '-'
	je get_first_position
	jmp next_char				; loop if any other char
	
get_first_position:
	dec rcx						; go back on last acceptable char on str

get_rank:						; find the current char's position in base to get rank
	push rcx					; calling convention for ft_strchr
	push rdi
	push rdx
	push rsi
	add rdi, rcx				; give ft_strchr the current char to be found in base
	call ft_strchr				; find position in base of current char in str

	pop rsi						; peek at rsi to reset address of str
	push rsi	
	cmp rax, 0					; check ft_strchr return, if 0, char not found in base
	je return_zero
	sub rax, rsi				; sub rax address (=location of char in base) - rsi (= start of base string) == rank in base
	
	mov rdi, rax				; first param = rank
	mov rsi, r8					; second param = position in str
								; third param already in place : rdx = base lenght
	call ft_atoi_base_computation
	add r9, rax					; accumulate result in r9 for final result
	pop rsi						; calling convention
	pop rdx
	pop rdi
	pop rcx
	
	inc r8						; increment char count
	dec rcx						; decement offset on str
	cmp rcx, 0					; check offset to stay in str
	jl return
	jmp get_rank
	
return_zero:
	xor rax, rax

return:
	mov rax, r9
	mov rsp, rbp
	pop rbp
	ret
