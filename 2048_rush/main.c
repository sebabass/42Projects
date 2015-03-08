/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:15:19 by spariaud          #+#    #+#             */
/*   Updated: 2015/03/01 23:20:03 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

static	int	init_m(t_game *game)
{
	srand(time(NULL));
	if (!initscr())
	{
		ft_menu(ERROR, game, "Error init screen");
		return (1);
	}
	if (NBR_CASE < 4 || NBR_CASE > 10)
	{
		ft_menu(ERROR, game, "Error NBR_CASE usage: 4 <---> 10 Quit = 'ESC'");
		return (0);
	}
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	return (1);
}

int			main(void)
{
	t_game		game;

	if (!init_m(&game))
	{
		endwin();
		return (0);
	}
	init_game(&game);
	how_does_it_look(&game);
	if (game.error)
	{
		endwin();
		return (0);
	}
	if (ft_menu(START, &game, "start") == PLAY)
		game_play(&game);
	endwin();
	clear();
	return (0);
}
