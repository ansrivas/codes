	.file	"ThreadArgs.c"
	.section	.rodata
.LC0:
	.string	"I am Thread %d\n"
	.text
.globl printme
	.type	printme, @function
printme:
.LFB2:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	subq	$16, %rsp
.LCFI2:
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %edi
	call	pthread_exit
.LFE2:
	.size	printme, .-printme
	.section	.rodata
.LC1:
	.string	"Creaing Thread\n"
.LC2:
	.string	"Printf Error Creating Thread"
	.text
.globl main
	.type	main, @function
main:
.LFB3:
	pushq	%rbp
.LCFI3:
	movq	%rsp, %rbp
.LCFI4:
	subq	$64, %rsp
.LCFI5:
	movl	$0, -52(%rbp)
.L3:
	cmpl	$4, -52(%rbp)
	jg	.L4
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	leaq	-52(%rbp), %rcx
	leaq	-48(%rbp), %rdx
	movl	-52(%rbp), %eax
	cltq
	salq	$3, %rax
	leaq	(%rdx,%rax), %rdi
	movl	$printme, %edx
	movl	$0, %esi
	call	pthread_create
	movl	%eax, -56(%rbp)
	cmpl	$0, -56(%rbp)
	je	.L5
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
.L5:
	leaq	-52(%rbp), %rax
	incl	(%rax)
	jmp	.L3
.L4:
	movl	$0, %edi
	call	pthread_exit
.LFE3:
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
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
