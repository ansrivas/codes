	.file	"file1.c"
	.section	.rodata
.LC0:
	.string	"\na1 = %d\n"
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
	movl	$2, a1
	subl	$8, %esp
	pushl	a1
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	call	next
	subl	$8, %esp
	pushl	a1
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	call	next1
	subl	$8, %esp
	pushl	a1
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.comm	a1,4,4
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
