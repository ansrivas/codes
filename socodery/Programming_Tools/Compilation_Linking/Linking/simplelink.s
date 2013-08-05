	.file	"simplelink.c"
	.section	".rodata"
	.align 8
.LLC0:
	.asciz	"\nENTER complexlink function"
	.align 8
.LLC1:
	.asciz	"\nlflag is equal to zero"
	.align 8
.LLC2:
	.asciz	"\nlflag is different from zero"
	.align 8
.LLC3:
	.asciz	"\nEXIT complexlink function"
	.section	".text"
	.align 4
	.global complexlink
	.type	complexlink,#function
	.proc	04
complexlink:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%g0, [%fp-20]
	sethi	%hi(.LLC0), %o0
	or	%o0, %lo(.LLC0), %o0
	call	printf, 0
	 nop
	ld	[%fp+68], %o0
	cmp	%o0, 0
	bne	.LL2
	nop
	sethi	%hi(.LLC1), %o0
	or	%o0, %lo(.LLC1), %o0
	call	printf, 0
	 nop
	sethi	%hi(gcomplex), %o0
	or	%o0, %lo(gcomplex), %o0
	st	%g0, [%o0]
	mov	1, %o0
	st	%o0, [%fp-20]
	b	.LL3
	 nop
.LL2:
	sethi	%hi(.LLC2), %o0
	or	%o0, %lo(.LLC2), %o0
	call	printf, 0
	 nop
	sethi	%hi(gcomplex), %o0
	or	%o0, %lo(gcomplex), %o1
	mov	1, %o0
	st	%o0, [%o1]
	st	%g0, [%fp-20]
.LL3:
	sethi	%hi(.LLC3), %o0
	or	%o0, %lo(.LLC3), %o0
	call	printf, 0
	 nop
	ld	[%fp-20], %o0
	mov	%o0, %i0
	nop
	ret
	restore
.LLfe1:
	.size	complexlink,.LLfe1-complexlink
	.section	".rodata"
	.align 8
.LLC4:
	.asciz	"\nENTER simplelink function"
	.align 8
.LLC5:
	.asciz	"\nEXIT simplelink function"
	.section	".text"
	.align 4
	.global simplelink
	.type	simplelink,#function
	.proc	04
simplelink:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%g0, [%fp-20]
	sethi	%hi(.LLC4), %o0
	or	%o0, %lo(.LLC4), %o0
	call	printf, 0
	 nop
	ld	[%fp+68], %o0
	cmp	%o0, 0
	bne	.LL5
	nop
	sethi	%hi(.LLC1), %o0
	or	%o0, %lo(.LLC1), %o0
	call	printf, 0
	 nop
	sethi	%hi(gsimple), %o0
	or	%o0, %lo(gsimple), %o1
	mov	1, %o0
	st	%o0, [%o1]
	st	%g0, [%fp-20]
	b	.LL6
	 nop
.LL5:
	sethi	%hi(.LLC2), %o0
	or	%o0, %lo(.LLC2), %o0
	call	printf, 0
	 nop
	sethi	%hi(gsimple), %o0
	or	%o0, %lo(gsimple), %o0
	st	%g0, [%o0]
	mov	1, %o0
	st	%o0, [%fp-20]
.LL6:
	sethi	%hi(.LLC5), %o0
	or	%o0, %lo(.LLC5), %o0
	call	printf, 0
	 nop
	ld	[%fp-20], %o0
	mov	%o0, %i0
	nop
	ret
	restore
.LLfe2:
	.size	simplelink,.LLfe2-simplelink
	.common	gsimple,4,4
	.common	gcomplex,4,4
	.ident	"GCC: (GNU) 3.2"
