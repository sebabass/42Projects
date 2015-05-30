;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/14 13:44:46 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/18 15:00:34 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section	.data
	string:	 db	"(null)", 10
	.len: 	equ	$ - string

section	.text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push	rbp					; Pointeur de base
	mov		rbp, rsp			; rsp pointeur de la pile
	cmp		rdi, 0
	jz		error				; jz si egal a zero
	push	rdi
	call	_ft_strlen
	mov		rdx, rax			; Retour de ft_strlen en 3eme arg de write
	pop		rsi
	mov		rdi, 1				; sortie arg1 de write
	mov		rax, 0x2000004		; appel de write
	syscall
	mov		rax, 0x2000004
	mov		rdx, 1
	lea		rsi, [rel string + 6] ; ajout du '\n'
	mov		rdi, 1
    syscall
	mov		rax, 10				; retour de write
	leave						; libere la pile
	ret

error:							; affichage de null
	mov		rax, 0x2000004
	mov		rdx, string.len
	lea		rsi, [rel string]
	mov		rdi, 1
    syscall
	mov		rax, 10
	leave
	ret