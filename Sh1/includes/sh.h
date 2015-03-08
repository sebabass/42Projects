/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 01:27:23 by spariaud          #+#    #+#             */
/*   Updated: 2015/02/26 16:07:31 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# define PATH_MX 4096
# define SIGNALDEL "\b\b\e[0J"

typedef	struct		s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

int					ft_cd(t_env **env, char **command);
int					cd_error(const char *path_name, int nbr_arg);
int					ft_setenv(t_env **env, char **command);
int					ft_env(t_env **e, char **command, char **env);
int					ft_unsetenv(t_env **env, char **command);
int					check_command(char **path_tab, char **command, char **env);
int					check_abs(char **command, char **path);
char				**get_path_tab(t_env **env);
void				add_end_env(t_env **env, t_env *new);
void				ft_exit(char **command);
void				del_begin_env(t_env **e);
void				del_middle_env(t_env **e, const char *name);
void				ft_signal(void);
t_env				*env_default(void);
t_env				*get_env(t_env **env, const char *name);
t_env				*new_env(const char *name, const char *content);
t_env				*create_env(char **c_env);

#endif
