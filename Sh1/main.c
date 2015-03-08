/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:47:46 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/26 17:13:43 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "sh.h"
#include "libft.h"
#include "get_next_line.h"

static	int		execute_command(char *path_command, char **argc, char **e)
{
	pid_t	pather;
	int		status;

	pather = fork();
	if (pather > 0)
		wait(&status);
	else if (pather == 0)
	{
		execve(path_command, argc, e);
		exit(0);
	}
	return (0);
}

static	int		check_builtin(t_env **e, char **command, char **env)
{
	if (ft_strcmp(command[0], "cd") == 0)
		ft_cd(e, command);
	else if (ft_strcmp(command[0], "env") == 0)
		ft_env(e, command, env);
	else if (ft_strcmp(command[0], "setenv") == 0)
		ft_setenv(e, command);
	else if (ft_strcmp(command[0], "unsetenv") == 0)
		ft_unsetenv(e, command);
	else if (ft_strcmp(command[0], "exit") == 0)
		ft_exit(command);
	else
		return (0);
	return (1);
}

static	void	init_command(t_env **e, char *line, char **env)
{
	char	**path_tab;
	char	**ac_command;

	line = ft_chinspace(line);
	ac_command = ft_strsplit(line, ' ');
	if (*ac_command)
	{
		if (!check_builtin(e, ac_command, env))
		{
			if ((path_tab = get_path_tab(e)))
				check_command(path_tab, ac_command, env);
		}
		else if (access(ac_command[0], F_OK) != -1)
			execute_command(ac_command[0], ac_command, env);
	}
}

int				check_command(char **path_tab, char **command, char **env)
{
	int		i;
	int		ret_abs;
	char	*path;

	i = 0;
	ret_abs = check_abs(command, &path);
	while (!ret_abs && i != -1 && path_tab[i])
	{
		path = ft_strdup(path_tab[i]);
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, command[0]);
		if (access(path, F_OK) != -1)
			i = -1;
		else
			i++;
	}
	if (ret_abs)
		return (execute_command(path, command, env));
	if (!ret_abs && i != -1)
	{
		ft_putendl(ft_strjoin("zsh: command not found: ", command[0]));
		return (0);
	}
	else
		return (execute_command(path, command, env));
}

int				main(int argc, char **argv, char **env)
{
	char	*line;
	t_env	*e;
	int		ret;

	if (env[0])
		e = create_env(env);
	else
		e = env_default();
	while (argc)
	{
		ft_putstr("$> ");
		ft_signal();
		if ((ret = get_next_line(0, &line) && ft_strlen(line)))
		{
			if (line)
			{
				init_command(&e, line, env);
				free(line);
			}
		}
		if (ret == -1)
			exit(0);
	}
	(void)argv;
	return (0);
}
