/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:11:02 by mfrisby           #+#    #+#             */
/*   Updated: 2015/03/01 13:06:09 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>

static int		check_rand_nbr(int nbr)
{
	if (nbr <= 2)
		return (2);
	else
		return (4);
}

void			random_nbr(t_game *game)
{
	int			rdx;
	int			rdy;
	int			empty;

	empty = 0;
	while (!empty)
	{
		rdx = rand() % NBR_CASE;
		rdy = rand() % NBR_CASE;
		if (game->tab[rdx][rdy] == 0)
			empty = 1;
	}
	game->rd_nbr = rand() % NBR_CASE;
	game->rd_nbr = check_rand_nbr(game->rd_nbr);
	game->tab[rdx][rdy] = game->rd_nbr;
}
