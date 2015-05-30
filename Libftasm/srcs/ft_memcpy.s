;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/13 21:12:43 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/18 17:32:28 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_memcpy

_ft_memcpy:
	mov		rbx, rsi
	mov		rax, rdi
	mov		rcx, rdx
	rep		movsb
	ret