/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 12:19:47 by spariaud          #+#    #+#             */
/*   Updated: 2014/11/29 15:51:18 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*ret;
	t_list	*tmp;

	if (!f || !lst)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	tmp = new;
	ret = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new = f(lst)))
			return (NULL);
		tmp->next = new;
		tmp = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (ret);
}
