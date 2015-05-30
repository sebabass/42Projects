;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isblank.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/14 14:51:39 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/14 16:27:04 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_isblank

_ft_isblank:
	cmp		rdi, 9
	je		ok
	cmp		rdi, 32
	je		ok
	jmp		ko

ok:
	mov		rax, 1
	ret

ko:
	mov		rax, 0
	ret