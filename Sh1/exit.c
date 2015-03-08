/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 01:13:46 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/23 17:23:28 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh.h"
#include "libft.h"

void	ft_exit(char **command)
{
	if (command[1] && command[2])
		ft_putendl("exit: too many arguments");
	else if (command[1])
		exit(ft_atoi(command[1]));
	else
		exit(0);
}
