/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:05:20 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/26 16:08:47 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <unistd.h>

int		check_abs(char **command, char **path)
{
	if (command && command[0])
	{
		if (access(command[0], F_OK) == 0)
		{
			*path = command[0];
			return (1);
		}
	}
	return (0);
}
