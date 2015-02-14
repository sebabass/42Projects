/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 00:31:15 by spariaud          #+#    #+#             */
/*   Updated: 2014/12/29 02:10:19 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nrot(char *str, int n)
{
	int		i;

	i = 0;
	n = n % 26;
	while (str[i])
	{
		if (ft_isalpha(str[i]) && ft_islower(str[i]))
		{
			if (ft_isalpha(str[i] + n))
				str[i] += n;
			else
				str[i] = 'a';
		}
		else if (ft_isalpha(str[i]))
		{
			if (ft_isalpha(str[i] + n))
				str[i] += n;
			else
				str[i] = 'A';
		}
		i++;
	}
	return (str);
}
