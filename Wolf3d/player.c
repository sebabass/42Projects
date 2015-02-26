/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:09:22 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/14 18:47:30 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "wolf3d.h"

static	t_vector		get_pos_player(t_map *map)
{
	int			i;
	int			j;
	t_vector	pos;

	i = -1;
	pos.x = -1;
	pos.y = -1;
	while (++i < MAP_HEIGHT)
	{
		j = -1;
		while (++j < MAP_WIDTH)
		{
			if (map->tab[i][j] == 2)
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
		}
	}
	return (pos);
}

void					init_player(t_env *e)
{
	e->player.pos = get_pos_player(&e->map);
	e->player.dir.x = -1;
	e->player.dir.y = 0;
	e->player.plane.x = 0;
	e->player.plane.y = 0.66;
	if (e->player.pos.x <= -1 || e->player.pos.y <= -1)
		error_exit("wolf3d : Position unknown player or disabled person");
}
