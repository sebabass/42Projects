/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <spariaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 04:55:58 by spariaud          #+#    #+#             */
/*   Updated: 2015/01/22 09:01:08 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_WIDTH 		900
# define WIN_HEIGHT 	800
# define CUBE			64
# define MAP_WIDTH		40
# define MAP_HEIGHT		40
# define PI 			3.14159265
# define RADIAN(angle) ((double)(angle) * PI / 180)

typedef	struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef	struct			s_map
{
	char				*name;
	int					**tab;
}						t_map;

typedef	struct			s_ray
{
	t_pos				ray_r;
	t_pos				ray_g;
}						t_ray;

typedef struct			s_player
{
	double				proj_w;
	double				proj_h;
	double				center_w;
	double				center_h;
	double				dist_proj;
	double				angle;
	double				fov;
	double				size;
	int					dist_wall_h;
	int					dist_wall_v;
	double				dist_wall;
	struct	s_pos		pos_g;
	struct	s_pos		pos_r;
}						t_player;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					sizeline;
	int					endian;
	int					bpp;
	int					ya;
	int					xa;
	int					height_wall;
	int					beta;
	struct	s_pos		a_r;
	struct	s_pos		a_g;
	struct	s_player	player;
	struct	s_ray		ray_h;
	struct	s_ray		ray_v;
	struct	s_map		map;
}						t_env;

void					perror_exit(char *error);
void					error_exit(char *error);
int						expose_hook(t_env *e);
int						key_hook(int keycode, t_env *e);
int						open_file(char *path_name);
void					close_file(int const fd);
void					load_map(t_env *e, char *path_map);
void					put_map_console(t_map *map);
void					init_player(t_env *e);
void					raycast(t_env *e);
void					draw(t_env *e);
void					draw_col_wall(t_env *e, int x);

#endif
