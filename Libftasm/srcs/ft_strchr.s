;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strchr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/18 17:48:34 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/18 18:52:28 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_strchr
    extern _ft_strlen

_ft_strchr:
	call	_ft_strlen
	cmp		rax, 0
	je		notfound
	mov		rcx, rax
	mov		al, sil
	cld
	repne	scasb
	je		found

notfound:
	mov		rax, 0
	ret

found:
	dec		rdi
	mov		rax, rdi
	ret
