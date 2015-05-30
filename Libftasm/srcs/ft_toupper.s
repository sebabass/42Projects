;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/13 17:06:40 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/14 02:06:29 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_toupper

_ft_toupper:
	cmp		rdi, 97
	jl		end
	cmp		rdi, 123
	jl		ok
	jmp		end

ok:
	sub		rdi, 32				; On soustrait 32
	mov		rax, rdi
	ret

end:
	mov		rax, rdi
	ret