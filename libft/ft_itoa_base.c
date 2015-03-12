/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 23:32:50 by spariaud          #+#    #+#             */
/*   Updated: 2015/03/12 00:10:14 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa_base(int nbr, int base)
{
	char	*str;
	int		n;
	int		i;

	n = nbr;
	i = 1;
	while (n > (int)(base - 1) && i++)
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
