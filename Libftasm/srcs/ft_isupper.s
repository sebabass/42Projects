;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/14 15:12:17 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/14 15:14:15 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_isupper

_ft_isupper:
	cmp		rdi, 65
	jl		ko
	cmp		rdi, 90
	jle		ok
	jmp		ko

ok:
	mov		rax, 1
	ret

ko:
	mov		rax, 0
	ret