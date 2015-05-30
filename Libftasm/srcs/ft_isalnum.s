;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/24 16:45:11 by spariaud          #+#    #+#              ;
;    Updated: 2015/05/14 02:16:26 by spariaud         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:
	call	_ft_isdigit
	cmp		rax, 1				; Si le retour de ft_isdigit
	je		end					; On jump sur end
	call	_ft_isalpha

end:
	ret