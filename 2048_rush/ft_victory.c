/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_victory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:07:37 by mfrisby           #+#    #+#             */
/*   Updated: 2015/03/01 22:55:14 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include "game.h"

static	int		ft_look_good(t_game *game)
{
	int				i;
	int				j;

	i = -1;
	while (++i < NBR_CASE)
	{
		j = -1;
		while (++j <= NBR_CASE)
		{
			if (game->tab[i][j] == WIN_VALUE && !game->winner)
			{
				game->winner = 1;
				flash();
				return (1);
			}
		}
	}
	return (0);
}

static	int		ft_look_bad(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < NBR_CASE)
	{
		j = -1;
		while (++j <= NBR_CASE)
		{
			if (game->tab[i][j] == 0)
				return (0);
			if ((j + 1) < NBR_CASE && (game->tab[i][j] == game->tab[i][j + 1]))
				return (0);
			if ((i + 1) < NBR_CASE && (game->tab[i][j] == game->tab[i + 1][j]))
				return (0);
		}
	}
	return (-1);
}

static	int		ft_win_value(void)
{
	int		i;

	i = 2;
	if (WIN_VALUE < 2 || WIN_VALUE > 131072)
		return (-1);
	while (i < WIN_VALUE)
		i *= 2;
	if (i != WIN_VALUE)
		return (-1);
	return (0);
}

int				how_does_it_look(t_game *game)
{
	int ret;

	ret = 0;
	if ((ft_win_value()) < 0)
		ft_menu(ERROR, game, "Error WIN_VALUE quit = 'ESC'");
	else if ((ft_look_good(game)) > 0)
	{
		ft_menu(VICTORY, game, "victory");
		return (1);
	}
	else if ((ft_look_bad(game)) < 0)
	{
		flash();
		ft_menu(END, game, "END");
		return (-1);
	}
	return (ret);
}
