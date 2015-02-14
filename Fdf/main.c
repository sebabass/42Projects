/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 11:45:31 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/27 16:27:59 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include "libft.h"

static	void	init(t_env *e, char *argv)
{
	e->img = NULL;
	e->data = NULL;
	e->map = NULL;
	e->n_point_line = 0;
	e->n_line = 0;
	e->is_help = 0;
	e->is_color = 0;
	e->is_file = 0;
	e->color_t = 0;
	e->x1 = 0;
	e->y1 = 0;
	e->z1 = Z_BASE;
	e->zoom = ZOOM_BASE;
	e->av = argv;
	e->pad_line = 10;
}

static	void	check_init_error(t_env *e, char *argv)
{
	int		is_error;

	is_error = 0;
	if ((e->mlx = mlx_init()))
	{
		if ((e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "MY FDF")))
			init(e, argv);
		else
			is_error = 1;
	}
	else
		is_error = 1;
	if (is_error)
	{
		perror("fdf");
		if (close(e->fd) == -1)
			perror("fdf");
		exit(EXIT_FAILURE);
	}
}

int				main(int argc, char **argv)
{
	t_env	e;

	if ((argc - 1) == 1)
	{
		if ((e.fd = open(argv[1], O_RDWR)) == -1)
		{
			perror("fdf");
			exit(EXIT_FAILURE);
		}
		else
		{
			check_init_error(&e, argv[1]);
			mlx_hook(e.win, 3, (1L << 1), key_release, &e);
			mlx_hook(e.win, 2, (1L << 0), key_press, &e);
			mlx_expose_hook(e.win, expose_hook, &e);
			mlx_loop(e.mlx);
		}
	}
	else
		ft_putendl_fd("Error 1 expected argument", 2);
	return (0);
}
