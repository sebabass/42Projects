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
	mov		al, sil				; prend les 8 premier bit de rsi
	cld							; clear direction flag
	repne	scasb
	je		found

notfound:						; si il trouve pas le caractere
	mov		rax, 0
	ret

found:							; si il trouve le caractere
	dec		rdi
	mov		rax, rdi
	ret