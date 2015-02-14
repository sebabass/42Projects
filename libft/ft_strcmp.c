/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:33:34 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/09 02:02:59 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	str_ascii(const char *str)
{
	int		i;
	int		v_ascii;

	i = 0;
	v_ascii = 0;
	while (str[i] != '\0')
	{
		v_ascii += str[i];
		i++;
	}
	return (v_ascii);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	int		s1_ascii;
	int		s2_ascii;

	s1_ascii = str_ascii(s1);
	s2_ascii = str_ascii(s2);
	if (s1_ascii < s2_ascii)
		return ((s1_ascii - s2_ascii));
	else if (s1_ascii == s2_ascii)
	{
		if (s1[0] > s2[0])
			return (1);
		if (s1[0] < s2[0])
			return (-1);
		return (0);
	}
	else
		return ((s1_ascii - s2_ascii));
}
