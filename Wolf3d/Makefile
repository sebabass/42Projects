#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/16 16:52:03 by spariaud          #+#    #+#              #
#    Updated: 2015/02/14 18:13:28 by spariaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			wolf3d

SRCS = 			main.c \
				get_next_line.c \
				event.c \
				map.c \
				opt_file.c \
				player.c \
				raycast.c \
				draw.c \
				move.c \

OBJS = 			$(SRCS:.c=.o)

FLAGS =			-Wall -Wextra -Werror

INC_FILES =		includes/get_next_line.h \
				includes/wolf3d.h \

INCLUDES =		-I includes/ \
				-I libft/includes/

LIBS =			-L libft/ -lft \
				-L /usr/X11/lib -lmlx -lXext -lX11

all: 			$(NAME)

$(NAME): 		$(INCLUDES)

$(INCLUDES): 	$(OBJS)

$(OBJS): 		$(SRCS)
				@make -C libft/ fclean
				@make -C libft/
				@echo "Create binary"
				@gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
				@gcc -o $(NAME) $(OBJS) $(LIBS);
				@echo "Compilation ok"

norm:
				@make -C libft/ norm
				@echo "Check norme wolf3d"
				@norminette $(SRCS)
				@norminette $(INC_FILES)

clean:
				/bin/rm -f $(OBJS)

fclean: 		clean
				/bin/rm -f $(NAME)

re: 			fclean all

.PHONY = 		all clean fclean re