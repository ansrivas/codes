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
	.align 4
	.global initializecalltable
	.type	initializecalltable,#function
	.proc	020
initializecalltable:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
	!#PROLOGUE# 1
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+4]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+8]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+12]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+16]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+20]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(callanswer), %i0
	or	%i0, %lo(callanswer), %i0
	st	%i0, [%i1+24]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+28]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+32]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+36]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+40]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+44]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+48]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+52]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+56]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+60]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(callanswer), %i0
	or	%i0, %lo(callanswer), %i0
	st	%i0, [%i1+64]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(callrelease), %i0
	or	%i0, %lo(callrelease), %i0
	st	%i0, [%i1+68]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+72]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(datatransfer), %i0
	or	%i0, %lo(datatransfer), %i0
	st	%i0, [%i1+76]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+80]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+84]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+88]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+92]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+96]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+100]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+104]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+108]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+112]
	sethi	%hi(ocallstatetable), %i0
	or	%i0, %lo(ocallstatetable), %i1
	sethi	%hi(defaulthandler), %i0
	or	%i0, %lo(defaulthandler), %i0
	st	%i0, [%i1+116]
	nop
	ret
	restore
.LLfe2:
	.size	initializecalltable,.LLfe2-initializecalltable
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
	.proc	0120
handleoriginatingcall:
	!#PROLOGUE# 0
	save	%sp, -256, %sp
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%g0, [%fp-20]
	ld	[%fp+68], %o0
	st	%o0, [%fp-160]
	ld	[%fp-160], %o1
	mov	1, %o0
	st	%o0, [%o1]
	mov	2, %o0
	call	sleep, 0
	 nop
.LL4:
	ld	[%fp-160], %o0
	add	%fp, -88, %o1
	ld	[%o0+4], %o0
	call	receivepacket, 0
	 nop
	st	%o0, [%fp-20]
	ld	[%fp-20], %o0
	cmp	%o0, 0
	bne	.LL7
	nop
	sethi	%hi(.LLC0), %o0
	or	%o0, %lo(.LLC0), %o0
	call	perror, 0
	 nop
	b	.LL5
	 nop
.LL7:
	add	%fp, -88, %o0
	add	%fp, -152, %o1
	call	createmessagefrompacket, 0
	 nop
	st	%o0, [%fp-20]
	ld	[%fp-20], %o0
	cmp	%o0, 0
	bne	.LL8
	nop
	sethi	%hi(.LLC1), %o0
	or	%o0, %lo(.LLC1), %o0
	call	perror, 0
	 nop
	b	.LL5
	 nop
.LL8:
	add	%fp, -152, %o0
	call	getsubscriberevent, 0
	 nop
	st	%o0, [%fp-156]
	ld	[%fp-156], %o0
	cmp	%o0, 4
	bleu	.LL9
	nop
	mov	3, %o0
	st	%o0, [%fp-156]
.LL9:
	sethi	%hi(ocallstatetable), %o0
	or	%o0, %lo(ocallstatetable), %o2
	ld	[%fp-160], %o0
	ld	[%o0], %o1
	mov	%o1, %o0
	sll	%o0, 2, %o0
	add	%o0, %o1, %o0
	ld	[%fp-156], %o1
	add	%o0, %o1, %o0
	sll	%o0, 2, %o0
	add	%fp, -152, %o1
	ld	[%o2+%o0], %o2
	ld	[%fp-160], %o0
	call	%o2, 0
	 nop
	st	%o0, [%fp-20]
	ld	[%fp-20], %o0
	cmp	%o0, 0
	bne	.LL10
	nop
	sethi	%hi(.LLC0), %o0
	or	%o0, %lo(.LLC0), %o0
	call	perror, 0
	 nop
	b	.LL5
	 nop
.LL10:
	ld	[%fp-160], %o0
	ld	[%o0], %o0
	cmp	%o0, 5
	bne	.LL4
	nop
.LL5:
	ld	[%fp-160], %o0
	ld	[%o0+4], %o0
	call	tcpcloseconnection, 0
	 nop
	ld	[%fp-160], %o0
	call	free, 0
	 nop
	mov	0, %o0
	mov	%o0, %i0
	nop
	ret
	restore
.LLfe3:
	.size	handleoriginatingcall,.LLfe3-handleoriginatingcall
	.common	ocallstatetable,120,4
	.ident	"GCC: (GNU) 3.2"
