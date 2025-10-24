bits 64

extern ft_strlen
extern ft_strcpy
extern __errno_location
extern malloc
global ft_strdup ; char *ft_strdup(const char *s1)
section .text
ft_strdup:
	push rdi
	call ft_strlen

	inc rax
	mov rdi, rax
	call malloc wrt ..plt
	test rax, rax
	jz .set_errno

	pop rsi
	mov rdi, rax
	push rdi
	call ft_strcpy
	pop rdi
	ret

	.set_errno:
		call __errno_location wrt ..plt
		mov qword [rax], 12
		xor rax, rax
		ret