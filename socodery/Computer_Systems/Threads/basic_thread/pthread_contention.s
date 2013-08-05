	.file	"pthread_contention.c"
	.global globalvar
	.section	".data"
	.align 4
	.type	globalvar,#object
	.size	globalvar,4
globalvar:
	.long	0
	.section	".rodata"
	.align 8
.LLC0:
	.asciz	"thread id : %d : globalvar : %d \n"
	.align 8
.LLC1:
	.asciz	"adderss of i & globalvar : %u : %u\n"
	.section	".text"
	.align 4
	.global commonfunction
	.type	commonfunction,#function
	.proc	0120
commonfunction:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	mov	10, %o0
	st	%o0, [%fp-20]
	sethi	%hi(globalvar), %o0
	or	%o0, %lo(globalvar), %o1
	ld	[%fp+68], %o0
	st	%o0, [%o1]
.LL2:
	add	%fp, -20, %o0
	ld	[%o0], %o1
	mov	%o1, %o2
	add	%o1, 1, %o1
	st	%o1, [%o0]
	cmp	%o2, 0
	ble	.LL4
	nop
	b	.LL3
	 nop
.LL4:
	sethi	%hi(globalvar), %o0
	or	%o0, %lo(globalvar), %o1
	sethi	%hi(globalvar), %o0
	or	%o0, %lo(globalvar), %o0
	ld	[%o0], %o0
	add	%o0, 1, %o0
	st	%o0, [%o1]
	call	pthread_self, 0
	 nop
	mov	%o0, %o1
	sethi	%hi(globalvar), %o0
	or	%o0, %lo(globalvar), %o2
	sethi	%hi(.LLC0), %o0
	or	%o0, %lo(.LLC0), %o0
	ld	[%o2], %o2
	call	printf, 0
	 nop
	add	%fp, -20, %o1
	sethi	%hi(.LLC1), %o0
	or	%o0, %lo(.LLC1), %o0
	sethi	%hi(globalvar), %o2
	or	%o2, %lo(globalvar), %o2
	call	printf, 0
	 nop
	b	.LL2
	 nop
.LL3:
	mov	0, %o0
	mov	%o0, %i0
	nop
	ret
	restore
.LLfe1:
	.size	commonfunction,.LLfe1-commonfunction
	.align 4
	.global startthread1
	.type	startthread1,#function
	.proc	0120
startthread1:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	mov	0, %o0
	call	commonfunction, 0
	 nop
	mov	0, %o0
	mov	%o0, %i0
	nop
	ret
	restore
.LLfe2:
	.size	startthread1,.LLfe2-startthread1
	.align 4
	.global startthread2
	.type	startthread2,#function
	.proc	0120
startthread2:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	mov	0, %o0
	call	commonfunction, 0
	 nop
	mov	0, %o0
	mov	%o0, %i0
	nop
	ret
	restore
.LLfe3:
	.size	startthread2,.LLfe3-startthread2
	.section	".rodata"
	.align 8
.LLC2:
	.asciz	"thread creation failed\n"
	.align 8
.LLC3:
	.asciz	"main thread will not come here\n"
	.section	".text"
	.align 4
	.global main
	.type	main,#function
	.proc	04
main:
	!#PROLOGUE# 0
	save	%sp, -136, %sp
	!#PROLOGUE# 1
	add	%fp, -32, %o0
	call	pthread_attr_init, 0
	 nop
	add	%fp, -32, %o0
	mov	1, %o1
	call	pthread_attr_setscope, 0
	 nop
	add	%fp, -28, %o0
	add	%fp, -32, %o1
	sethi	%hi(startthread2), %o2
	or	%o2, %lo(startthread2), %o2
	mov	0, %o3
	call	pthread_create, 0
	 nop
	st	%o0, [%fp-20]
	ld	[%fp-20], %o0
	cmp	%o0, 0
	be	.LL8
	nop
	sethi	%hi(.LLC2), %o0
	or	%o0, %lo(.LLC2), %o0
	call	printf, 0
	 nop
	mov	-1, %o0
	st	%o0, [%fp-36]
	b	.LL7
	 nop
.LL8:
	add	%fp, -24, %o0
	mov	0, %o1
	sethi	%hi(startthread1), %o2
	or	%o2, %lo(startthread1), %o2
	mov	0, %o3
	call	pthread_create, 0
	 nop
	st	%o0, [%fp-20]
	ld	[%fp-20], %o0
	cmp	%o0, 0
	be	.LL9
	nop
	sethi	%hi(.LLC2), %o0
	or	%o0, %lo(.LLC2), %o0
	call	printf, 0
	 nop
	mov	-1, %o0
	st	%o0, [%fp-36]
	b	.LL7
	 nop
.LL9:
	add	%fp, -20, %o0
	call	pthread_exit, 0
	 nop
	sethi	%hi(.LLC3), %o0
	or	%o0, %lo(.LLC3), %o0
	call	printf, 0
	 nop
	st	%g0, [%fp-36]
.LL7:
	ld	[%fp-36], %i0
	nop
	ret
	restore
.LLfe4:
	.size	main,.LLfe4-main
	.ident	"GCC: (GNU) 3.2"
