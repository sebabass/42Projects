/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:37:54 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/09 02:05:01 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	c_echap(int c)
{
	if (c == ' ')
		return (1);
	else if (!ft_isprint(c))
		return (1);
	else
		return (0);
}

static	int	c_ascii(const char *str)
{
	int		i;
	int		c;

	i = 0;
	c = 1;
	while (c_echap(str[i]))
		i++;
	if (str[i] == '-')
	{
		c = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		c = 1;
		i++;
	}
	return (c);
}

static	int	is_op(int c)
{
	if (c == '-')
		return (1);
	if (c == '+')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		n;
	int		i;
	int		c;

	n = 0;
	i = 0;
	c = 1;
	while (c_echap(str[i]))
		i++;
	if (is_op(str[i]))
		i++;
	c = c_ascii(str);
	while (ft_isdigit(str[i]))
	{
		if (ft_isdigit(str[i + 1]))
		{
			n += (str[i] - 48);
			n *= 10;
		}
		else
			n += (str[i] - 48);
		i++;
	}
	return (n * c);
}
