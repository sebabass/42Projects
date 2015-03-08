/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 03:09:16 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/26 03:42:36 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft.h"

int		ft_unsetenv(t_env **env, char **command)
{
	if (!command[1])
	{
		ft_putendl("unsetenv: [name] name is null");
		return (1);
	}
	if (command[2])
	{
		ft_putendl("usentenv: [name] Too many arguments");
		return (1);
	}
	if (*env && get_env(env, command[1]))
		del_middle_env(env, command[1]);
	else
	{
		ft_putstr("unsetenv: Variable of environment untraceable ");
		ft_putendl(command[1]);
		return (1);
	}
	return (0);
}
