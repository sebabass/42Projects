/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 01:17:49 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/18 13:41:39 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf3d.h"
#include "libft.h"

static	void	check_wall(t_player *p, t_map *map)
{
	int		is_wall;

	is_wall = 0;
	while (!is_wall)
	{
		if (p->dist_wall.x < p->dist_wall.y)
		{
			p->dist_wall.x += p->dist2_wall.x;
			p->tmp_map.x += p->tmp_x;
			p->is_ver_hor = 0;
		}
		else
		{
			p->dist_wall.y += p->dist2_wall.y;
			p->tmp_map.y += p->tmp_y;
			p->is_ver_hor = 1;
		}
		if (map->tab[p->tmp_map.x][p->tmp_map.y] == 1)
			is_wall = 1;
		if (map->tab[p->tmp_map.x][p->tmp_map.y] == 3)
		{
			p->secret = 1;
			is_wall = 1;
		}
	}
}

static	void	raycast_x_y(t_player *p, t_map *map)
{
	float	f;

	f = 0;
	check_wall(p, map);
	if (p->is_ver_hor == 0)
	{
		f = fabs((p->tmp_map.x - p->ray_pos.x + (1 - p->tmp_x) / 2)
			/ p->ray_dir.x);
		p->wall_width = f;
		if (p->ray_dir.x > 0)
			p->color = 0x00FF00;
		else
			p->color = 0xFF0000;
	}
	else
	{
		if (p->ray_dir.y > 0)
			p->color = 0x0000FF;
		else
			p->color = 0xFFFF00;
		f = fabs((p->tmp_map.y - p->ray_pos.y + (1 - p->tmp_y) / 2)
			/ p->ray_dir.y);
		p->wall_width = f;
	}
	p->wall_height = fabs((int)(WIN_HEIGHT / p->wall_width));
}

static	void	raycast_dir_y(t_player *p)
{
	if (p->ray_dir.y < 0)
	{
		p->tmp_y = -1;
		p->dist_wall.y = (p->ray_pos.y - p->tmp_map.y) * p->dist2_wall.y;
	}
	else
	{
		p->tmp_y = 1;
		p->dist_wall.y = (p->tmp_map.y + 1.0 - p->ray_pos.y) * p->dist2_wall.y;
	}
}

static	void	raycast_dir_x(t_player *p)
{
	if (p->ray_dir.x < 0)
	{
		p->tmp_x = -1;
		p->dist_wall.x = (p->ray_pos.x - p->tmp_map.x) * p->dist2_wall.x;
	}
	else
	{
		p->tmp_x = 1;
		p->dist_wall.x = (p->tmp_map.x + 1.0 - p->ray_pos.x) * p->dist2_wall.x;
	}
}

void			raycast(t_env *e, t_player *p)
{
	int		i;

	i = 0;
	while (i < WIN_WIDTH)
	{
		p->cam_x = 2 * i / (double)WIN_WIDTH - 1;
		p->ray_pos.x = p->pos.x;
		p->ray_pos.y = p->pos.y;
		p->ray_dir.x = p->dir.x + p->plane.x * p->cam_x;
		p->ray_dir.y = p->dir.y + p->plane.y * p->cam_x;
		p->tmp_map.x = (int)p->ray_pos.x;
		p->tmp_map.y = (int)p->ray_pos.y;
		p->dist2_wall.x = sqrt(1 + (p->ray_dir.y * p->ray_dir.y)
			/ (p->ray_dir.x * p->ray_dir.x));
		p->dist2_wall.y = sqrt(1 + (p->ray_dir.x * p->ray_dir.x)
			/ (p->ray_dir.y * p->ray_dir.y));
		raycast_dir_x(p);
		raycast_dir_y(p);
		raycast_x_y(p, &e->map);
		draw_col_wall(e, i);
		i++;
	}
}
