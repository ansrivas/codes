	.file	"test.c"
.globl j
	.data
	.align 4
	.type	j, @object
	.size	j, 4
j:
	.long	10
	.section	.rodata
.LC0:
	.string	"a is : %d"
.LC1:
	.string	"b is : %d"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	andl	$-16, %esp
	movl	$0, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	subl	%eax, %esp
	movl	$10, -4(%ebp)
	movl	$20, -8(%ebp)
	subl	$8, %esp
	pushl	-4(%ebp)
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	pushl	-8(%ebp)
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	leave
	ret
	.size	main, .-main
	.comm	p,4,4
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
