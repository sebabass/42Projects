;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/14 13:44:46 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/18 15:00:34 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section	.data
	string:	 db	"(null)", 10
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
	mov		rdi, 1
	mov		rax, 0x2000004
	syscall
	mov		rax, 0x2000004
	mov		rdx, 1
	lea		rsi, [rel string + 6]
	mov		rdi, 1
    syscall
	mov		rax, 10
	leave
	ret

error:
	mov		rax, 0x2000004
	mov		rdx, string.len
	lea		rsi, [rel string]
	mov		rdi, 1
    syscall
	mov		rax, 10
	leave
	ret
