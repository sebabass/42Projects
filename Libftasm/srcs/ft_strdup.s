;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/13 21:12:57 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/18 17:39:20 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_strdup
    extern _ft_strlen
    extern _ft_memcpy
    extern _malloc

_ft_strdup:
	push	rdi
	call	_ft_strlen
    inc		rax
    mov		rdi, rax
    call	_malloc
    mov		rdx, rax
    pop		rdi
    call	_ft_strlen
	inc		rax
    mov		rsi, rdi
    mov		rdi, rdx
    mov		rdx, rax
    call	_ft_memcpy
    ret