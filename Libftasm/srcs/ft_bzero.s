;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/13 17:04:13 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/18 14:56:08 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_bzero

_ft_bzero:
	cmp		rdi, 0
	je		end
	jmp		end_loop
	begin_loop:
	mov		[rdi], byte 0
	inc		rdi
	dec		rsi
	end_loop:
	cmp		rsi, 0
	jne		begin_loop
	ret

end:
	ret
