bits 64
%include "header/bonus/struct.s"
extern malloc
extern __errno_location
global ft_list_push_front
ft_list_push_front:
	xor rax, rax
	test rdi, rdi
	jz .done

	.create_new_node:
		push rdi
		push rsi
		push rdx
		mov rdi, t_list_size
		call malloc wrt ..plt
		pop rdx
		pop rsi
		pop rdi
		test rax, rax
		jz .set_errno
		mov qword [rax + t_list.data], rsi

	.check_head:
		mov rdx, [rdi]
		test rdx, rdx
		jz .head_is_null
		jmp .add_new_node

	.head_is_null:
		mov qword [rax + t_list.next], 0
		mov [rdi], rax
		jmp .done

	.add_new_node:
		mov qword [rdi], rax
		mov qword [rax + t_list.next], rdx
		jmp .done

	.set_errno:
		call __errno_location wrt ..plt
		mov dword [rax], 12
		jmp .done

	.done:
		ret