bits 64

%include 'struct.s'

global ft_list_size

section .text
ft_list_size: ; int ft_list_size(t_list *begin_list);
	xor eax, eax
	test rdi, rdi
	jz .done

	.loop:
		inc eax
		mov rdi, [rdi + t_list.next]
		test rdi, rdi
		jz .done
		jmp .loop

	.done:
		ret
