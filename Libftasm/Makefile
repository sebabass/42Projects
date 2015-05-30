#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/22 19:01:52 by spariaud          #+#    #+#              #
#    Updated: 2015/05/18 18:48:05 by spariaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			libfts.a

AS =			nasm -f macho64

SRCS =			srcs/ft_isalpha.s \
				srcs/ft_isdigit.s \
				srcs/ft_isalnum.s \
				srcs/ft_isascii.s \
				srcs/ft_isprint.s \
				srcs/ft_toupper.s \
				srcs/ft_tolower.s \
				srcs/ft_bzero.s \
				srcs/ft_strcat.s \
				srcs/ft_strlen.s \
				srcs/ft_memset.s \
				srcs/ft_memcpy.s \
				srcs/ft_puts.s \
				srcs/ft_strdup.s \
				srcs/ft_cat.s \
				srcs/ft_isblank.s \
				srcs/ft_isspace.s \
				srcs/ft_isupper.s \
				srcs/ft_islower.s \
				srcs/ft_ispunct.s \
				srcs/ft_strchr.s \
				srcs/ft_puterror.s

INCLUDE =		-I include/

OBJS =			$(SRCS:srcs/%.s=obj/%.o)

CFLAGS =		-Wall -Wextra -Werror

all:			$(NAME) test test_cat

$(NAME):		obj $(OBJS)
				@ar rc -L $(NAME) $(OBJS)
				@ranlib $(NAME)

test:
				@gcc -o test $(INCLUDE) srcs/main.c $(NAME)

test_cat:
				@gcc -o test_cat $(INCLUDE) srcs/main_cat.c $(NAME)

obj/%.o:		srcs/%.s
				@$(AS) -o $@ $<
				@echo "[\033[32m√\033[m]" $<

obj:
				@mkdir -p obj

clean:
				@rm -rf obj
				@rm test test_cat

fclean:			clean
				@rm $(NAME)

re:				fclean all

.PHONY =		all clean fclean re
