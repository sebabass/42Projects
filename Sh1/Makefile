#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/16 16:52:03 by spariaud          #+#    #+#              #
#    Updated: 2015/02/26 16:07:52 by spariaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			ft_minishell1

SRCS = 			main.c \
				get_next_line.c \
				cd.c \
				cd_next.c \
				env.c \
				setenv.c \
				unsetenv.c \
				exit.c \
				lst_env.c \
				del_lst_env.c \
				tool.c \
				tool_next.c

OBJS = 			$(SRCS:.c=.o)

FLAGS =			-Wall -Wextra -Werror

INC_FILES =		includes/get_next_line.h \
				includes/sh.h

INCLUDES =		-I includes/ \
				-I libft/includes/

all: 			$(NAME)

$(NAME): 		$(INCLUDES)

$(INCLUDES): 	$(OBJS)

$(OBJS): 		$(SRCS)
				@make -C libft/ fclean
				@make -C libft/
				@echo "Create binary"
				@gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
				@gcc -o $(NAME) $(OBJS) -L libft/ -lft
				@echo "Compilation ok"

norm:
				@make -C libft/ norm
				@echo "Check norme ft_minishell1"
				@norminette $(SRCS)
				@norminette $(INC_FILES)

clean:
				/bin/rm -f $(OBJS)

fclean: 		clean
				/bin/rm -f $(NAME)

re: 			fclean all

.PHONY = 		all clean fclean re