/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 02:18:04 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/26 17:04:13 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "sh.h"

static	int	is_error_setenv(char *name, char *content, char *overwrite)
{
	if (!name || !content || (overwrite && !ft_isnumber(overwrite)))
	{
		ft_putendl("usage: setenv name value [1]");
		return (1);
	}
	if ((ft_memchr(name, '=', ft_strlen(name))))
	{
		ft_putendl("setenv: name contains an '=' character");
		return (1);
	}
	return (0);
}

int			ft_setenv(t_env **env, char **command)
{
	t_env	*tmp_env;
	char	*cont;

	if (is_error_setenv(command[1], command[2], command[3]))
		return (1);
	if (command[2] && command[3] && command[4])
	{
		ft_putendl("setenv: too many arguments");
		return (1);
	}
	if ((tmp_env = get_env(env, command[1])))
	{
		if (!command[3] || ft_getnbr(command[3]) == 0)
			return (1);
		if ((cont = (char *)malloc(sizeof(char) * ft_strlen(command[2]) + 1)))
			tmp_env->content = ft_strcpy(cont, command[2]);
	}
	else if (!env)
		*env = new_env(command[1], command[2]);
	else
	{
		tmp_env = new_env(command[1], command[2]);
		add_end_env(env, tmp_env);
	}
	return (0);
}
