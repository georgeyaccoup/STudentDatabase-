	.file	"main.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "\12Hello Every one this is George Yaccoup C-Project For AMIT learning Embedded Systems Diploma : \0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	call	_PrintLine
	movl	$LC0, (%esp)
	call	_puts
	call	_PrintLine
	call	_SDB_APP
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.ident	"GCC: (i686-posix-dwarf-rev1, Built by MinGW-W64 project) 6.2.0"
	.def	_PrintLine;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_SDB_APP;	.scl	2;	.type	32;	.endef
