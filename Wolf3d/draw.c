/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 05:59:47 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/18 13:57:06 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "wolf3d.h"
#include "libft.h"

void		put_pixel(t_env *e, int x, int y, int color)
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
		e->data[(y * e->sizeline) + (2 * x) + 2] = r;
		e->data[(y * e->sizeline) + (2 * x) + 1] = g;
		e->data[(y * e->sizeline) + (2 * x)] = b;
	}
}

void		draw_col_wall(t_env *e, int x)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < WIN_HEIGHT)
	{
		if (i < ((WIN_HEIGHT / 2) - (e->player.wall_height / 2)))
			put_pixel(e, x, i, 0x0186C8);
		else if (j < e->player.wall_height)
		{
			if (e->player.secret)
			{
				e->player.secret = 0;
				put_pixel(e, x, i, 0x000000);
			}
			else
				put_pixel(e, x, i, e->player.color);
			j++;
		}
		else
			put_pixel(e, x, i, 0xF6E497);
		i++;
	}
}
