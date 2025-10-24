bits 64
extern __errno_location
global ft_read
section .text

	ft_read:
		mov rax, 0
		syscall
		cmp rax, 0
		jl .set_errno
		ret

		.set_errno:
			neg rax
			push rax
			call __errno_location wrt ..plt
			pop rdi
			mov [rax], rdi
			mov rax, -1
			ret