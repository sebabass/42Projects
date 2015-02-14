/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 22:12:38 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/07 22:29:38 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (size <= 0)
		return (NULL);
	mem = (void *)malloc(sizeof(mem) * size);
	if (mem)
	{
		mem = 0;
		return (mem);
	}
	return (NULL);
}
