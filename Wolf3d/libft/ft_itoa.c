/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 21:30:20 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/12 17:58:19 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static	int		size_nbr(int n)
{
	int		size;

	size = 0;
	if (n < 0)
	{
		size++;
		n -= (n * 2);
	}
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

char			*ft_itoa(int n)
{
	char	*str_n;

	str_n = ft_strnew(size_nbr(n));
	if (n >= 0 && str_n)
	{
		*--str_n = '0' + (n % 10);
		n /= 10;
		while (n != 0)
		{
			*--str_n = '0' + (n % 10);
			n /= 10;
		}
	}
	else if (str_n)
	{
		*--str_n = '0' - (n % 10);
		n /= 10;
		while (n != 0)
		{
			*--str_n = '0' - (n % 10);
			n /= 10;
		}
		*--str_n = '-';
	}
	return (ft_strdup(str_n));
}
