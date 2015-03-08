/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 01:14:01 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/26 03:38:13 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "sh.h"

t_env	*get_env(t_env **env, const char *name)
{
	t_env	*tmp_env;

	tmp_env = *env;
	while (tmp_env)
	{
		if (ft_strcmp(tmp_env->name, name) == 0)
			return (tmp_env);
		tmp_env = tmp_env->next;
	}
	return (tmp_env);
}

void	add_end_env(t_env **env, t_env *new)
{
	t_env	*tmp_env;

	tmp_env = *env;
	if (*env)
	{
		while (tmp_env->next)
			tmp_env = tmp_env->next;
		tmp_env->next = new;
	}
	else
		*env = new;
}

t_env	*new_env(const char *name, const char *content)
{
	t_env	*new;
	char	*tmp_name;
	char	*cont;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (!content)
		cont = NULL;
	else if (!(cont = (char *)malloc(sizeof(char) * ft_strlen(content) + 1)))
		return (NULL);
	if (!(tmp_name = (char *)malloc(sizeof(char) * ft_strlen(name) + 1)))
		return (NULL);
	new->name = ft_strcpy(tmp_name, name);
	if (content)
		new->content = ft_strcpy(cont, content);
	else
		new->content = NULL;
	new->next = NULL;
	return (new);
}

t_env	*create_env(char **c_env)
{
	t_env	*ret;
	t_env	*env;
	int		i;
	char	**split;

	i = 0;
	ret = NULL;
	env = NULL;
	while (c_env[i])
	{
		split = ft_strsplit(c_env[i], '=');
		if (i == 0)
			ret = new_env(split[0], split[1]);
		else
		{
			env = new_env(split[0], split[1]);
			add_end_env(&ret, env);
		}
		i++;
	}
	return (ret);
}
