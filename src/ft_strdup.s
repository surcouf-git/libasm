bits 64

extern ft_strlen
extern malloc

global ft_strdup ; char *ft_strdup(const char *s1)

section .text
	ft_strdup:
		push rdi
		call ft_strlen wrt ..plt

		mov rdi, rax
		call malloc wrt ..plt

		pop rdi
		ret

section .note.GNU-stack