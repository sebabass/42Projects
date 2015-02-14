/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 13:54:26 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/16 11:26:28 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "libft.h"

void	put_menu_help(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 40, 0xFF0000, "1-MOVE [Arrow keys]");
	if (e->zoom == ZOOM_MAX)
		mlx_string_put(e->mlx, e->win, 10, 55, 0x00FF00, "2-ZOOM [-]");
	else if (e->zoom == ZOOM_MIN)
		mlx_string_put(e->mlx, e->win, 10, 55, 0x00FF00, "2-ZOOM [+]");
	else
		mlx_string_put(e->mlx, e->win, 10, 55, 0x00FF00, "2-ZOOM [+][-]");
	if (e->zoom != ZOOM_MIN)
		mlx_string_put(e->mlx, e->win, 10, 70, 0xFF0000, "3-DEPTH +/- [8]/[2]");
	mlx_string_put(e->mlx, e->win, 10, 85, 0x00FF00, "4-RESET [DEL]");
	mlx_string_put(e->mlx, e->win, 10, 100, 0xFF0000, "5-EXIT [ESC]");
}

void	put_menu_color_theme(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 210, 40, 0xFF0000, "1-MAPP [!1]");
	mlx_string_put(e->mlx, e->win, 210, 55, 0x00FF00, "2-JUNGLE [@2]");
	mlx_string_put(e->mlx, e->win, 210, 70, 0xFF0000, "3-SOLAR [#3]");
}

void	put_menu_file(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 410, 40, 0xFFFFFF, "MAP ACTUEL :");
	mlx_string_put(e->mlx, e->win, 410, 60, 0x00FDF4, e->av);
}
