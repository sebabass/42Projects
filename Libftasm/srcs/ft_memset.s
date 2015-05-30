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
	mov 	rbx, rdi			; On stock dans un pointeur l'arg1
	mov 	rax, rsi
	mov 	rcx, rdx			; On stock l'arg3 dans un compteur
	rep 	stosb				; On repete l'operation.
	mov 	rax, rbx			; On ret notre pointeur
	ret
	