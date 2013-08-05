	.file	"file3.c"
	.section	.rodata
.LC1:
	.string	"%d \n"
	.text
.globl next1
	.type	next1, @function
next1:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$0x41a26666, %eax
	movl	%eax, -4(%ebp)
	subl	$8, %esp
	pushl	a1
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	movl	$15, a1
	leave
	ret
	.size	next1, .-next1
	.comm	a1,4,4
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
