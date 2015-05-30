;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/12 21:19:48 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/18 15:01:34 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_strlen

_ft_strlen:
	push	rdi
	mov		rcx, 0
	mov		al, 0
	not		rcx
	repne	scasb
	not		rcx
	dec		rcx
	pop		rdi
	
end:
	mov		rax, rcx
	ret
	
