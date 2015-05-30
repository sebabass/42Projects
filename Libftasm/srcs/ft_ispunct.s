;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_ispunct.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/14 16:09:15 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/14 16:12:42 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_ispunct

_ft_ispunct:
	cmp		rdi, 33
	jl		ko
	cmp		rdi, 47
	jle		ok
	cmp		rdi, 58
	jl		ko
	cmp		rdi, 64
	jle		ok
	cmp		rdi, 91
	jl		ko
	cmp		rdi, 96
	jle		ok
	cmp		rdi, 123
	jl		ko
	cmp		rdi, 126
	jle		ok
	jmp		ko

ok:
	mov		rax, 1
	ret

ko:
	mov		rax, 0
	ret