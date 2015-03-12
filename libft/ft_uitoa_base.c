/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 00:49:18 by spariaud          #+#    #+#             */
/*   Updated: 2015/03/12 01:39:02 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_uitoa_base(unsigned int nbr, int base)
{
	char			*str;
	unsigned int	n;
	int				i;

	n = nbr;
	i = 1;
	while (n > (unsigned int)(base - 1) && i++)
		n /= base;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = BASE[(nbr % base)];
		nbr /= base;
		i--;
	}
	return (str);
}
