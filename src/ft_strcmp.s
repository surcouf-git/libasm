bits 64

global ft_strcmp

section .text
	ft_strcmp: ; int ft_strcmp(const char *s1, const char *s2)
		xor rcx, rcx
		.loop:
			mov al, [rdi + rcx]
			cmp al, [rsi + rcx]
			jne .fail
			cmp al, 0
			je .done
			inc rcx
			jmp .loop

		.fail:
			sub al, [rsi + rcx]
			movsx eax, al
			ret
		
		.done:
			ret