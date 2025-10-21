bits 64

global ft_strcpy
section .text
	ft_strcpy:
		xor rcx, rcx
		.loop:
			cmp byte [rsi + rcx], 0
			je .done
			mov rdx, [rsi + rcx]
			mov [rdi + rcx], rdx
			inc rcx
			jmp .loop
		.done:
			ret
section .note.GNU-stack noalloc noexec nowrite progbits