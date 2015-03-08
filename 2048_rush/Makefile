#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spariaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 23:25:32 by spariaud          #+#    #+#              #
#    Updated: 2015/03/01 22:51:35 by spariaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME =			game_2048

SRCS = 			main.c \
				game_params.c \
				ft_mouv.c \
				ft_mouvbis.c \
				ft_feed_norme.c \
				ft_victory.c \
				random.c \
				put_tab.c \
				ft_menu.c \
				game.c \
				ft_strlen.c \

OBJS = 			$(SRCS:.c=.o)

FLAGS =			-Wall -Wextra -Werror

INC_FILES =		includes/game.h

INCLUDES =		-I includes/ \

all: 			$(NAME)

$(NAME): 		$(INCLUDES)

$(INCLUDES): 	$(OBJS)

$(OBJS): 		$(INC_FILES) $(SRCS)
				@echo "Create binary"
				@gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
				@gcc -o $(NAME) $(OBJS) -lncurses
				@echo "Compilation ok"

norm:
				@echo "Check norme game_2048"
				@norminette $(SRCS)
				@norminette $(INC_FILES)

clean:
				/bin/rm -f $(OBJS)

fclean: 		clean
				/bin/rm -f $(NAME)

re: 			fclean all

.PHONY = 		all clean fclean re
