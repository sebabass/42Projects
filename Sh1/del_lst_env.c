/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 03:57:56 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/25 20:39:48 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh.h"
#include "libft.h"

static	void	free_elem(t_env *e)
{
	if (e)
	{
		free(e->name);
		free(e->content);
		free(e);
	}
}

void			del_begin_env(t_env **e)
{
	t_env	*tmp;

	if (*e)
	{
		tmp = (*e)->next;
		free_elem(*e);
		*e = tmp;
	}
}

void			del_middle_env(t_env **e, const char *name)
{
	t_env	*first;
	t_env	*prev;
	t_env	*next;

	first = *e;
	if (first->next && (ft_strcmp(first->name, name) != 0))
	{
		prev = first;
		next = prev->next;
		while (next && (ft_strcmp(next->name, name) != 0))
		{
			prev = next;
			next = prev->next;
		}
		if (next)
		{
			prev->next = next->next;
			free_elem(next);
		}
	}
	else
		del_begin_env(e);
}
