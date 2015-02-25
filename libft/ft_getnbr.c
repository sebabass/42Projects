/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 06:28:04 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/27 06:46:35 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnbr(char *str)
{
	int		ret;

	if (*str == '-')
		return (-ft_getnbr(str + 1));
	if (*str == '+')
		return (ft_getnbr(str + 1));
	ret = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret = ret + *str - '0';
		str++;
	}
	return (ret);
}
