;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isspace.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/14 15:00:38 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/14 15:12:05 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_isspace

_ft_isspace:
	cmp		rdi, 9
	jl		ko
	cmp		rdi, 13
	jle		ok
	cmp		rdi, 32
	je		ok
	jmp		ko

ok:
	mov		rax, 1
	ret

ko:
	mov		rax, 0
	ret