/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 02:07:01 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/26 03:58:37 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "libft.h"
#include "sh.h"

int				set_old_pwd(t_env **env, char *str_free)
{
	t_env	*pwd;
	t_env	*old_pwd;

	if ((pwd = get_env(env, "PWD")))
	{
		if ((old_pwd = get_env(env, "OLDPWD")))
		{
			old_pwd->content = pwd->content;
			return (1);
		}
		else
			ft_putendl("cd: Variable of environment untraceable OLDPWD");
	}
	else
		ft_putendl("cd: Variable of environment untraceable PWD");
	if (str_free)
		free(str_free);
	return (0);
}

static	int		cd_home_path(t_env **env, const char *path)
{
	t_env	*env_home;
	t_env	*env_pwd;
	char	*updt;

	if ((env_home = get_env(env, "HOME")))
	{
		if ((env_pwd = get_env(env, "PWD")))
		{
			if (!(updt = (char *)malloc(sizeof(char) * ft_strlen(path) + 1)))
				return (1);
			updt = ft_strsub(path, 1, (ft_strlen(path) - 1));
			if (chdir(ft_strjoin(env_home->content, updt)) == -1)
				return (cd_error(ft_strjoin(env_home->content, updt), 0));
			if (!set_old_pwd(env, updt))
				return (1);
			env_pwd->content = ft_strjoin(env_home->content, updt);
			return (0);
		}
		else
			ft_putendl("cd: Variable of environment untraceable PWD");
	}
	else
		ft_putendl("cd: Variable of environment untraceable HOME");
	return (1);
}

static	int		cd_home(t_env **env)
{
	t_env	*env_home;
	t_env	*env_pwd;

	if (!set_old_pwd(env, NULL))
		return (1);
	if ((env_home = get_env(env, "HOME")))
	{
		if ((env_pwd = get_env(env, "PWD")))
		{
			if (chdir(env_home->content) == -1)
				cd_error(env_home->content, 0);
			env_pwd->content = env_home->content;
			return (0);
		}
		else
			ft_putendl("cd: Variable of environment untraceable PWD");
	}
	ft_putendl("cd: Variable of environment untraceable HOME");
	return (1);
}

int				ft_cd(t_env **env, char **command)
{
	t_env	*tmp_env;
	char	*buf;

	if (command[3])
		return (cd_error(command[0], 3));
	if (!command[1] || ((ft_strcmp(command[1], "~") == 0)))
		return (cd_home(env));
	if (command[1][0] == '~' && command[1][1] && command[1][1] == '/')
		return (cd_home_path(env, command[1]));
	if (cd_error(command[1], 0) || chdir(command[1]) == -1)
		return (1);
	if ((tmp_env = get_env(env, "PWD")))
	{
		buf = (char *)malloc(sizeof(char) * PATH_MX);
		buf = getcwd(buf, PATH_MX);
		if (!set_old_pwd(env, buf))
			return (1);
		tmp_env->content = ft_strdup(buf);
		free(buf);
		return (0);
	}
	ft_putendl("cd: Variable of environment untraceable PWD");
	return (0);
}
