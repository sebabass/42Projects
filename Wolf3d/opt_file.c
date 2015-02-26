/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:27:47 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/17 14:48:15 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "wolf3d.h"

int		open_file(char *path_name)
{
	int		fd;

	if ((fd = open(path_name, O_RDONLY)) == -1)
		perror_exit("wolf3d :");
	return (fd);
}

void	close_file(int const fd)
{
	if (close(fd) == -1)
		perror_exit("wolf3d :");
}
