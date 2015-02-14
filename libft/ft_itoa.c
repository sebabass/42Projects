/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 21:30:20 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/09 02:11:08 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
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

static	void	str_nbr(char *str, int n, int i)
{
	int		neg;

	neg = 0;
	if (n < 0)
	{
		str[0] = '-';
		n -= (n * 2);
		neg = 1;
	}
	while (i > neg)
	{
		if (n > 9)
		{
			str[i - 1] = (n % 10) + 48;
			n -= (n % 10);
			n /= 10;
		}
		else
			str[i - 1] = n + 48;
		i--;
	}
}

char			*ft_itoa(int n)
{
	char	*str_n;
	int		s_nbr;

	s_nbr = size_nbr(n);
	if ((str_n = (char *)malloc(sizeof(char) * (s_nbr + 1))))
	{
		str_nbr(str_n, n, s_nbr);
		str_n[s_nbr] = '\0';
		return (str_n);
	}
	return (NULL);
}
