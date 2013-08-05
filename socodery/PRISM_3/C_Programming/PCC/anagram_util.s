	.file	"anagram_util.c"
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.text
.Ltext0:
.globl g_trace_level
	.data
	.align 4
	.type	g_trace_level, @object
	.size	g_trace_level, 4
g_trace_level:
	.long	1
	.section	.rodata
	.align 8
.LC0:
	.string	"set_trace_flag: trace flag set to %d\n"
	.text
.globl set_trace_flag
	.type	set_trace_flag, @function
set_trace_flag:
.LFB2:
	.file 1 "anagram_util.c"
	.loc 1 42 0
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	subq	$16, %rsp
.LCFI2:
	movl	%edi, -4(%rbp)
	.loc 1 43 0
	movl	-4(%rbp), %eax
	movl	%eax, g_trace_level(%rip)
	.loc 1 44 0
	cmpl	$2, g_trace_level(%rip)
	jle	.L1
	movl	g_trace_level(%rip), %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
.L1:
	.loc 1 45 0
	leave
	ret
.LFE2:
	.size	set_trace_flag, .-set_trace_flag
	.section	.rodata
	.align 8
.LC1:
	.string	"count_letters : function entered (%s)\n"
	.align 8
.LC2:
	.string	"count_letters : index = %d MAX = %d  \n"
	.align 8
.LC3:
	.string	"count_letters : Incrementing count for char %c \n"
	.align 8
.LC4:
	.string	"count_letters : Ignoring invalid character %c \n"
	.align 8
.LC5:
	.string	"count_letters : function exited\n"
	.text
.globl count_letters
	.type	count_letters, @function
count_letters:
.LFB3:
	.loc 1 66 0
	pushq	%rbp
.LCFI3:
	movq	%rsp, %rbp
.LCFI4:
	subq	$32, %rsp
.LCFI5:
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	.loc 1 67 0
	movl	$0, -20(%rbp)
	.loc 1 69 0
	cmpl	$2, g_trace_level(%rip)
	jle	.L4
	movq	-8(%rbp), %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
.L4:
	.loc 1 73 0
	movq	-16(%rbp), %rdi
	movl	$8, %edx
	movl	$0, %esi
	call	memset
.L5:
	.loc 1 75 0
	movq	-8(%rbp), %rax
	cmpb	$0, (%rax)
	je	.L6
	.loc 1 78 0
	movq	-8(%rbp), %rax
	movsbl	(%rax),%edi
	call	letter_index_converter
	movl	%eax, -20(%rbp)
	.loc 1 83 0
	cmpl	$2, g_trace_level(%rip)
	jle	.L7
	movl	-20(%rbp), %esi
	movl	$5, %edx
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
.L7:
	.loc 1 88 0
	cmpl	$0, -20(%rbp)
	js	.L8
	cmpl	$4, -20(%rbp)
	jg	.L8
	.loc 1 91 0
	cmpl	$2, g_trace_level(%rip)
	jle	.L9
	movq	-8(%rbp), %rax
	movsbl	(%rax),%esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
.L9:
	.loc 1 92 0
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-16(%rbp), %rax
	incl	(%rdx,%rax)
	jmp	.L10
.L8:
	.loc 1 96 0
	cmpl	$2, g_trace_level(%rip)
	jle	.L10
	movq	-8(%rbp), %rax
	movsbl	(%rax),%esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
.L10:
	.loc 1 99 0
	leaq	-8(%rbp), %rax
	incq	(%rax)
	jmp	.L5
.L6:
	.loc 1 102 0
	cmpl	$2, g_trace_level(%rip)
	jle	.L3
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
.L3:
	.loc 1 104 0
	leave
	ret
.LFE3:
	.size	count_letters, .-count_letters
	.section	.rodata
	.align 8
.LC6:
	.string	"letter_index_converter : function entered (%c)\n"
	.align 8
.LC7:
	.string	"letter_index_converter: Got invalid character %c \n"
	.text
.globl letter_index_converter
	.type	letter_index_converter, @function
letter_index_converter:
.LFB4:
	.loc 1 115 0
	pushq	%rbp
.LCFI6:
	movq	%rsp, %rbp
.LCFI7:
	subq	$16, %rsp
.LCFI8:
	movb	%dil, -1(%rbp)
	.loc 1 116 0
	cmpl	$2, g_trace_level(%rip)
	jle	.L14
	movsbl	-1(%rbp),%esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
.L14:
	.loc 1 118 0
	call	__ctype_b_loc
	movq	%rax, %rcx
	movsbq	-1(%rbp),%rax
	leaq	(%rax,%rax), %rdx
	movq	(%rcx), %rax
	movzwl	(%rdx,%rax), %eax
	shrl	$10, %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L15
	.loc 1 120 0
	movsbl	-1(%rbp),%eax
	subl	$65, %eax
	movl	%eax, -8(%rbp)
	jmp	.L13
.L15:
	.loc 1 124 0
	cmpl	$1, g_trace_level(%rip)
	jle	.L17
	movsbl	-1(%rbp),%esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
.L17:
	.loc 1 125 0
	movl	$1, %esi
	movl	$3, %edi
	call	ang_error
	.loc 1 127 0
	movl	$-1, -8(%rbp)
.L13:
	.loc 1 130 0
	movl	-8(%rbp), %eax
	leave
	ret
.LFE4:
	.size	letter_index_converter, .-letter_index_converter
	.section	.rodata
.LC8:
	.string	"get_line : Got Empty Line\n"
	.align 8
.LC9:
	.string	"get_line : Read the line [%s]\n"
.LC10:
	.string	"get_line : Returning \n"
	.text
.globl get_line
	.type	get_line, @function
get_line:
.LFB5:
	.loc 1 143 0
	pushq	%rbp
.LCFI9:
	movq	%rsp, %rbp
.LCFI10:
	subq	$48, %rsp
.LCFI11:
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	.loc 1 144 0
	movl	$0, -20(%rbp)
	movq	-16(%rbp), %rax
	movl	%eax, -24(%rbp)
	.loc 1 147 0
	movq	-8(%rbp), %rax
	movq	%rax, -32(%rbp)
.L19:
	.loc 1 149 0
	cmpq	$1, -16(%rbp)
	jbe	.L20
	call	getchar
	movl	%eax, -20(%rbp)
	cmpl	$-1, -20(%rbp)
	je	.L20
	cmpl	$10, -20(%rbp)
	je	.L20
	.loc 1 152 0
	movq	-8(%rbp), %rdx
	movl	-20(%rbp), %eax
	movb	%al, (%rdx)
	.loc 1 153 0
	leaq	-8(%rbp), %rax
	incq	(%rax)
	.loc 1 154 0
	leaq	-16(%rbp), %rax
	decq	(%rax)
	jmp	.L19
.L20:
	.loc 1 157 0
	movl	-24(%rbp), %eax
	cltq
	cmpq	-16(%rbp), %rax
	jne	.L21
	.loc 1 159 0
	cmpl	$1, g_trace_level(%rip)
	jle	.L22
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
.L22:
	.loc 1 160 0
	movl	$0, -36(%rbp)
	jmp	.L18
.L21:
	.loc 1 163 0
	cmpq	$0, -16(%rbp)
	je	.L23
	.loc 1 165 0
	movq	-8(%rbp), %rax
	movb	$0, (%rax)
.L23:
	.loc 1 168 0
	cmpl	$1, g_trace_level(%rip)
	jle	.L24
	movq	-32(%rbp), %rsi
	movl	$.LC9, %edi
	movl	$0, %eax
	call	printf
.L24:
	.loc 1 169 0
	cmpl	$2, g_trace_level(%rip)
	jle	.L25
	movl	$.LC10, %edi
	movl	$0, %eax
	call	printf
.L25:
	.loc 1 170 0
	movl	$1, -36(%rbp)
.L18:
	.loc 1 171 0
	movl	-36(%rbp), %eax
	leave
	ret
.LFE5:
	.size	get_line, .-get_line
	.section	.rodata
.LC11:
	.string	" anagram_checker entering \n"
	.align 8
.LC12:
	.string	" anagram_checker:Mismatch for index %d (%d Versus %d)\n"
	.align 8
.LC13:
	.string	" anagram_checker returned %d \n"
	.text
.globl anagram_checker
	.type	anagram_checker, @function
anagram_checker:
.LFB6:
	.loc 1 182 0
	pushq	%rbp
.LCFI12:
	movq	%rsp, %rbp
.LCFI13:
	subq	$32, %rsp
.LCFI14:
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	.loc 1 184 0
	movl	$0, -24(%rbp)
	.loc 1 186 0
	cmpl	$2, g_trace_level(%rip)
	jle	.L27
	movl	$.LC11, %edi
	movl	$0, %eax
	call	printf
.L27:
	.loc 1 188 0
	movl	$0, -20(%rbp)
.L28:
	cmpl	$4, -20(%rbp)
	jg	.L29
	.loc 1 191 0
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rsi
	movq	-8(%rbp), %rdi
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-16(%rbp), %rdx
	movl	(%rsi,%rdi), %eax
	cmpl	(%rcx,%rdx), %eax
	je	.L31
	.loc 1 194 0
	cmpl	$1, g_trace_level(%rip)
	jle	.L32
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-16(%rbp), %rax
	movl	(%rdx,%rax), %ecx
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-8(%rbp), %rax
	movl	(%rdx,%rax), %edx
	movl	-20(%rbp), %esi
	movl	$.LC12, %edi
	movl	$0, %eax
	call	printf
.L32:
	.loc 1 196 0
	movl	$0, -24(%rbp)
	.loc 1 197 0
	jmp	.L29
.L31:
	.loc 1 201 0
	movl	$1, -24(%rbp)
	.loc 1 188 0
	leaq	-20(%rbp), %rax
	incl	(%rax)
	jmp	.L28
.L29:
	.loc 1 205 0
	cmpl	$1, g_trace_level(%rip)
	jle	.L34
	movl	-24(%rbp), %esi
	movl	$.LC13, %edi
	movl	$0, %eax
	call	printf
.L34:
	.loc 1 206 0
	movl	-24(%rbp), %eax
	.loc 1 207 0
	leave
	ret
.LFE6:
	.size	anagram_checker, .-anagram_checker
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
.LSFDE2:
	.long	.LEFDE2-.LASFDE2
.LASFDE2:
	.long	.Lframe0
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
.LEFDE2:
.LSFDE4:
	.long	.LEFDE4-.LASFDE4
.LASFDE4:
	.long	.Lframe0
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
.LEFDE4:
.LSFDE6:
	.long	.LEFDE6-.LASFDE6
.LASFDE6:
	.long	.Lframe0
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.byte	0x4
	.long	.LCFI9-.LFB5
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI10-.LCFI9
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE6:
.LSFDE8:
	.long	.LEFDE8-.LASFDE8
.LASFDE8:
	.long	.Lframe0
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.byte	0x4
	.long	.LCFI12-.LFB6
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI13-.LCFI12
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE8:
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
.LSFDE7:
	.long	.LEFDE7-.LASFDE7
.LASFDE7:
	.long	.LASFDE7-.Lframe1
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.byte	0x4
	.long	.LCFI9-.LFB5
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI10-.LCFI9
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE7:
.LSFDE9:
	.long	.LEFDE9-.LASFDE9
.LASFDE9:
	.long	.LASFDE9-.Lframe1
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.byte	0x4
	.long	.LCFI12-.LFB6
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI13-.LCFI12
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE9:
	.file 2 "<internal>"
	.file 3 "/usr/lib/gcc/x86_64-redhat-linux/3.4.3/include/stddef.h"
	.text
.Letext0:
	.section	.debug_info
	.long	0x31a
	.value	0x2
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.Ldebug_line0
	.quad	.Letext0
	.quad	.Ltext0
	.string	"GNU C 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
	.byte	0x1
	.string	"anagram_util.c"
	.string	"/user/socodery/PRISM_3/C_Programming/PCC"
	.uleb128 0x2
	.string	"size_t"
	.byte	0x3
	.byte	0xd5
	.long	0x92
	.uleb128 0x3
	.long	.LASF0
	.byte	0x8
	.byte	0x7
	.uleb128 0x4
	.string	"unsigned char"
	.byte	0x1
	.byte	0x8
	.uleb128 0x4
	.string	"short unsigned int"
	.byte	0x2
	.byte	0x7
	.uleb128 0x4
	.string	"unsigned int"
	.byte	0x4
	.byte	0x7
	.uleb128 0x4
	.string	"signed char"
	.byte	0x1
	.byte	0x6
	.uleb128 0x4
	.string	"short int"
	.byte	0x2
	.byte	0x5
	.uleb128 0x4
	.string	"int"
	.byte	0x4
	.byte	0x5
	.uleb128 0x4
	.string	"long int"
	.byte	0x8
	.byte	0x5
	.uleb128 0x3
	.long	.LASF0
	.byte	0x8
	.byte	0x7
	.uleb128 0x5
	.byte	0x8
	.long	0x10c
	.uleb128 0x4
	.string	"char"
	.byte	0x1
	.byte	0x6
	.uleb128 0x6
	.byte	0x8
	.uleb128 0x7
	.long	0x155
	.byte	0x1
	.string	"set_trace_flag"
	.byte	0x1
	.byte	0x2a
	.byte	0x1
	.quad	.LFB2
	.quad	.LFE2
	.byte	0x1
	.byte	0x56
	.uleb128 0x8
	.string	"trace_val"
	.byte	0x1
	.byte	0x29
	.long	0xec
	.byte	0x2
	.byte	0x91
	.sleb128 -4
	.byte	0x0
	.uleb128 0x7
	.long	0x1ce
	.byte	0x1
	.string	"count_letters"
	.byte	0x1
	.byte	0x42
	.byte	0x1
	.quad	.LFB3
	.quad	.LFE3
	.byte	0x1
	.byte	0x56
	.uleb128 0x8
	.string	"str"
	.byte	0x1
	.byte	0x40
	.long	0x106
	.byte	0x2
	.byte	0x91
	.sleb128 -8
	.uleb128 0x8
	.string	"table"
	.byte	0x1
	.byte	0x41
	.long	0x1ce
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x9
	.string	"index"
	.byte	0x1
	.byte	0x43
	.long	0xec
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xa
	.byte	0x1
	.string	"memset"
	.byte	0x2
	.byte	0x0
	.byte	0x1
	.long	0x114
	.byte	0x1
	.uleb128 0xb
	.long	0x114
	.uleb128 0xb
	.long	0xec
	.uleb128 0xb
	.long	0x92
	.byte	0x0
	.byte	0x0
	.uleb128 0x5
	.byte	0x8
	.long	0xec
	.uleb128 0xc
	.long	0x217
	.byte	0x1
	.string	"letter_index_converter"
	.byte	0x1
	.byte	0x73
	.byte	0x1
	.long	0xec
	.quad	.LFB4
	.quad	.LFE4
	.byte	0x1
	.byte	0x56
	.uleb128 0x8
	.string	"c"
	.byte	0x1
	.byte	0x72
	.long	0x10c
	.byte	0x2
	.byte	0x91
	.sleb128 -1
	.byte	0x0
	.uleb128 0xc
	.long	0x28b
	.byte	0x1
	.string	"get_line"
	.byte	0x1
	.byte	0x8f
	.byte	0x1
	.long	0xec
	.quad	.LFB5
	.quad	.LFE5
	.byte	0x1
	.byte	0x56
	.uleb128 0x8
	.string	"buf"
	.byte	0x1
	.byte	0x8d
	.long	0x106
	.byte	0x2
	.byte	0x91
	.sleb128 -8
	.uleb128 0x8
	.string	"len"
	.byte	0x1
	.byte	0x8e
	.long	0x84
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x9
	.string	"c"
	.byte	0x1
	.byte	0x90
	.long	0xec
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x9
	.string	"temp_len"
	.byte	0x1
	.byte	0x90
	.long	0xec
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x9
	.string	"input"
	.byte	0x1
	.byte	0x91
	.long	0x106
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.byte	0x0
	.uleb128 0xc
	.long	0x2fd
	.byte	0x1
	.string	"anagram_checker"
	.byte	0x1
	.byte	0xb6
	.byte	0x1
	.long	0xec
	.quad	.LFB6
	.quad	.LFE6
	.byte	0x1
	.byte	0x56
	.uleb128 0x8
	.string	"table1"
	.byte	0x1
	.byte	0xb5
	.long	0x1ce
	.byte	0x2
	.byte	0x91
	.sleb128 -8
	.uleb128 0x8
	.string	"table2"
	.byte	0x1
	.byte	0xb5
	.long	0x1ce
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x9
	.string	"index"
	.byte	0x1
	.byte	0xb7
	.long	0xec
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x9
	.string	"match"
	.byte	0x1
	.byte	0xb8
	.long	0xec
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.byte	0x0
	.uleb128 0xd
	.string	"g_trace_level"
	.byte	0x1
	.byte	0x1d
	.long	0xec
	.byte	0x1
	.byte	0x9
	.byte	0x3
	.quad	g_trace_level
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
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x3
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
	.uleb128 0x4
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
	.uleb128 0x5
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x7
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
	.uleb128 0x8
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
	.uleb128 0x9
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
	.uleb128 0xa
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
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0xb
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xc
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
	.uleb128 0xd
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
	.byte	0x0
	.section	.debug_pubnames,"",@progbits
	.long	0x81
	.value	0x2
	.long	.Ldebug_info0
	.long	0x31e
	.long	0x116
	.string	"set_trace_flag"
	.long	0x155
	.string	"count_letters"
	.long	0x1d4
	.string	"letter_index_converter"
	.long	0x217
	.string	"get_line"
	.long	0x28b
	.string	"anagram_checker"
	.long	0x2fd
	.string	"g_trace_level"
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
