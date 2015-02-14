/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 02:16:00 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/16 15:17:59 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mlx.h>

static	void	put_pixel(t_env *e, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = color & 0xFF;
	x *= 2;
	if (x >= 0 && y >= 0 && x < WIN_WIDTH * 2 && y <= WIN_HEIGHT)
	{
		e->data[(y * e->n_point_line) + (2 * x) + 2] = r;
		e->data[(y * e->n_point_line) + (2 * x) + 1] = g;
		e->data[(y * e->n_point_line) + (2 * x)] = b;
	}
}

static	void	put_line(t_env *e, t_point *p1, t_point *p2)
{
	int				color;
	float			i;
	int				param_y;

	i = p1->x;
	color = get_color_theme(e, p1, p2);
	while (i < p2->x)
	{
		param_y = p1->y + (((p2->y - p1->y) * (i - p1->x)) / (p2->x - p1->x));
		put_pixel(e, i, param_y, color);
		i += 0.1;
	}
}

void			free_map(t_env *e, int i, int j)
{
	while (e->map[++i])
	{
		j = -1;
		while (e->map[i][++j])
			free(e->map[i][j]);
		free(e->map[i]);
	}
	free(e->map);
	e->map = NULL;
}

void			put_map(t_env *e, int x, int y)
{
	if (!e->map)
	{
		create_map_point(e, NULL, NULL, NULL);
		if (close(e->fd) == -1)
		{
			perror("fdf");
			exit(EXIT_FAILURE);
		}
	}
	else
		change_map(e);
	while (e->map[++y])
	{
		x = -1;
		while (e->map[y][++x])
		{
			if (x > 0 && e->map[y][x - 1])
				put_line(e, e->map[y][x - 1], e->map[y][x]);
			if (y > 0 && e->map[y - 1][0] && e->map[y - 1][x])
				put_line(e, e->map[y - 1][x], e->map[y][x]);
		}
	}
}
