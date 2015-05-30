;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/13 17:07:22 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/18 15:04:39 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_memset

_ft_memset:
	mov 	rbx, rdi
	mov 	rax, rsi
	mov 	rcx, rdx
	rep 	stosb
	mov 	rax, rbx
	ret
	
