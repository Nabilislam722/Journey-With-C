	.text
	.def	@feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 0
	.file	"line_reverse.c"
	.def	main;
	.scl	2;
	.type	32;
	.endef
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
main:                                   # @main
.seh_proc main
# %bb.0:
	pushq	%rbp
	.seh_pushreg %rbp
	movl	$1001056, %eax                  # imm = 0xF4660
	callq	___chkstk_ms
	subq	%rax, %rsp
	.seh_stackalloc 1001056
	leaq	128(%rsp), %rbp
	.seh_setframe %rbp, 128
	.seh_endprologue
	callq	__main
	movl	$0, 1000924(%rbp)
	movl	$0, -88(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	leaq	999920(%rbp), %rcx
	movl	$1000, %edx                     # imm = 0x3E8
	callq	get_line
	movl	%eax, -84(%rbp)
	cmpl	$0, %eax
	jle	.LBB0_7
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	movl	-88(%rbp), %eax
	cmpl	-84(%rbp), %eax
	jge	.LBB0_6
# %bb.3:                                #   in Loop: Header=BB0_1 Depth=1
	leaq	999920(%rbp), %rcx
	callq	trim_trailing_whitespace
	leaq	999920(%rbp), %rcx
	callq	strlen
	cmpq	$0, %rax
	jbe	.LBB0_5
# %bb.4:                                #   in Loop: Header=BB0_1 Depth=1
	movslq	-88(%rbp), %rax
	leaq	-80(%rbp), %rcx
	imulq	$1000, %rax, %rax               # imm = 0x3E8
	addq	%rax, %rcx
	leaq	999920(%rbp), %rdx
	callq	strcpy
	movl	-88(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -88(%rbp)
.LBB0_5:                                #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_6
.LBB0_6:                                #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_1
.LBB0_7:
	leaq	.L.str(%rip), %rcx
	callq	printf
	leaq	.L.str.1(%rip), %rcx
	callq	printf
	movl	$0, -92(%rbp)
.LBB0_8:                                # =>This Inner Loop Header: Depth=1
	movl	-92(%rbp), %eax
	cmpl	-88(%rbp), %eax
	jge	.LBB0_11
# %bb.9:                                #   in Loop: Header=BB0_8 Depth=1
	movslq	-92(%rbp), %rax
	leaq	-80(%rbp), %rdx
	imulq	$1000, %rax, %rax               # imm = 0x3E8
	addq	%rax, %rdx
	leaq	.L.str.2(%rip), %rcx
	callq	printf
# %bb.10:                               #   in Loop: Header=BB0_8 Depth=1
	movl	-92(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -92(%rbp)
	jmp	.LBB0_8
.LBB0_11:
	leaq	.L.str.1(%rip), %rcx
	callq	printf
	leaq	.L.str.3(%rip), %rcx
	callq	printf
	leaq	.L.str.1(%rip), %rcx
	callq	printf
	movl	$0, -96(%rbp)
.LBB0_12:                               # =>This Inner Loop Header: Depth=1
	movl	-96(%rbp), %eax
	cmpl	-88(%rbp), %eax
	jge	.LBB0_15
# %bb.13:                               #   in Loop: Header=BB0_12 Depth=1
	movslq	-96(%rbp), %rax
	leaq	-80(%rbp), %rcx
	imulq	$1000, %rax, %rax               # imm = 0x3E8
	addq	%rax, %rcx
	callq	reverse
# %bb.14:                               #   in Loop: Header=BB0_12 Depth=1
	movl	-96(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -96(%rbp)
	jmp	.LBB0_12
.LBB0_15:
	movl	1000924(%rbp), %eax
	addq	$1001056, %rsp                  # imm = 0xF4660
	popq	%rbp
	retq
	.seh_endproc
                                        # -- End function
	.def	get_line;
	.scl	2;
	.type	32;
	.endef
	.globl	get_line                        # -- Begin function get_line
	.p2align	4, 0x90
get_line:                               # @get_line
.seh_proc get_line
# %bb.0:
	subq	$56, %rsp
	.seh_stackalloc 56
	.seh_endprologue
	movq	%rcx, 48(%rsp)
	movl	%edx, 44(%rsp)
	movl	$0, 36(%rsp)
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
	movl	36(%rsp), %ecx
	movl	44(%rsp), %edx
	subl	$1, %edx
	xorl	%eax, %eax
                                        # kill: def $al killed $al killed $eax
	cmpl	%edx, %ecx
	movb	%al, 35(%rsp)                   # 1-byte Spill
	jge	.LBB1_4
# %bb.2:                                #   in Loop: Header=BB1_1 Depth=1
	callq	getchar
	movl	%eax, %ecx
	movl	%ecx, 40(%rsp)
	xorl	%eax, %eax
                                        # kill: def $al killed $al killed $eax
	cmpl	$-1, %ecx
	movb	%al, 35(%rsp)                   # 1-byte Spill
	je	.LBB1_4
# %bb.3:                                #   in Loop: Header=BB1_1 Depth=1
	cmpl	$10, 40(%rsp)
	setne	%al
	movb	%al, 35(%rsp)                   # 1-byte Spill
.LBB1_4:                                #   in Loop: Header=BB1_1 Depth=1
	movb	35(%rsp), %al                   # 1-byte Reload
	testb	$1, %al
	jne	.LBB1_5
	jmp	.LBB1_7
.LBB1_5:                                #   in Loop: Header=BB1_1 Depth=1
	movl	40(%rsp), %eax
	movb	%al, %dl
	movq	48(%rsp), %rax
	movslq	36(%rsp), %rcx
	movb	%dl, (%rax,%rcx)
# %bb.6:                                #   in Loop: Header=BB1_1 Depth=1
	movl	36(%rsp), %eax
	addl	$1, %eax
	movl	%eax, 36(%rsp)
	jmp	.LBB1_1
.LBB1_7:
	cmpl	$10, 40(%rsp)
	jne	.LBB1_9
# %bb.8:
	movq	48(%rsp), %rax
	movslq	36(%rsp), %rcx
	movb	$10, (%rax,%rcx)
	movl	36(%rsp), %eax
	addl	$1, %eax
	movl	%eax, 36(%rsp)
.LBB1_9:
	movq	48(%rsp), %rax
	movslq	36(%rsp), %rcx
	movb	$0, (%rax,%rcx)
	movl	36(%rsp), %eax
	addq	$56, %rsp
	retq
	.seh_endproc
                                        # -- End function
	.def	trim_trailing_whitespace;
	.scl	2;
	.type	32;
	.endef
	.globl	trim_trailing_whitespace        # -- Begin function trim_trailing_whitespace
	.p2align	4, 0x90
trim_trailing_whitespace:               # @trim_trailing_whitespace
.seh_proc trim_trailing_whitespace
# %bb.0:
	subq	$56, %rsp
	.seh_stackalloc 56
	.seh_endprologue
	movq	%rcx, 48(%rsp)
	movq	48(%rsp), %rcx
	callq	strlen
	subq	$1, %rax
                                        # kill: def $eax killed $eax killed $rax
	movl	%eax, 44(%rsp)
.LBB2_1:                                # =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
                                        # kill: def $al killed $al killed $eax
	cmpl	$0, 44(%rsp)
	movb	%al, 43(%rsp)                   # 1-byte Spill
	jl	.LBB2_6
# %bb.2:                                #   in Loop: Header=BB2_1 Depth=1
	movq	48(%rsp), %rax
	movslq	44(%rsp), %rcx
	movsbl	(%rax,%rcx), %ecx
	movb	$1, %al
	cmpl	$32, %ecx
	movb	%al, 42(%rsp)                   # 1-byte Spill
	je	.LBB2_5
# %bb.3:                                #   in Loop: Header=BB2_1 Depth=1
	movq	48(%rsp), %rax
	movslq	44(%rsp), %rcx
	movsbl	(%rax,%rcx), %ecx
	movb	$1, %al
	cmpl	$9, %ecx
	movb	%al, 42(%rsp)                   # 1-byte Spill
	je	.LBB2_5
# %bb.4:                                #   in Loop: Header=BB2_1 Depth=1
	movq	48(%rsp), %rax
	movslq	44(%rsp), %rcx
	movsbl	(%rax,%rcx), %eax
	cmpl	$10, %eax
	sete	%al
	movb	%al, 42(%rsp)                   # 1-byte Spill
.LBB2_5:                                #   in Loop: Header=BB2_1 Depth=1
	movb	42(%rsp), %al                   # 1-byte Reload
	movb	%al, 43(%rsp)                   # 1-byte Spill
.LBB2_6:                                #   in Loop: Header=BB2_1 Depth=1
	movb	43(%rsp), %al                   # 1-byte Reload
	testb	$1, %al
	jne	.LBB2_7
	jmp	.LBB2_8
.LBB2_7:                                #   in Loop: Header=BB2_1 Depth=1
	movq	48(%rsp), %rax
	movslq	44(%rsp), %rcx
	movb	$0, (%rax,%rcx)
	movl	44(%rsp), %eax
	addl	$-1, %eax
	movl	%eax, 44(%rsp)
	jmp	.LBB2_1
.LBB2_8:
	addq	$56, %rsp
	retq
	.seh_endproc
                                        # -- End function
	.def	reverse;
	.scl	2;
	.type	32;
	.endef
	.globl	reverse                         # -- Begin function reverse
	.p2align	4, 0x90
reverse:                                # @reverse
.seh_proc reverse
# %bb.0:
	subq	$1064, %rsp                     # imm = 0x428
	.seh_stackalloc 1064
	.seh_endprologue
	movq	%rcx, 1056(%rsp)
	movq	1056(%rsp), %rcx
	callq	strlen
                                        # kill: def $eax killed $eax killed $rax
	movl	%eax, 1052(%rsp)
	movl	$0, 44(%rsp)
	movl	1052(%rsp), %eax
	subl	$1, %eax
	movl	%eax, 40(%rsp)
.LBB3_1:                                # =>This Inner Loop Header: Depth=1
	cmpl	$0, 40(%rsp)
	jl	.LBB3_4
# %bb.2:                                #   in Loop: Header=BB3_1 Depth=1
	movq	1056(%rsp), %rax
	movslq	40(%rsp), %rcx
	movb	(%rax,%rcx), %cl
	movslq	44(%rsp), %rax
	movb	%cl, 48(%rsp,%rax)
	movl	44(%rsp), %eax
	addl	$1, %eax
	movl	%eax, 44(%rsp)
# %bb.3:                                #   in Loop: Header=BB3_1 Depth=1
	movl	40(%rsp), %eax
	addl	$-1, %eax
	movl	%eax, 40(%rsp)
	jmp	.LBB3_1
.LBB3_4:
	movslq	44(%rsp), %rax
	movb	$0, 48(%rsp,%rax)
	leaq	48(%rsp), %rdx
	leaq	.L.str.2(%rip), %rcx
	callq	printf
	movq	1056(%rsp), %rcx
	leaq	48(%rsp), %rdx
	callq	strcpy
	nop
	addq	$1064, %rsp                     # imm = 0x428
	retq
	.seh_endproc
                                        # -- End function
	.section	.rdata,"dr"
.L.str:                                 # @.str
	.asciz	"\nTrimmed Lines:\n"

.L.str.1:                               # @.str.1
	.asciz	"\n"

.L.str.2:                               # @.str.2
	.asciz	"%s\n"

.L.str.3:                               # @.str.3
	.asciz	"\nREVERSE LINE:\n"

	.addrsig
	.addrsig_sym get_line
	.addrsig_sym trim_trailing_whitespace
	.addrsig_sym strlen
	.addrsig_sym strcpy
	.addrsig_sym printf
	.addrsig_sym reverse
	.addrsig_sym getchar
