/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 00:26:11 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/16 15:48:29 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

void		activate(t_env *e, int kc)
{
	if (kc == 104)
	{
		if (e->is_help)
			e->is_help = 0;
		else
			e->is_help = 1;
	}
	else if (kc == 99)
	{
		if (e->is_color)
			e->is_color = 0;
		else
			e->is_color = 1;
	}
	else if (kc == 108)
	{
		if (e->is_file)
			e->is_file = 0;
		else
			e->is_file = 1;
	}
	draw(e);
}

void		reset(t_env *e)
{
	e->is_help = 0;
	e->is_color = 0;
	e->is_file = 0;
	e->x1 = 0;
	e->y1 = 0;
	e->z1 = Z_BASE;
	e->pad_line = 10;
	e->color_t = 0;
	e->zoom = ZOOM_BASE;
	draw(e);
}

void		zoom(t_env *e, int value, int zm)
{
	int		tmp;
	int		zoom;

	tmp = e->pad_line + value;
	zoom = e->zoom + zm;
	if (tmp > 0 && zoom <= ZOOM_MAX && zoom >= ZOOM_MIN)
	{
		e->zoom += zm;
		e->pad_line += value;
		draw(e);
	}
}

void		move(t_env *e, int c, float value)
{
	int		tmp_z;

	tmp_z = e->z1 + value;
	if ((c == 'x' || c == 'y' || c == 'z'))
	{
		if (c == 'x')
			e->x1 += value;
		else if (c == 'y')
			e->y1 += value;
		else
		{
			if (e->zoom > ZOOM_MIN)
			{
				if (tmp_z >= Z_DWN_MAX && tmp_z <= Z_UP_MAX)
					e->z1 += value;
			}
		}
		draw(e);
	}
}
