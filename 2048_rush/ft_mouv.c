/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:23:44 by mfrisby           #+#    #+#             */
/*   Updated: 2015/03/01 21:09:22 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include "game.h"

static void		ft_key_down(t_game *game)
{
	int		i;
	int		j;
	int		k;

	i = NBR_CASE;
	game->mouv = 0;
	while (--i >= 0)
	{
		j = NBR_CASE;
		while (--j >= 0)
		{
			if ((i - 1) >= 0 && game->tab[i - 1][j] != 0)
			{
				k = i;
				while (k < NBR_CASE && game->tab[k][j] == 0)
				{
					game->tab[k][j] = game->tab[i - 1][j];
					game->tab[i - 1][j] = 0;
					k++;
					i++;
					game->mouv = 1;
				}
			}
		}
	}
}

static void		ft_key_up(t_game *game)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	game->mouv = 0;
	while (++i < NBR_CASE)
	{
		j = -1;
		while (++j < NBR_CASE)
		{
			if ((i + 1) < NBR_CASE && game->tab[i + 1][j] != 0)
			{
				k = i;
				while (k >= 0 && game->tab[k][j] == 0)
				{
					game->tab[k][j] = game->tab[i + 1][j];
					game->tab[i + 1][j] = 0;
					k--;
					i--;
					game->mouv = 1;
				}
			}
		}
	}
}

static void		ft_key_right(t_game *game)
{
	int		i;
	int		j;
	int		k;

	i = NBR_CASE;
	game->mouv = 0;
	while (--i >= 0)
	{
		j = NBR_CASE;
		while (--j >= 0)
		{
			if ((j - 1) >= 0 && game->tab[i][j - 1] != 0)
			{
				k = j;
				while (k < NBR_CASE && game->tab[i][k] == 0)
				{
					game->tab[i][k] = game->tab[i][j - 1];
					game->tab[i][j - 1] = 0;
					k++;
					j++;
					game->mouv = 1;
				}
			}
		}
	}
}

static void		ft_key_left(t_game *game)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	game->mouv = 0;
	while (++i < NBR_CASE)
	{
		j = -1;
		while (++j < NBR_CASE)
		{
			if ((j + 1) < NBR_CASE && game->tab[i][j + 1] != 0)
			{
				k = j;
				while (k >= 0 && game->tab[i][k] == 0)
				{
					game->tab[i][k] = game->tab[i][j + 1];
					game->tab[i][j + 1] = 0;
					k--;
					j--;
					game->mouv = 1;
				}
			}
		}
	}
}

void			ft_key_type(t_game *game, int type)
{
	if (type == UP)
		ft_key_up(game);
	if (type == DOWN)
		ft_key_down(game);
	if (type == RIGHT)
		ft_key_right(game);
	if (type == LEFT)
		ft_key_left(game);
}
