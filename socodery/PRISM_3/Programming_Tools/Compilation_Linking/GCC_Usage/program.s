	.file	"program.c"
.globl gsimple
	.bss
	.align 4
	.type	gsimple, @object
	.size	gsimple, 4
gsimple:
	.zero	4
.globl gcomplex
	.align 4
	.type	gcomplex, @object
	.size	gcomplex, 4
gcomplex:
	.zero	4
	.section	.rodata
.LC0:
	.string	"\nENTER complexlink function"
.LC1:
	.string	"\nlflag is equal to zero"
.LC2:
	.string	"\nlflag is different from zero"
.LC3:
	.string	"\nEXIT complexlink function"
	.text
.globl complexlink
	.type	complexlink, @function
complexlink:
.LFB2:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	subq	$16, %rsp
.LCFI2:
	movl	%edi, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	cmpl	$0, -4(%rbp)
	jne	.L2
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, gcomplex(%rip)
	movl	$1, -8(%rbp)
	jmp	.L3
.L2:
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$1, gcomplex(%rip)
	movl	$0, -8(%rbp)
.L3:
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	-8(%rbp), %eax
	leave
	ret
.LFE2:
	.size	complexlink, .-complexlink
	.section	.rodata
.LC4:
	.string	"\nENTER simplelink function"
.LC5:
	.string	"\nEXIT simplelink function"
	.text
.globl simplelink
	.type	simplelink, @function
simplelink:
.LFB3:
	pushq	%rbp
.LCFI3:
	movq	%rsp, %rbp
.LCFI4:
	subq	$16, %rsp
.LCFI5:
	movl	%edi, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	cmpl	$0, -4(%rbp)
	jne	.L5
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$1, gsimple(%rip)
	movl	$0, -8(%rbp)
	jmp	.L6
.L5:
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$0, gsimple(%rip)
	movl	$1, -8(%rbp)
.L6:
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	-8(%rbp), %eax
	leave
	ret
.LFE3:
	.size	simplelink, .-simplelink
	.section	.rodata
	.align 8
.LC6:
	.string	"\ngsimple before simplelink call: %d \n"
	.align 8
.LC7:
	.string	"\ngsimple after simplelink call: %d \n"
	.align 8
.LC8:
	.string	"\nreturn value from simplelink : %d \n"
	.align 8
.LC9:
	.string	"\ngcomplex before complexlink call: %d \n"
	.align 8
.LC10:
	.string	"\ngcomplex after complexlink call: %d \n"
	.align 8
.LC11:
	.string	"\nreturn value from complexlink : %d \n"
	.text
.globl main
	.type	main, @function
main:
.LFB4:
	pushq	%rbp
.LCFI6:
	movq	%rsp, %rbp
.LCFI7:
	subq	$16, %rsp
.LCFI8:
	movl	$1, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	-4(%rbp), %eax
	addl	%eax, gsimple(%rip)
	movl	gsimple(%rip), %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	-4(%rbp), %edi
	call	simplelink
	movl	%eax, -8(%rbp)
	movl	gsimple(%rip), %esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movl	-8(%rbp), %esi
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
	movl	gcomplex(%rip), %esi
	movl	$.LC9, %edi
	movl	$0, %eax
	call	printf
	movl	-4(%rbp), %edi
	call	complexlink
	movl	%eax, -8(%rbp)
	movl	gcomplex(%rip), %esi
	movl	$.LC10, %edi
	movl	$0, %eax
	call	printf
	movl	-8(%rbp), %esi
	movl	$.LC11, %edi
	movl	$0, %eax
	call	printf
	movl	-8(%rbp), %eax
	leave
	ret
.LFE4:
	.size	main, .-main
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	""
	.uleb128 0x1
	.sleb128 -8
	.byte	0x10
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 8
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.byte	0x4
	.long	.LCFI0-.LFB2
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE1:
.LSFDE3:
	.long	.LEFDE3-.LASFDE3
.LASFDE3:
	.long	.LASFDE3-.Lframe1
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.byte	0x4
	.long	.LCFI3-.LFB3
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI4-.LCFI3
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE3:
.LSFDE5:
	.long	.LEFDE5-.LASFDE5
.LASFDE5:
	.long	.LASFDE5-.Lframe1
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.byte	0x4
	.long	.LCFI6-.LFB4
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI7-.LCFI6
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE5:
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
