/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spoint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 09:51:44 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/20 10:38:10 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"
#include "fdf.h"

static	t_point	*new_tpoint(int x, int y, int z, t_env *e)
{
	t_point	*new;
	int		center_x;

	if (!(new = (t_point *)malloc(sizeof(t_point))))
		exit(EXIT_FAILURE);
	center_x = ((WIN_WIDTH / 2) - (WIN_WIDTH / 4));
	y += (WIN_HEIGHT / e->pad_line) / 2;
	x = x * 2;
	new->x = (x * e->pad_line) + (y * e->pad_line * 2) - center_x + (e->x1);
	new->y = (y * e->pad_line) - (x * e->pad_line / 2) -
		(z * ((e->pad_line / 3) * e->z1)) + e->y1;
	new->z = z;
	return (new);
}

static	int		get_nline_map(t_env *e)
{
	int		n_line;
	char	*line;

	n_line = 0;
	while (get_next_line(e->fd, &line))
		n_line++;
	if (close(e->fd) == -1)
	{
		perror("fdf :");
		exit(EXIT_FAILURE);
	}
	if ((e->fd = open(e->av, O_RDONLY)) == -1)
	{
		perror("fdf :");
		exit(EXIT_FAILURE);
	}
	return (n_line);
}

void			change_map(t_env *e)
{
	int		x;
	int		y;
	int		xtmp;
	int		ytmp;
	int		center_x;

	y = 0;
	center_x = ((WIN_WIDTH / 2) - (WIN_WIDTH / 4));
	while (e->map[y])
	{
		x = 0;
		while (e->map[y][x])
		{
			ytmp = y + ((WIN_HEIGHT / e->pad_line) / 2);
			xtmp = (x * 2);
			e->map[y][x]->x = (xtmp * e->pad_line) + (ytmp * e->pad_line * 2)
				- center_x + (e->x1);
			e->map[y][x]->y = (ytmp * e->pad_line) - (xtmp * e->pad_line / 2)
				- (e->map[y][x]->z * ((e->pad_line / 3) * e->z1)) + e->y1;
			x++;
		}
		y++;
	}
}

void			create_map_point(t_env *e, char *l, char **split, char *li)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	if (!e->n_line)
		e->n_line = get_nline_map(e);
	if (!(e->map = (t_point ***)malloc(sizeof(t_point **) * e->n_line)))
		exit(EXIT_FAILURE);
	while (get_next_line(e->fd, &l))
	{
		if (!(e->map[y] = (t_point **)malloc(sizeof(t_point *) * ft_strlen(l))))
			exit(EXIT_FAILURE);
		x = 0;
		i = -1;
		split = ft_strsplit(l, ' ');
		while ((li = split[++i]))
		{
			e->map[y][x] = new_tpoint(x, y, ft_getnbr(li), e);
			e->map[y][++x] = NULL;
		}
		e->map[++y] = NULL;
	}
}
