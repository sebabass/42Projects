/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 05:24:36 by spariaud          #+#    #+#             */
/*   Updated: 2015/03/01 22:02:38 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include "game.h"

static	void	init_tab(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < NBR_CASE)
	{
		j = -1;
		while (++j < NBR_CASE)
			game->tab[i][j] = 0;
	}
	random_nbr(game);
	random_nbr(game);
}

void			init_game(t_game *game)
{
	game->c = 0;
	game->row = 0;
	game->col = 0;
	game->mouv = 0;
	game->fus = 0;
	game->winner = 0;
	game->error = 0;
	init_tab(game);
}
