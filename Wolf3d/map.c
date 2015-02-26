/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 11:17:08 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/29 20:54:39 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "get_next_line.h"
#include "wolf3d.h"

void		put_map_console(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < MAP_HEIGHT)
	{
		j = -1;
		while (++j < MAP_WIDTH)
		{
			ft_putstr("{[");
			ft_putnbr(i);
			ft_putstr(",");
			ft_putnbr(j);
			ft_putstr("]");
			ft_putnbr(map->tab[i][j]);
			ft_putstr("}");
		}
		ft_putchar('\n');
	}
}

void		load_map(t_env *e, char *path_map)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**split;

	e->map.name = path_map;
	if (!(e->map.tab = (int **)malloc(sizeof(int *) * MAP_HEIGHT)))
		error_exit("wolf3d : error malloc load_map()");
	i = -1;
	fd = open_file(e->map.name);
	while (get_next_line(fd, &line))
	{
		j = -1;
		if (!(e->map.tab[++i] = (int *)malloc(sizeof(int) * MAP_WIDTH)))
			error_exit("wolf3d : error malloc load_map()");
		split = ft_strsplit(line, ';');
		while (split[++j])
			e->map.tab[i][j] = ft_getnbr(split[j]);
	}
	close_file(fd);
}
