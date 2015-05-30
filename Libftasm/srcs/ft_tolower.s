;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/13 17:06:24 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/14 02:06:17 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_tolower

_ft_tolower:
	cmp		rdi, 65
	jl		end
	cmp		rdi, 91
	jl		ok
	jmp		end

ok:
	add		rdi, 32
	mov		rax, rdi
	ret

end:
	mov		rax, rdi
	ret
