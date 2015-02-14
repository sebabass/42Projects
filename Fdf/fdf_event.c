/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 13:44:04 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/16 16:29:42 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>

void	draw_img(t_env *e)
{
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->n_point_line, &e->endian);
	if (!e->data)
	{
		perror("fdf :");
		exit(EXIT_FAILURE);
	}
	else
		put_map(e, -1, -1);
}

void	draw(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	draw_img(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 10, 20, 0xFFFF00, "[H]--- HELP ---[H]");
	mlx_string_put(e->mlx, e->win, 210, 20, 0xFFFF00, "[C]--- COLOR ---[C]");
	mlx_string_put(e->mlx, e->win, 410, 20, 0xFFFF00, "[L]--- LOAD MAP ---[L]");
	if (e->is_help)
		put_menu_help(e);
	if (e->is_color)
		put_menu_color_theme(e);
	if (e->is_file)
		put_menu_file(e);
	mlx_destroy_image(e->mlx, e->img);
}

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		key_release(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65451)
		zoom(e, 2, 1);
	if (keycode == 65453)
		zoom(e, -2, -1);
	if (keycode == 104 || keycode == 99 || keycode == 108)
		activate(e, keycode);
	if (keycode == 38 || keycode == 233 || keycode == 34)
		change_color_theme(e, keycode);
	if (keycode == 65535)
		reset(e);
	return (0);
}

int		key_press(int keycode, t_env *e)
{
	if (keycode == 65362)
		move(e, 'y', -30);
	if (keycode == 65364)
		move(e, 'y', 30);
	if (keycode == 65361)
		move(e, 'x', -30);
	if (keycode == 65363)
		move(e, 'x', 30);
	if (keycode == 65464)
		move(e, 'z', 0.1);
	if (keycode == 65458)
		move(e, 'z', -0.1);
	return (0);
}
