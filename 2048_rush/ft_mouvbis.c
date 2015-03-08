/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouvbis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 21:35:03 by mfrisby           #+#    #+#             */
/*   Updated: 2015/03/01 19:08:18 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include "game.h"

static int		ft_fusiondown(t_game *game)
{
	int i;
	int j;
	int ret;

	i = NBR_CASE;
	ret = 0;
	game->fus = 0;
	while (--i >= 0)
	{
		j = NBR_CASE;
		while (--j >= 0)
		{
			if (i - 1 >= 0 && game->tab[i - 1][j] == game->tab[i][j])
			{
				if (game->tab[i][j] != 0 && game->tab[i - 1][j] != 0)
				{
					game->tab[i][j] *= 2;
					game->tab[i - 1][j] = 0;
					ret = 1;
					game->fus = 1;
				}
			}
		}
	}
	return (ret);
}

static int		ft_fusionup(t_game *game)
{
	int i;
	int j;
	int ret;

	i = -1;
	ret = 0;
	game->fus = 0;
	while (++i < NBR_CASE)
	{
		j = -1;
		while (++j < NBR_CASE)
		{
			if (i + 1 < NBR_CASE && game->tab[i + 1][j] == game->tab[i][j])
			{
				if (game->tab[i][j] != 0 && game->tab[i + 1][j] != 0)
				{
					game->tab[i][j] *= 2;
					game->tab[i + 1][j] = 0;
					ret = 1;
					game->fus = 1;
				}
			}
		}
	}
	return (ret);
}

static int		ft_fusionright(t_game *game)
{
	int i;
	int j;
	int ret;

	i = NBR_CASE;
	ret = 0;
	game->fus = 0;
	while (--i >= 0)
	{
		j = NBR_CASE;
		while (--j >= 0)
		{
			if (j - 1 >= 0 && game->tab[i][j - 1] == game->tab[i][j])
			{
				if (game->tab[i][j] != 0 && game->tab[i][j - 1] != 0)
				{
					game->tab[i][j] *= 2;
					game->tab[i][j - 1] = 0;
					ret = 1;
					game->fus = 1;
				}
			}
		}
	}
	return (ret);
}

static int		ft_fusionleft(t_game *game)
{
	int i;
	int j;
	int ret;

	i = -1;
	ret = 0;
	game->fus = 0;
	while (++i < NBR_CASE)
	{
		j = -1;
		while (++j < NBR_CASE)
		{
			if (j + 1 < NBR_CASE && game->tab[i][j + 1] == game->tab[i][j])
			{
				if (game->tab[i][j] != 0 && game->tab[i][j + 1] != 0)
				{
					game->tab[i][j] *= 2;
					game->tab[i][j + 1] = 0;
					ret = 1;
					game->fus = 1;
				}
			}
		}
	}
	return (ret);
}

int				ft_fusion(t_game *game, int type)
{
	if (type == LEFT)
		return (ft_fusionleft(game));
	if (type == RIGHT)
		return (ft_fusionright(game));
	if (type == UP)
		return (ft_fusionup(game));
	if (type == DOWN)
		return (ft_fusiondown(game));
	return (0);
}
