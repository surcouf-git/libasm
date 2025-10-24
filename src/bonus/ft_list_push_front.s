bits 64
%include 'struct.s'
extern malloc
extern __errno_location
global ft_list_push_front
ft_list_push_front:
	xor rax, rax
	test rdi, rdi
	jz .done

	.create_new_node:
		push rdi
		mov rdi, t_list_size
		call malloc wrt ..plt
		pop rdi
		test rax, rax
		jz .set_errno

	.check_list:
		mov rdx, [rdi]
		test rdx, rdx
		jz .head_is_null
		jmp .add_new_node

	.head_is_null:
		mov [rdi], rax
		mov qword [rax + t_list.next], 0
		mov rdx, [rdi]
		mov qword [rdx + t_list.data], rsi
		jmp .done

	.add_new_node:
		mov rdx, [rdi]
		mov [rdx + t_list.data], rsi
		jmp .done

	.set_errno:
		call __errno_location wrt ..plt
		mov qword [rax], 12
		jmp .done

	.done:
		ret