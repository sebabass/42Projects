/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 21:34:22 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/26 01:33:20 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include "sh.h"
#include "libft.h"

int		cd_error(const char *path_name, int nbr_arg)
{
	struct stat		st;

	if (nbr_arg > 2)
		ft_putendl("cd:cd:13: too many arguments");
	else if (stat(path_name, &st) == -1 && lstat(path_name, &st) == -1)
	{
		ft_putendl(ft_strjoin("cd: No such file or directory: ", path_name));
		return (1);
	}
	else
	{
		if (!S_ISDIR(st.st_mode))
		{
			ft_putendl(ft_strjoin("cd: Not a directory: ", path_name));
			return (1);
		}
		else if (access(path_name, X_OK) == -1)
		{
			ft_putendl(ft_strjoin("cd: permission denied: ", path_name));
			return (1);
		}
	}
	return (0);
}
