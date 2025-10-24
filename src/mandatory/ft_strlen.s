bits 64

global ft_strlen

section .text

	ft_strlen: ; size_t ft_strlen(const char *s);
		mov rax, 0
		.loop:
			cmp byte [rdi + rax], 0
			je .done
			inc rax
			jmp .loop

		.done:
			ret