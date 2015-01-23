/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:37:48 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 17:21:03 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "libft.h"
# include "libumlx.h"

# define W_WIDTH 1366
# define W_HEIGHT 768
# define W_TITLE "Wolf3D"
# define GRAIN 64
# define PLAYER_ORIGIN 2

typedef struct		s_ituple
{
	int				fst;
	int				snd;
	int				thd;
}					t_ituple;

typedef struct		s_dir
{
	double			x;
	double			y;
	double			z;
}					t_dir;

typedef struct		s_map
{
	int				width;
	int				height;
	int				**map;
}					t_map;

typedef struct		s_player
{
	t_dir			pos;
	t_dir			dir;
	t_dir			cam;
}					t_player;

typedef struct		s_ray
{
	t_dir			dir;
	t_dir			delta;
	t_dir			side;
	t_pos			map;
	t_pos			step;
	int				where;
}					t_ray;

typedef struct		s_env
{
	void			*mlx;
	t_win			win;
	t_img			img;
	t_player		player;
	t_map			map;
}					t_env;

int					check(int const col, int const row, t_map const map);
t_ray				dda(t_ray ray, t_map const map);
t_ray				new_ray(t_player const player, int x);
double				get_distance(t_ray const ray, t_player const player);

int					move(int key_code, t_env *env);

t_color				get_wall_color(t_ray const ray);
void				draw_slice(t_img const img,
		t_ray const ray,
		int const x,
		int const distance);


t_map				get_map(char const *file);
t_player			get_player(t_map const map);
void				hook_init(t_env env);
int					key_hook(int key_code, t_env *env);
int					render(t_env *env);
#endif
