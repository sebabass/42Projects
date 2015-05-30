;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/13 17:05:23 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/13 18:45:01 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_isdigit

_ft_isdigit:
	cmp		rdi, 48
	jl		ko
	cmp		rdi, 58
	jl		ok
	jmp		ko

ok:
	mov		rax, 1
	ret

ko:
	mov		rax, 0
	ret