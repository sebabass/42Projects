/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 09:02:17 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/14 19:04:38 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "wolf3d.h"
#include "libft.h"

void	draw(t_env *e)
{
	if (!(e->img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT)))
		error_exit("mlx : error mlx_new_image()");
	else
	{
		e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
		if (!e->data)
			error_exit("mlx : error data");
		raycast(e, &e->player);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_destroy_image(e->mlx, e->img);
	}
}

int		expose_hook(t_env *e)
{
	rotate_left(e);
	draw(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == ESCAPE)
		exit(EXIT_SUCCESS);
	if (keycode == KEY_RIGHT)
		rotate_right(e);
	if (keycode == KEY_LEFT)
		rotate_left(e);
	if (keycode == KEY_UP)
		move_forward(e, 1);
	if (keycode == KEY_DOWN)
		move_back(e, 1);
	if (keycode == RUN_FORWARD)
		move_forward(e, 2);
	if (keycode == RUN_BACK)
		move_back(e, 2);
	return (0);
}
