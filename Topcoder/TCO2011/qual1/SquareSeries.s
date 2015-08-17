	.file	"SquareSeries.cpp"
	.text
	.align 2
	.def	__ZSt17__verify_groupingPKcjRKSs;	.scl	3;	.type	32;	.endef
__ZSt17__verify_groupingPKcjRKSs:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSs4sizeEv
	decl	%eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	decl	%eax
	movl	%eax, -12(%ebp)
	leal	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3minIjERKT_S2_S2_
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, -16(%ebp)
	movb	$1, -17(%ebp)
	movl	$0, -24(%ebp)
L2:
	movl	-24(%ebp), %eax
	cmpl	-8(%ebp), %eax
	jae	L5
	cmpb	$0, -17(%ebp)
	je	L5
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSsixEj
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	-24(%ebp), %edx
	addl	%eax, %edx
	movzbl	(%ecx), %eax
	cmpb	(%edx), %al
	sete	%al
	movb	%al, -17(%ebp)
	leal	-16(%ebp), %eax
	decl	(%eax)
	leal	-24(%ebp), %eax
	incl	(%eax)
	jmp	L2
L5:
	cmpl	$0, -16(%ebp)
	je	L6
	cmpb	$0, -17(%ebp)
	je	L6
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSsixEj
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	-8(%ebp), %edx
	addl	%eax, %edx
	movzbl	(%ecx), %eax
	cmpb	(%edx), %al
	sete	%al
	movb	%al, -17(%ebp)
	leal	-16(%ebp), %eax
	decl	(%eax)
	jmp	L5
L6:
	movl	$0, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSsixEj
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	-8(%ebp), %edx
	addl	%eax, %edx
	movzbl	(%ecx), %eax
	cmpb	(%edx), %al
	jg	L8
	movzbl	-17(%ebp), %eax
	andl	$1, %eax
	movb	%al, -25(%ebp)
	jmp	L9
L8:
	movb	$0, -25(%ebp)
L9:
	movzbl	-25(%ebp), %eax
	movb	%al, -17(%ebp)
	movzbl	-17(%ebp), %eax
	leave
	ret
.lcomm __ZSt8__ioinit,16
.globl _blen
	.bss
	.align 4
_blen:
	.space 4
.globl _elen
	.align 4
_elen:
	.space 4
.globl _strSize
	.align 4
_strSize:
	.space 4
.globl _wPos
	.align 4
_wPos:
	.space 4
.globl _res
	.align 4
_res:
	.space 4
.globl _ans
	.align 4
_ans:
	.space 4
.globl _pStr
	.align 4
_pStr:
	.space 4
	.section .rdata,"dr"
LC0:
	.ascii "B\0"
LC1:
	.ascii "\0"
LC2:
	.ascii "W\0"
	.text
	.align 2
.globl __Z3dfsici
	.def	__Z3dfsici;	.scl	2;	.type	32;	.endef
__Z3dfsici:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	12(%ebp), %eax
	movb	%al, -1(%ebp)
	movl	16(%ebp), %eax
	cmpl	_elen, %eax
	jne	L11
	movl	_strSize, %eax
	decl	%eax
	cmpl	_wPos, %eax
	je	L12
	movl	_wPos, %eax
	incl	%eax
	movl	%eax, 4(%esp)
	movl	$_pStr, (%esp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	cmpb	-1(%ebp), %al
	je	L13
	movl	$LC0, 4(%esp)
	movl	$_res, (%esp)
	call	__ZNSspLEPKc
	jmp	L12
L13:
	movl	8(%ebp), %eax
	decl	%eax
	movl	%eax, 4(%esp)
	movl	$_res, (%esp)
	call	__ZNSsixEj
	movb	$0, (%eax)
L12:
	movl	$LC1, 4(%esp)
	movl	$_ans, (%esp)
	call	__ZStneIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	testb	%al, %al
	jne	L16
	movl	$_res, 4(%esp)
	movl	$_ans, (%esp)
	call	__ZStgtIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_ES8_
	testb	%al, %al
	jne	L16
	jmp	L11
L16:
	movl	$_res, 4(%esp)
	movl	$_ans, (%esp)
	call	__ZNSsaSERKSs
L11:
	movl	16(%ebp), %eax
	cmpl	_elen, %eax
	jge	L17
	cmpb	$66, -1(%ebp)
	jne	L18
	movl	$LC2, 4(%esp)
	movl	$_res, (%esp)
	call	__ZNSspLEPKc
	movl	16(%ebp), %eax
	incl	%eax
	movl	%eax, 8(%esp)
	movl	$87, 4(%esp)
	movl	8(%ebp), %eax
	incl	%eax
	movl	%eax, (%esp)
	call	__Z3dfsici
	jmp	L17
L18:
	movl	$LC0, 4(%esp)
	movl	$_res, (%esp)
	call	__ZNSspLEPKc
	movl	16(%ebp), %eax
	incl	%eax
	movl	%eax, 8(%esp)
	movl	$66, 4(%esp)
	movl	8(%ebp), %eax
	incl	%eax
	movl	%eax, (%esp)
	call	__Z3dfsici
L17:
	movl	16(%ebp), %eax
	cmpl	_elen, %eax
	jge	L10
	cmpl	$1, 16(%ebp)
	jg	L21
	jmp	L10
L21:
	cmpb	$66, -1(%ebp)
	jne	L22
	movl	$LC0, 4(%esp)
	movl	$_res, (%esp)
	call	__ZNSspLEPKc
	movl	16(%ebp), %eax
	decl	%eax
	movl	%eax, 8(%esp)
	movl	$66, 4(%esp)
	movl	8(%ebp), %eax
	incl	%eax
	movl	%eax, (%esp)
	call	__Z3dfsici
	jmp	L10
L22:
	movl	$LC2, 4(%esp)
	movl	$_res, (%esp)
	call	__ZNSspLEPKc
	movl	16(%ebp), %eax
	decl	%eax
	movl	%eax, 8(%esp)
	movl	$87, 4(%esp)
	movl	8(%ebp), %eax
	incl	%eax
	movl	%eax, (%esp)
	call	__Z3dfsici
L10:
	leave
	ret
	.section	.text$_ZSt3minIjERKT_S2_S2_,"x"
	.linkonce discard
	.align 2
.globl __ZSt3minIjERKT_S2_S2_
	.def	__ZSt3minIjERKT_S2_S2_;	.scl	2;	.type	32;	.endef
__ZSt3minIjERKT_S2_S2_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	(%eax), %eax
	cmpl	(%edx), %eax
	jae	L25
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	L24
L25:
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
L24:
	movl	-4(%ebp), %eax
	leave
	ret
	.section	.text$_ZStneIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_,"x"
	.linkonce discard
	.align 2
.globl __ZStneIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	.def	__ZStneIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_;	.scl	2;	.type	32;	.endef
__ZStneIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSs7compareEPKc
	movl	%eax, -4(%ebp)
	cmpl	$0, -4(%ebp)
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.section	.text$_ZStgtIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_ES8_,"x"
	.linkonce discard
	.align 2
.globl __ZStgtIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_ES8_
	.def	__ZStgtIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_ES8_;	.scl	2;	.type	32;	.endef
__ZStgtIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_ES8_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSs7compareERKSs
	movl	%eax, -4(%ebp)
	cmpl	$0, -4(%ebp)
	setg	%al
	movzbl	%al, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.text
	.align 2
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	cmpl	$65535, 12(%ebp)
	jne	L29
	cmpl	$1, 8(%ebp)
	jne	L29
	movl	$__ZSt8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
L29:
	cmpl	$65535, 12(%ebp)
	jne	L30
	cmpl	$1, 8(%ebp)
	jne	L30
	movl	$_res, (%esp)
	call	__ZNSsC1Ev
L30:
	cmpl	$65535, 12(%ebp)
	jne	L31
	cmpl	$1, 8(%ebp)
	jne	L31
	movl	$_ans, (%esp)
	call	__ZNSsC1Ev
L31:
	cmpl	$65535, 12(%ebp)
	jne	L32
	cmpl	$1, 8(%ebp)
	jne	L32
	movl	$_pStr, (%esp)
	call	__ZNSsC1Ev
L32:
	cmpl	$65535, 12(%ebp)
	jne	L33
	cmpl	$0, 8(%ebp)
	jne	L33
	movl	$_pStr, (%esp)
	call	__ZNSsD1Ev
L33:
	cmpl	$65535, 12(%ebp)
	jne	L34
	cmpl	$0, 8(%ebp)
	jne	L34
	movl	$_ans, (%esp)
	call	__ZNSsD1Ev
L34:
	cmpl	$65535, 12(%ebp)
	jne	L35
	cmpl	$0, 8(%ebp)
	jne	L35
	movl	$_res, (%esp)
	call	__ZNSsD1Ev
L35:
	cmpl	$65535, 12(%ebp)
	jne	L28
	cmpl	$0, 8(%ebp)
	jne	L28
	movl	$__ZSt8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
L28:
	leave
	ret
	.align 2
	.def	__GLOBAL__I_blen;	.scl	3;	.type	32;	.endef
__GLOBAL__I_blen:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__I_blen
	.text
	.align 2
	.def	__GLOBAL__D_blen;	.scl	3;	.type	32;	.endef
__GLOBAL__D_blen:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$65535, 4(%esp)
	movl	$0, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__D_blen
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	3;	.type	32;	.endef
	.def	__ZNKSs7compareERKSs;	.scl	3;	.type	32;	.endef
	.def	__ZNKSs7compareEPKc;	.scl	3;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	3;	.type	32;	.endef
	.def	__ZNSsaSERKSs;	.scl	3;	.type	32;	.endef
	.def	__ZStgtIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_ES8_;	.scl	3;	.type	32;	.endef
	.def	__ZStneIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_;	.scl	3;	.type	32;	.endef
	.def	__ZNSspLEPKc;	.scl	3;	.type	32;	.endef
	.def	__ZNSsixEj;	.scl	3;	.type	32;	.endef
	.def	__ZNSsC1Ev;	.scl	3;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	3;	.type	32;	.endef
	.def	__ZNKSsixEj;	.scl	3;	.type	32;	.endef
	.def	__ZNKSs4sizeEv;	.scl	3;	.type	32;	.endef
	.def	__ZSt3minIjERKT_S2_S2_;	.scl	3;	.type	32;	.endef
