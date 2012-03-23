	.file	"test.c"
	.intel_syntax noprefix
	.text
.globl main
	.type	main, @function
main:
	push	ebp
	mov	ebp, esp
	mov	eax, 0
	pop	ebp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
