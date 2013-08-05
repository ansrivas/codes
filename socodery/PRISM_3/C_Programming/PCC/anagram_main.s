	.file	"anagram_main.c"
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.text
.Ltext0:
	.section	.rodata
.LC0:
	.string	"Enter the target string:\n"
	.align 8
.LC1:
	.string	"Enter a test string (to exit just press ENTER key):\n"
.LC2:
	.string	"Result : It is an Anagram! \n"
	.align 8
.LC3:
	.string	"Result : Not an Anagram. Try again (to exit just press ENTER key)\n"
	.text
.globl main
	.type	main, @function
main:
.LFB2:
	.file 1 "anagram_main.c"
	.loc 1 33 0
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	subq	$192, %rsp
.LCFI2:
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	.loc 1 38 0
	cmpl	$1, -4(%rbp)
	jle	.L2
.LBB2:
	.loc 1 40 0
	movq	-16(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdi
	movl	$0, %eax
	call	atoi
	movl	%eax, %edi
	movl	$0, %eax
	call	set_trace_flag
.L2:
.LBE2:
	.loc 1 43 0
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	.loc 1 45 0
	leaq	-128(%rbp), %rdi
	movl	$100, %esi
	call	get_line
	.loc 1 46 0
	leaq	-160(%rbp), %rsi
	leaq	-128(%rbp), %rdi
	call	count_letters
	.loc 1 48 0
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
.L3:
	.loc 1 50 0
	leaq	-128(%rbp), %rdi
	movl	$100, %esi
	call	get_line
	testl	%eax, %eax
	je	.L4
	.loc 1 52 0
	leaq	-192(%rbp), %rsi
	leaq	-128(%rbp), %rdi
	call	count_letters
	.loc 1 54 0
	leaq	-192(%rbp), %rsi
	leaq	-160(%rbp), %rdi
	call	anagram_checker
	testl	%eax, %eax
	je	.L5
	.loc 1 55 0
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L3
.L5:
	.loc 1 57 0
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	jmp	.L3
.L4:
	.loc 1 60 0
	movl	$0, %eax
	.loc 1 61 0
	leave
	ret
.LFE2:
	.size	main, .-main
	.section	.debug_frame,"",@progbits
.Lframe0:
	.long	.LECIE0-.LSCIE0
.LSCIE0:
	.long	0xffffffff
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
.LECIE0:
.LSFDE0:
	.long	.LEFDE0-.LASFDE0
.LASFDE0:
	.long	.Lframe0
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
.LEFDE0:
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
	.text
.Letext0:
	.section	.debug_info
	.long	0x1db
	.value	0x2
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.Ldebug_line0
	.quad	.Letext0
	.quad	.Ltext0
	.string	"GNU C 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
	.byte	0x1
	.string	"anagram_main.c"
	.string	"/user/socodery/PRISM_3/C_Programming/PCC"
	.uleb128 0x2
	.long	.LASF0
	.byte	0x8
	.byte	0x7
	.uleb128 0x3
	.string	"unsigned char"
	.byte	0x1
	.byte	0x8
	.uleb128 0x3
	.string	"short unsigned int"
	.byte	0x2
	.byte	0x7
	.uleb128 0x3
	.string	"unsigned int"
	.byte	0x4
	.byte	0x7
	.uleb128 0x3
	.string	"signed char"
	.byte	0x1
	.byte	0x6
	.uleb128 0x3
	.string	"short int"
	.byte	0x2
	.byte	0x5
	.uleb128 0x3
	.string	"int"
	.byte	0x4
	.byte	0x5
	.uleb128 0x3
	.string	"long int"
	.byte	0x8
	.byte	0x5
	.uleb128 0x2
	.long	.LASF0
	.byte	0x8
	.byte	0x7
	.uleb128 0x4
	.byte	0x8
	.long	0xfe
	.uleb128 0x3
	.string	"char"
	.byte	0x1
	.byte	0x6
	.uleb128 0x5
	.long	0x1bc
	.byte	0x1
	.string	"main"
	.byte	0x1
	.byte	0x21
	.byte	0x1
	.long	0xde
	.quad	.LFB2
	.quad	.LFE2
	.byte	0x1
	.byte	0x56
	.uleb128 0x6
	.string	"argc"
	.byte	0x1
	.byte	0x20
	.long	0xde
	.byte	0x2
	.byte	0x91
	.sleb128 -4
	.uleb128 0x6
	.string	"argv"
	.byte	0x1
	.byte	0x20
	.long	0x1bc
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x7
	.string	"line"
	.byte	0x1
	.byte	0x22
	.long	0x1c2
	.byte	0x3
	.byte	0x91
	.sleb128 -128
	.uleb128 0x7
	.string	"target"
	.byte	0x1
	.byte	0x23
	.long	0x1d2
	.byte	0x3
	.byte	0x91
	.sleb128 -160
	.uleb128 0x7
	.string	"trial"
	.byte	0x1
	.byte	0x24
	.long	0x1d2
	.byte	0x3
	.byte	0x91
	.sleb128 -192
	.uleb128 0x8
	.quad	.LBB2
	.quad	.LBE2
	.uleb128 0x9
	.long	0x1aa
	.byte	0x1
	.string	"set_trace_flag"
	.byte	0x1
	.byte	0x28
	.long	0xde
	.byte	0x1
	.uleb128 0xa
	.byte	0x0
	.uleb128 0xb
	.byte	0x1
	.string	"atoi"
	.byte	0x1
	.byte	0x28
	.long	0xde
	.byte	0x1
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x4
	.byte	0x8
	.long	0xf8
	.uleb128 0xc
	.long	0x1d2
	.long	0xfe
	.uleb128 0xd
	.long	0xf1
	.byte	0x63
	.byte	0x0
	.uleb128 0xe
	.long	0xde
	.uleb128 0xd
	.long	0xf1
	.byte	0x4
	.byte	0x0
	.byte	0x0
	.section	.debug_abbrev
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x10
	.uleb128 0x6
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1b
	.uleb128 0x8
	.byte	0x0
	.byte	0x0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x4
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x5
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x1
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x7
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.byte	0x0
	.byte	0x0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x1
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0xa
	.uleb128 0x18
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0xb
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x1
	.uleb128 0x13
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0xe
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,"",@progbits
	.long	0x17
	.value	0x2
	.long	.Ldebug_info0
	.long	0x1df
	.long	0x106
	.string	"main"
	.long	0x0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0x0
	.value	0x0
	.value	0x0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0x0
	.quad	0x0
	.section	.debug_str,"",@progbits
.LASF0:
	.string	"long unsigned int"
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
