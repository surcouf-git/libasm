bits 64

%include 'ft_strlen.s'
%include 'ft_strcpy.s'

section .data
	message db "message de test", 0
	buffer db "buffer de test", 0
	other db 14	

section .text
	global _start

	_start:
		lea rdi, message
		call ft_strlen

		xor rax, rax
		lea rdi, message
		lea rsi, other
		call ft_strcpy

	exit:
		mov rdi, rax
		mov rax, 60
		syscall