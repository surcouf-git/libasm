bits 64
global ft_strcpy
section .text

	ft_strcpy: ; char *ft_strcpy(char *restrict dst, const char *restrict src);
		xor rcx, rcx

		.null_check:
			test rsi, rsi
			jz .null_ret

		.loop:
			cmp byte [rsi + rcx], 0
			je .done
			mov rdx, byte [rsi + rcx]
			mov byte [rdi + rcx], rdx
			inc rcx
			jmp .loop

		.null_ret:
			mov rax, rdi
			jmp .done

		.done:
			ret

; section .note.GNU-stack noalloc noexec nowrite progbits