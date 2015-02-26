/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 04:51:39 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/14 19:24:57 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "wolf3d.h"

static	void	init_env(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->img = NULL;
	e->data = NULL;
	e->cursor = 0;
}

void			perror_exit(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

void			error_exit(char *error)
{
	ft_putendl(error);
	exit(EXIT_FAILURE);
}

int				main(void)
{
	t_env	e;

	init_env(&e);
	if (!(e.mlx = mlx_init()))
		error_exit("mlx : error mlx_init()");
	else
	{
		if (!(e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "Wolf3d")))
			error_exit("mlx: error mlx_new_window()");
		else if (MOVE_SPEED > 0.2)
			error_exit("wolf3d: init speed player failed()");
		else
		{
			load_map(&e, "map/lvl1.w3d");
			init_player(&e);
			mlx_hook(e.win, 3, 3, key_hook, &e);
			mlx_expose_hook(e.win, expose_hook, &e);
			mlx_loop(e.mlx);
		}
	}
	return (0);
}
