bits 128

extern ft_strlen
extern malloc

global ft_strdup ; char *ft_strdup(const char *s1)

section .text
	ft_strdup:
		push rdi
		call ft_strlen

		mov rdi, rax
		call malloc
		pop rdi
		ret