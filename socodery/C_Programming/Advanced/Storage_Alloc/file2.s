	.file	"file2.c"
.globl b1
	.bss
	.align 4
	.type	b1, @object
	.size	b1, 4
b1:
	.zero	4
	.text
.globl next
	.type	next, @function
next:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movb	$97, -1(%ebp)
	movl	$77, b1
	leave
	ret
	.size	next, .-next
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
