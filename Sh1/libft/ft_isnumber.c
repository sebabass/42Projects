/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 01:54:56 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/29 02:04:16 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((i == 0 && (str[i] == '-' || str[i] == '+')) || ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
