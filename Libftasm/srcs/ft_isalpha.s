;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/13 17:04:57 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/14 02:05:05 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_isalpha

_ft_isalpha:
	cmp		rdi, 65
	jl		ko
	cmp		rdi, 91
	jl		ok			
	cmp		rdi, 97
	jl		ko
	cmp		rdi, 123
	jl		ok
	jmp		ko

ko:
	mov		rax, 0				; On retourne 0 si c'est pas bon
	ret

ok:
	mov		rax, 1				; Sinon on retourne 1
	ret
