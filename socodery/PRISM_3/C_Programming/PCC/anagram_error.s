	.file	"anagram_error.c"
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.text
.Ltext0:
.globl g_error_level
	.data
	.align 4
	.type	g_error_level, @object
	.size	g_error_level, 4
g_error_level:
	.long	3
	.section	.rodata
.LC0:
	.string	"Unexpected End of File"
.LC1:
	.string	"Invalid Character"
.globl g_error_code_to_str
	.data
	.align 16
	.type	g_error_code_to_str, @object
	.size	g_error_code_to_str, 16
g_error_code_to_str:
	.quad	.LC0
	.quad	.LC1
	.section	.rodata
.LC2:
	.string	"Error : (%s)\n"
	.text
.globl ang_error
	.type	ang_error, @function
ang_error:
.LFB2:
	.file 1 "anagram_error.c"
	.loc 1 25 0
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	subq	$16, %rsp
.LCFI2:
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	.loc 1 30 0
	movl	-4(%rbp), %eax
	cmpl	g_error_level(%rip), %eax
	jg	.L1
	.loc 1 32 0
	movl	-8(%rbp), %eax
	cltq
	movq	g_error_code_to_str(,%rax,8), %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
.L1:
	.loc 1 34 0
	leave
	ret
.LFE2:
	.size	ang_error, .-ang_error
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
	.long	0x1a7
	.value	0x2
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.Ldebug_line0
	.quad	.Letext0
	.quad	.Ltext0
	.string	"GNU C 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
	.byte	0x1
	.string	"anagram_error.c"
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
	.long	0xff
	.uleb128 0x3
	.string	"char"
	.byte	0x1
	.byte	0x6
	.uleb128 0x5
	.long	0x154
	.byte	0x1
	.string	"ang_error"
	.byte	0x1
	.byte	0x19
	.byte	0x1
	.quad	.LFB2
	.quad	.LFE2
	.byte	0x1
	.byte	0x56
	.uleb128 0x6
	.string	"err_level"
	.byte	0x1
	.byte	0x17
	.long	0xdf
	.byte	0x2
	.byte	0x91
	.sleb128 -4
	.uleb128 0x6
	.string	"err_code"
	.byte	0x1
	.byte	0x18
	.long	0xdf
	.byte	0x2
	.byte	0x91
	.sleb128 -8
	.byte	0x0
	.uleb128 0x7
	.string	"g_error_level"
	.byte	0x1
	.byte	0x7
	.long	0xdf
	.byte	0x1
	.byte	0x9
	.byte	0x3
	.quad	g_error_level
	.uleb128 0x8
	.long	0x184
	.long	0xf9
	.uleb128 0x9
	.long	0xf2
	.byte	0x1
	.byte	0x0
	.uleb128 0x7
	.string	"g_error_code_to_str"
	.byte	0x1
	.byte	0x9
	.long	0x174
	.byte	0x1
	.byte	0x9
	.byte	0x3
	.quad	g_error_code_to_str
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
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x1
	.uleb128 0x13
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x9
	.uleb128 0x21
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,"",@progbits
	.long	0x46
	.value	0x2
	.long	.Ldebug_info0
	.long	0x1ab
	.long	0x107
	.string	"ang_error"
	.long	0x154
	.string	"g_error_level"
	.long	0x184
	.string	"g_error_code_to_str"
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
