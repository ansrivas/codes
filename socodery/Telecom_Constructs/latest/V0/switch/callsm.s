	.file	"callsm.c"
	.section	".text"
	.align 4
	.global getsubscriberevent
	.type	getsubscriberevent,#function
	.proc	012
getsubscriberevent:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %i0
	ld	[%i0], %i0
	nop
	ret
	restore
.LLfe1:
	.size	getsubscriberevent,.LLfe1-getsubscriberevent
	.section	".rodata"
	.align 8
.LLC0:
	.asciz	"packet reading failed"
	.align 8
.LLC1:
	.asciz	"message parsing failed"
	.section	".text"
	.align 4
	.global handleoriginatingcall
	.type	handleoriginatingcall,#function
	.proc	012
handleoriginatingcall:
	!#PROLOGUE# 0
	save	%sp, -280, %sp
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	mov	1, %o0
	st	%o0, [%fp-20]
	mov	1, %o0
	st	%o0, [%fp-184]
	ld	[%fp+68], %o0
	st	%o0, [%fp-180]
.LL3:
	add	%fp, -88, %o1
	ld	[%fp-180], %o0
	call	receivepacket, 0
	 nop
	st	%o0, [%fp-20]
	ld	[%fp-20], %o0
	cmp	%o0, 0
	bne	.LL6
	nop
	sethi	%hi(.LLC0), %o0
	or	%o0, %lo(.LLC0), %o0
	call	perror, 0
	 nop
	b	.LL4
	 nop
.LL6:
	add	%fp, -88, %o0
	add	%fp, -152, %o1
	call	createmessagefrompacket, 0
	 nop
	st	%o0, [%fp-20]
	ld	[%fp-20], %o0
	cmp	%o0, 0
	bne	.LL7
	nop
	sethi	%hi(.LLC1), %o0
	or	%o0, %lo(.LLC1), %o0
	call	perror, 0
	 nop
	b	.LL4
	 nop
.LL7:
	add	%fp, -152, %o0
	call	getsubscriberevent, 0
	 nop
	st	%o0, [%fp-156]
	ld	[%fp-156], %o0
	cmp	%o0, 4
	bleu	.LL8
	nop
	mov	3, %o0
	st	%o0, [%fp-156]
.LL8:
	ld	[%fp-184], %o0
	cmp	%o0, 5
	bgu	.LL9
	nop
	ld	[%fp-184], %o0
	sll	%o0, 2, %o1
	sethi	%hi(.LL64), %o0
	or	%o0, %lo(.LL64), %o0
	ld	[%o1+%o0], %o0
	jmp	%o0
	 nop
.LL10:
	ld	[%fp-156], %o0
	cmp	%o0, 4
	bgu	.LL9
	nop
	ld	[%fp-156], %o0
	sll	%o0, 2, %o1
	sethi	%hi(.LL17), %o0
	or	%o0, %lo(.LL17), %o0
	ld	[%o1+%o0], %o0
	jmp	%o0
	 nop
.LL12:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL13:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL14:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL15:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL16:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL19:
	ld	[%fp-156], %o0
	cmp	%o0, 4
	bgu	.LL9
	nop
	ld	[%fp-156], %o0
	sll	%o0, 2, %o1
	sethi	%hi(.LL26), %o0
	or	%o0, %lo(.LL26), %o0
	ld	[%o1+%o0], %o0
	jmp	%o0
	 nop
.LL21:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL22:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	callanswer, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL23:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL24:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL25:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL28:
	ld	[%fp-156], %o0
	cmp	%o0, 4
	bgu	.LL9
	nop
	ld	[%fp-156], %o0
	sll	%o0, 2, %o1
	sethi	%hi(.LL35), %o0
	or	%o0, %lo(.LL35), %o0
	ld	[%o1+%o0], %o0
	jmp	%o0
	 nop
.LL30:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL31:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL32:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL33:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL34:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL37:
	ld	[%fp-156], %o0
	cmp	%o0, 4
	bgu	.LL9
	nop
	ld	[%fp-156], %o0
	sll	%o0, 2, %o1
	sethi	%hi(.LL44), %o0
	or	%o0, %lo(.LL44), %o0
	ld	[%o1+%o0], %o0
	jmp	%o0
	 nop
.LL39:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL40:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL41:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	callrelease, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL42:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL43:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	datatransfer, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL46:
	ld	[%fp-156], %o0
	cmp	%o0, 4
	bgu	.LL9
	nop
	ld	[%fp-156], %o0
	sll	%o0, 2, %o1
	sethi	%hi(.LL53), %o0
	or	%o0, %lo(.LL53), %o0
	ld	[%o1+%o0], %o0
	jmp	%o0
	 nop
.LL48:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL49:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL50:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL51:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL52:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL55:
	ld	[%fp-156], %o0
	cmp	%o0, 4
	bgu	.LL9
	nop
	ld	[%fp-156], %o0
	sll	%o0, 2, %o1
	sethi	%hi(.LL62), %o0
	or	%o0, %lo(.LL62), %o0
	ld	[%o1+%o0], %o0
	jmp	%o0
	 nop
.LL57:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL58:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL59:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL60:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
	b	.LL9
	 nop
.LL61:
	add	%fp, -184, %o0
	add	%fp, -152, %o1
	call	defaulthandler, 0
	 nop
	st	%o0, [%fp-20]
.LL9:
	ld	[%fp-20], %o0
	cmp	%o0, 0
	bne	.LL66
	nop
	sethi	%hi(.LLC0), %o0
	or	%o0, %lo(.LLC0), %o0
	call	perror, 0
	 nop
	b	.LL4
	 nop
.LL66:
	ld	[%fp-184], %o0
	cmp	%o0, 5
	bne	.LL3
	nop
.LL4:
	ld	[%fp-180], %o0
	call	tcpcloseconnection, 0
	 nop
	ld	[%fp-20], %o0
	mov	%o0, %i0
	nop
	ret
	restore
	.align 4
	.align 4
.LL62:
	.word	.LL57
	.word	.LL58
	.word	.LL59
	.word	.LL60
	.word	.LL61
	.align 4
.LL53:
	.word	.LL48
	.word	.LL49
	.word	.LL50
	.word	.LL51
	.word	.LL52
	.align 4
.LL44:
	.word	.LL39
	.word	.LL40
	.word	.LL41
	.word	.LL42
	.word	.LL43
	.align 4
.LL35:
	.word	.LL30
	.word	.LL31
	.word	.LL32
	.word	.LL33
	.word	.LL34
	.align 4
.LL26:
	.word	.LL21
	.word	.LL22
	.word	.LL23
	.word	.LL24
	.word	.LL25
	.align 4
.LL17:
	.word	.LL12
	.word	.LL13
	.word	.LL14
	.word	.LL15
	.word	.LL16
	.align 4
.LL64:
	.word	.LL10
	.word	.LL19
	.word	.LL28
	.word	.LL37
	.word	.LL46
	.word	.LL55
.LLfe2:
	.size	handleoriginatingcall,.LLfe2-handleoriginatingcall
	.ident	"GCC: (GNU) 3.2"
