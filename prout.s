	.file	"main.c"
# GNU C17 (Ubuntu 13.3.0-6ubuntu2~24.04) version 13.3.0 (x86_64-linux-gnu)
#	compiled by GNU C version 13.3.0, GMP version 6.3.0, MPFR version 4.2.1, MPC version 1.3.1, isl version isl-0.26-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -O0 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.section	.rodata
.LC0:
	.string	"%d | %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$1024, %rsp	#,
# main.c:16: int main () {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp92
	movq	%rax, -8(%rbp)	# tmp92, D.4013
	xorl	%eax, %eax	# tmp92
# main.c:23: 	errno = 0;
	call	__errno_location@PLT	#
# main.c:23: 	errno = 0;
	movl	$0, (%rax)	#, *_1
# main.c:24: 	int result = ft_read(-1, buf, 999);
	leaq	-1008(%rbp), %rax	#, tmp88
	movl	$999, %edx	#,
	movq	%rax, %rsi	# tmp88,
	movl	$-1, %edi	#,
	call	ft_read@PLT	#
# main.c:24: 	int result = ft_read(-1, buf, 999);
	movl	%eax, -1012(%rbp)	# _2, result
# main.c:25: 	printf("%d | %d\n", result, errno);
	call	__errno_location@PLT	#
# main.c:25: 	printf("%d | %d\n", result, errno);
	movl	(%rax), %edx	# *_3, _4
	movl	-1012(%rbp), %eax	# result, tmp89
	movl	%eax, %esi	# tmp89,
	leaq	.LC0(%rip), %rax	#, tmp90
	movq	%rax, %rdi	# tmp90,
	movl	$0, %eax	#,
	call	printf@PLT	#
# main.c:26: 	return (0);
	movl	$0, %eax	#, _10
# main.c:27: }
	movq	-8(%rbp), %rdx	# D.4013, tmp93
	subq	%fs:40, %rdx	# MEM[(<address-space-1> long unsigned int *)40B], tmp93
	je	.L3	#,
	call	__stack_chk_fail@PLT	#
.L3:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4: