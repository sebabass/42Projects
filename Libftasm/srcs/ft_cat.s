;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/14 13:47:34 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/18 15:03:08 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .data
	%define BUFSIZE 2048
	buffer times BUFSIZE db 0
	
section .text
	global _ft_cat
	
_ft_cat:
	mov		rax, 0x2000003
    lea		rsi, [rel buffer]
    mov		rdx, BUFSIZE
    syscall
    jc		return
    cmp		rax, 0
    je		return
    push	rdi
    mov		rdi, 1
    mov		rdx, rax
    mov		rax, 0x2000004
    syscall
    jc		return
    pop		rdi
	jmp		_ft_cat

return:
	ret
