/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 01:27:30 by spariaud          #+#    #+#             */
/*   Updated: 2015/03/12 01:38:50 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_ltoa_base(long nbr, int base)
{
	char	*str;
	long	n;
	int		i;

	n = nbr;
	i = 1;
	while (n > (long)(base - 1) && i++)
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
