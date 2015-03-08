/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:42:34 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/08 02:06:10 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

static	int	get_pos_n(char *save, int end)
{
	char	*tmp;

	tmp = save;
	if (save)
	{
		while (*save)
		{
			if (*save++ == '\n' && !end)
				return (save - tmp - 1);
		}
		if (end)
			return (save - tmp - 1);
	}
	return (-1);
}

static	int	get_new_line(char **save, char **line, int end)
{
	char	*tmp;
	int		i;

	if ((i = get_pos_n(*save, end)) == -1)
		return (0);
	tmp = ft_strdup(*save);
	tmp[i + end] = '\0';
	*line = ft_strdup(tmp);
	*save += i + 1;
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static	char	*save;
	char			*buf;
	int				ret;

	if (!line || fd < 0 || !(buf = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!save)
	{
		if (!(save = (char *)malloc(sizeof(char))))
			return (-1);
		*save = 0;
	}
	while (!(get_new_line(&save, line, 0)))
	{
		if (!save || BUFF_SIZE <= 0 || (ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		if (!ret)
		{
			free(buf);
			return (get_new_line(&save, line, 1));
		}
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
	}
	return (1);
}
