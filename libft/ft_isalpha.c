/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:45:53 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/09 02:05:49 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is_upper(int c)
{
	if (c >= 'A')
	{
		if (c <= 'Z')
			return (1);
	}
	return (0);
}

static	int	ft_is_lower(int c)
{
	if (c >= 'a')
	{
		if (c <= 'z')
			return (1);
	}
	return (0);
}

int			ft_isalpha(int c)
{
	if (ft_is_upper(c))
		return (1);
	if (ft_is_lower(c))
		return (1);
	return (0);
}
