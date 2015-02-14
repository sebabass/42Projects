/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_themes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 02:42:30 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/15 04:23:47 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	mappemonde(t_point *p1, t_point *p2)
{
	if (p1->z <= 0 || p2->z <= 0)
		return (0x0000FF);
	else if (p1->z <= 20)
		return (0x00FF00);
	else if (p1->z <= 60)
		return (0x663300);
	else
		return (0xFFFFFF);
}

static	int	jungle(t_point *p1, t_point *p2)
{
	if (p1->z < p2->z || p1->z > p2->z)
		return (0x663300);
	else if (p1->z <= 0)
		return (0x007F2A);
	else
		return (0xF0B001);
}

static	int	solar(t_point *p1, t_point *p2)
{
	if (p1->z < p2->z || p1->z > p2->z)
		return (0x000000);
	else if (p1->z <= 0)
		return (0xFD0101);
	else
		return (0xFEF601);
}

int			get_color_theme(t_env *e, t_point *p1, t_point *p2)
{
	if (e->color_t == 0)
		return (mappemonde(p1, p2));
	else if (e->color_t == 1)
		return (jungle(p1, p2));
	else if (e->color_t == 2)
		return (solar(p1, p2));
	else
		return (0xFFFFFF);
}

void		change_color_theme(t_env *e, int kc)
{
	int		tmp_idcol;

	tmp_idcol = e->color_t;
	if (kc == 38)
		e->color_t = 0;
	else if (kc == 233)
		e->color_t = 1;
	else if (kc == 34)
		e->color_t = 2;
	if (e->color_t != tmp_idcol)
		draw(e);
}
