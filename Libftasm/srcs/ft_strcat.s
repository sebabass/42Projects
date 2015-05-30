;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/13 17:05:59 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/18 14:58:45 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_strcat

_ft_strcat:
	cmp		rdi, 0
	jle		empty				; On jump sur empty
	mov		rbx, rsi			; On stock notre 2eme arg dans un pointeur
	push	rdi					; On push rdi sur la stack

loop_rdi:
	cmp		byte[rdi], 0		; On compare byte de rdi a 0
	je		loop_rbx			; si egale on jump sur loop_rbx
	inc		rdi					; Sinon on incremente notre chaine
	jmp		loop_rdi			; et on jump sur loop_rdi

loop_rbx:
	cmp		byte[rbx], 0
	je		ok
	mov		rax, [rbx]
	mov		[rdi], rax
	inc		rbx
	inc		rdi
	jmp		loop_rbx

ok:
	mov		byte[rdi], 0
	pop		rdi
	mov		rax, rdi
	ret

empty:
	mov		rax, 0
	ret