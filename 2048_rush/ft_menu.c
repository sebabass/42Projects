/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:56:47 by mfrisby           #+#    #+#             */
/*   Updated: 2015/03/01 22:48:07 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <game.h>

static	int	menu_end(t_game *game)
{
	char	*s;
	int		len;

	s = "YOU LOOSE! Look grid = 'ENTER' | Quit = 'ESC'";
	len = ft_strlen(s);
	getmaxyx(stdscr, game->row, game->col);
	clear();
	mvprintw(game->row / 2, (game->col / 2) - (len / 2), "%s", s);
	while ((game->c = getch()) != KEY_ENTER)
	{
		clear();
		if (game->c == KEY_ESC)
		{
			game->error = 1;
			return (0);
		}
		getmaxyx(stdscr, game->row, game->col);
		mvprintw(game->row / 2, (game->col / 2) - (len / 2), "%s", s);
		refresh();
	}
	clear();
	return (0);
}

static	int menu_victory(t_game *game)
{
	char	*s;
	int		len;

	s = "YOU WIN! Continue = 'ENTER' | Quit = 'ESC'";
	len = ft_strlen(s);
	getmaxyx(stdscr, game->row, game->col);
	clear();
	mvprintw(game->row / 2, (game->col / 2) - (len / 2), "%s", s);
	while ((game->c = getch()) != KEY_ENTER)
	{
		clear();
		if (game->c == KEY_ESC)
		{
			game->error = 1;
			return (0);
		}
		getmaxyx(stdscr, game->row, game->col);
		mvprintw(game->row / 2, (game->col / 2) - (len / 2), "%s", s);
		refresh();
	}
	clear();
	return (0);
}

static	int	menu_start(t_game *game)
{
	char	*s;
	int		len;

	s = "Rush 2048 Play = 'ENTER' | Quit 'ESC'";
	len = ft_strlen(s);
	getmaxyx(stdscr, game->row, game->col);
	mvprintw(game->row / 2, (game->col / 2) - (len / 2), "%s", s);
	while ((game->c = getch()) != KEY_ESC)
	{
		getmaxyx(stdscr, game->row, game->col);
		if (game->c == KEY_ENTER)
		{
			clear();
			return (PLAY);
		}
		clear();
		mvprintw(game->row / 2, (game->col / 2) - (len / 2), "%s", s);
		refresh();
	}
	clear();
	return (0);
}

static	int menu_error(t_game *game, char *s)
{
	int		len;

	len = ft_strlen(s);
	clear();
	getmaxyx(stdscr, game->row, game->col);
	mvprintw(game->row / 2, (game->col / 2) - (len / 2), "%s", s);
	while ((game->c = getch()) != KEY_ESC)
	{
		getmaxyx(stdscr, game->row, game->col);
		clear();
		mvprintw(game->row / 2, (game->col / 2) - (len / 2), "%s", s);
		refresh();
	}
	game->error = 1;
	clear();
	return (0);
}

int			ft_menu(int type, t_game *game, char *str)
{
	if (type == START)
		return (menu_start(game));
	if (type == END)
		return (menu_end(game));
	if (type == VICTORY)
		return (menu_victory(game));
	if (type == ERROR)
		return (menu_error(game, str));
	return (0);
}
