bits 64
global ft_strcpy
section .text
ft_strcpy:

	cmp rdi, rsi
	je .return_as_is
	push rdi
	xor rcx, rcx

	.loop:
		mov al, [rsi + rcx]
		mov [rdi + rcx], al
		test al, al
		jz .done
		inc rcx
		jmp .loop
		
	.done:
		pop rax
		ret
		
	.return_as_is:
		mov rax, rdi
		ret