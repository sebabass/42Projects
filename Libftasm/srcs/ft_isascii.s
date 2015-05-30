;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/24 17:57:22 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/13 18:48:37 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_isascii

_ft_isascii:
	cmp		rdi, 0
	jl		ko
	cmp		rdi, 127
	jle		ok
	jmp		ko

ko:
	mov		rax, 0
	ret

ok:
	mov		rax, 1
	ret