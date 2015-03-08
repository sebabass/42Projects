/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 14:18:22 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/26 17:14:38 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "sh.h"

static	void	signal_c(int sign)
{
	if (sign)
	{
		ft_putstr(SIGNALDEL);
		ft_putstr("\n$> ");
	}
}

static	void	signal_no(int sign)
{
	if (sign)
		ft_putstr(SIGNALDEL);
}

void			ft_signal(void)
{
	signal(SIGTSTP, signal_no);
	signal(SIGINT, signal_c);
	signal(SIGQUIT, signal_no);
}

char			**get_path_tab(t_env **env)
{
	char	**path_tab;
	t_env	*tmp_env;
	char	*ss;

	tmp_env = NULL;
	if ((tmp_env = get_env(env, "PATH")))
		path_tab = ft_strsplit(tmp_env->content, ':');
	else
	{
		ss = "/usr/local/bin:/usr/bin:/bin";
		path_tab = ft_strsplit(ss, ':');
	}
	return (path_tab);
}

t_env			*env_default(void)
{
	t_env	*ret;
	t_env	*new;
	char	*buf;

	if (!(buf = (char *)malloc(sizeof(char) * PATH_MX)))
		exit(EXIT_FAILURE);
	buf = getcwd(buf, PATH_MX);
	ret = new_env("PWD", buf);
	new = new_env("OLDPWD", buf);
	add_end_env(&ret, new);
	new = new_env("PATH", "/usr/local/bin:/usr/bin:/bin");
	add_end_env(&ret, new);
	free(buf);
	return (ret);
}
