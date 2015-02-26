/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 06:07:34 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/14 18:44:41 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void	move_forward(t_env *e, int speed)
{
	int		t_x;
	int		t_y;

	t_x = e->player.pos.x + e->player.dir.x * MOVE_SPEED * speed;
	t_y = e->player.pos.y + e->player.dir.y * MOVE_SPEED * speed;
	if (e->map.tab[(int)(t_x)][(int)(e->player.pos.y)] != 1)
		e->player.pos.x += e->player.dir.x * MOVE_SPEED * speed;
	if (e->map.tab[(int)(e->player.pos.x)][(int)(t_y)] != 1)
		e->player.pos.y += e->player.dir.y * MOVE_SPEED * speed;
	draw(e);
}

void	move_back(t_env *e, int speed)
{
	int		t_x;
	int		t_y;

	t_x = e->player.pos.x - e->player.dir.x * MOVE_SPEED * speed;
	t_y = e->player.pos.y - e->player.dir.y * MOVE_SPEED * speed;
	if (e->map.tab[(int)(t_x)][(int)(e->player.pos.y)] == 0)
		e->player.pos.x -= e->player.dir.x * MOVE_SPEED * speed;
	if (e->map.tab[(int)(e->player.pos.x)][(int)(t_y)] == 0)
		e->player.pos.y -= e->player.dir.y * MOVE_SPEED * speed;
	draw(e);
}

void	rotate_right(t_env *e)
{
	double	dir_old_x;
	double	plane_old_x;

	dir_old_x = e->player.dir.x;
	plane_old_x = e->player.plane.x;
	e->player.dir.x = e->player.dir.x * cos(-ROTATE_SPEED) - e->player.dir.y
		* sin(-ROTATE_SPEED);
	e->player.dir.y = dir_old_x * sin(-ROTATE_SPEED) + e->player.dir.y
		* cos(-ROTATE_SPEED);
	e->player.plane.x = e->player.plane.x * cos(-ROTATE_SPEED)
		- e->player.plane.y * sin(-ROTATE_SPEED);
	e->player.plane.y = plane_old_x * sin(-ROTATE_SPEED) + e->player.plane.y
		* cos(-ROTATE_SPEED);
	draw(e);
}

void	rotate_left(t_env *e)
{
	double	dir_old_x;
	double	plane_old_x;

	dir_old_x = e->player.dir.x;
	plane_old_x = e->player.plane.x;
	e->player.dir.x = e->player.dir.x * cos(ROTATE_SPEED) - e->player.dir.y
		* sin(ROTATE_SPEED);
	e->player.dir.y = dir_old_x * sin(ROTATE_SPEED) + e->player.dir.y
		* cos(ROTATE_SPEED);
	e->player.plane.x = e->player.plane.x * cos(ROTATE_SPEED)
		- e->player.plane.y * sin(ROTATE_SPEED);
	e->player.plane.y = plane_old_x * sin(ROTATE_SPEED) + e->player.plane.y
		* cos(ROTATE_SPEED);
	draw(e);
}
