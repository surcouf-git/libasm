bits 64
global ft_strcmp
section .text

ft_strcmp:
	xor rcx, rcx
	cmp rdi, rsi
	je .equal

	.loop:
		mov al, [rdi + rcx]
		mov dl, [rsi + rcx]
		cmp al, dl
		jne .differ
		test al, al
		jz .equal
		inc rcx
		jmp .loop
		
	.differ:
		movzx eax, al
		movzx edx, dl
		sub eax, edx
		ret
		
	.equal:
		xor eax, eax
		ret