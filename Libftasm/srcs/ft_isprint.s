;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/13 17:05:35 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/13 18:45:31 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_isprint

_ft_isprint:
	cmp		rdi, 32
	jl		ko
	cmp		rdi, 127
	jl		ok
	jmp		ko

ko:
	mov		rax, 0
	ret

ok:
	mov		rax, 1
	ret