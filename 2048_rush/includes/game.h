/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:56:33 by spariaud          #+#    #+#             */
/*   Updated: 2015/03/01 23:20:38 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define KEY_ESC	27
# define NBR_CASE	4
# define MAX_SCORE	131072
# define RIGHT		1
# define LEFT		2
# define UP			3
# define DOWN		4
# define PLAY		1
# define START		1
# define END		2
# define VICTORY	3
# define ERROR		4

enum	e_const
{
	WIN_VALUE = 2048
};

typedef	struct			s_game
{
	int					tab[NBR_CASE][NBR_CASE];
	int					c;
	int					row;
	int					col;
	int					rd_nbr;
	int					mouv;
	int					fus;
	int					winner;
	int					error;
}						t_game;

int						ft_strlen(char *str);
int						game_play(t_game *game);
int						ft_menu(int type, t_game *game, char *str);
void					put_tab(t_game *game);
void					init_game(t_game *game);
void					random_nbr(t_game *game);
void					init_game(t_game *game);
int						how_does_it_look(t_game *game);
void					ft_feed_norme(t_game *game);
void					ft_key_type(t_game *game, int type);
int						ft_fusion(t_game *game, int type);
void					random_nbr(t_game *game);
void					put_tab(t_game *game);

#endif
