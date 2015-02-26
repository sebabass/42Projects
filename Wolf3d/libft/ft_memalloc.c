/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 22:12:38 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/12 15:19:48 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*mem;
	char			*tmp;
	unsigned int	i;

	mem = malloc(size);
	tmp = (char *)mem;
	if (mem)
	{
		while (i < size)
		{
			*tmp++ = 0;
			i++;
		}
	}
	return (mem);
}
