bits 64
global ft_strcpy
section .text

	ft_strcpy: ; char *ft_strcpy(char *restrict dst, const char *restrict src);
		xor rcx, rcx

		.null_check:
			cmp rsi, 0
			jz .null_ret

		.loop:
			mov al, [rsi + rcx]
			mov [rdi + rcx], al
			cmp byte [rsi + rcx], 0
			je .done
			inc rcx
			jmp .loop

		.null_ret:
			mov rax, rdi
			jmp .done

		.done:
			mov rax, rdi
			ret

; section .note.GNU-stack noalloc noexec nowrite progbits