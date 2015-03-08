/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:16:21 by mfrisby           #+#    #+#             */
/*   Updated: 2015/03/01 12:11:14 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <ncurses.h>

void	put_tab(t_game *game)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		nbr;

	i = 0;
	x = 0;
	y = 0;
	while (i < NBR_CASE)
	{
		j = 0;
		x = ((game->row / NBR_CASE) * i) + ((game->row / NBR_CASE) / 2);
		while (j < NBR_CASE)
		{
			nbr = game->tab[i][j];
			y = ((game->col / NBR_CASE) * j) + ((game->col / NBR_CASE) / 2);
			if (game->tab[i][j] != 0)
				mvprintw(x, y, "%d", nbr);
			refresh();
			j++;
		}
		i++;
	}
}
