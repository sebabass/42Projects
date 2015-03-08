/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 02:13:24 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/26 17:02:37 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft.h"

static	int	env_command(t_env **e, char **command, char **env)
{
	char	**path_tab;

	if ((path_tab = get_path_tab(e)))
		check_command(path_tab, command, env);
	return (0);
}

static	int	opt_env(t_env **e, char **command, char **env)
{
	if ((ft_strcmp(command[1], "-i") == 0) && command[2])
	{
		ft_putstr(ft_strjoin("zsh: ", command[2]));
		ft_putendl(": No such file or directory");
	}
	else if (command[1][0] == '-' && (ft_strcmp(command[1], "-i") != 0))
	{
		ft_putendl("env illegal option");
		ft_putendl("usage: env [-i]");
	}
	else if ((ft_strcmp(command[1], "-i") != 0))
		env_command(e, command, env);
	return (0);
}

int			ft_env(t_env **e, char **command, char **env)
{
	t_env	*tmp_env;

	tmp_env = *e;
	if (!command[1])
	{
		while (tmp_env)
		{
			ft_putstr(tmp_env->name);
			ft_putchar('=');
			if (tmp_env->content)
				ft_putendl(tmp_env->content);
			tmp_env = tmp_env->next;
		}
		return (0);
	}
	return (opt_env(e, command, env));
}
