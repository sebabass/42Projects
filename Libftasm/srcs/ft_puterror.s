;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puterror.s                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/18 18:31:15 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/18 18:34:01 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section	.data
	string: db	"(null)", 10
	.len: 	equ	$ - string

	section	.text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push	rbp
	mov		rbp, rsp
	cmp		rdi, 0
	jz		error
	push	rdi
	call	_ft_strlen
	mov		rdx, rax
	pop		rsi
	mov		rdi, 2
	mov		rax, 0x2000004
	syscall
	mov		rax, 0x2000004
	mov		rdx, 1
	lea		rsi, [rel string + 6]
	mov		rdi, 2
	syscall
	mov		rax, 10
	leave
	ret

error:
	mov		rax, 0x2000004
	mov		rdx, string.len
	lea		rsi, [rel string]
	mov		rdi, 2
	syscall
	mov		rax, 10
	leave
	ret
