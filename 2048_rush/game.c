/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:14:16 by spariaud          #+#    #+#             */
/*   Updated: 2015/03/01 23:23:47 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <ncurses.h>

static	void	draw_line(t_game *game)
{
	int		i;

	i = 0;
	while (i < (NBR_CASE + 1))
	{
		whline(stdscr, ' ', (game->col - (game->col % NBR_CASE)));
		move((game->row / NBR_CASE) * i, 0);
		i++;
	}
	whline(stdscr, ' ', (game->col - (game->col % NBR_CASE)));
}

static	void	draw_col(t_game *game)
{
	int		i;

	i = 0;
	while (i < (NBR_CASE + 1))
	{
		wvline(stdscr, ' ', (game->row - (game->row % NBR_CASE)));
		move(0, (game->col / NBR_CASE) * i);
		i++;
	}
	wvline(stdscr, ' ', (game->row - (game->row % NBR_CASE) + 1));
}

static	int		draw_tab(t_game *game)
{
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLUE);
	attron(COLOR_PAIR(1));
	getmaxyx(stdscr, game->row, game->col);
	if (game->row <= NBR_CASE * 2)
	{
		mvprintw(0, 0, "Error size windows\n");
		game->error = 1;
		return (0);
	}
	game->row--;
	game->col--;
	draw_line(game);
	move(0, 0);
	draw_col(game);
	put_tab(game);
	attroff(COLOR_PAIR(1));
	return (1);
}

int				game_play(t_game *game)
{
	if (!game->error && !draw_tab(game))
		game->error = 1;
	while (!game->error && (game->c = getch()) != KEY_ESC)
	{
		ft_feed_norme(game);
		if (game->mouv || game->fus)
			random_nbr(game);
		how_does_it_look(game);
		if (game->error)
			return (0);
		clear();
		if (!game->error && !draw_tab(game))
			game->error = 1;
		refresh();
	}
	return (0);
}
