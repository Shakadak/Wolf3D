/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:37:48 by npineau           #+#    #+#             */
/*   Updated: 2015/01/30 17:34:44 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <mlx.h>
# include "libft.h"
# include "libumlx.h"

# define W_WIDTH 1366
# define W_HEIGHT 768
# define W_TITLE "Wolf3D"
# define GRAIN 64
# define PLAYER_ORIGIN 2

# define UP 1
# define DOWN 1 << 1
# define LEFT 1 << 2
# define RIGHT 1 << 3
# define FORWARD 1 << 4
# define BACKWARD 1 << 5

# define ROT_RIGHT 1
# define ROT_LEFT 1 << 1
# define ROT_UP 1 << 2
# define ROT_DOWN 1 << 3

# define SPEED 2.0
# define ROT 2.0
# define HITBOX 0.1 * W_HEIGHT / W_WIDTH

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
	int				mov;
	int				rot;
	t_dir			pos;
	t_dir			dir;
	t_dir			cam;
}					t_player;

typedef struct		s_ray
{
	double			dist;
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

int					collide(double const x, double const y, t_map const map);
int					check(int const col, int const row, t_map const map);
t_ray				dda(t_ray ray, t_map const map);
t_ray				new_ray(t_player const player, int x);
double				get_distance(t_ray const ray, t_player const player);
double				get_frame_time(void);

void				move(t_env *env, double frame);

void				h_mov_press(int key, int *mov);
void				h_mov_release(int key, int *mov);

void				v_mov_press(int key, int *mov);
void				v_mov_release(int key, int *mov);
void				v_mov(t_env *env, double speed);

void				rotate(t_env *env, double frame);

void				v_rot_press(int key, int *rot);
void				v_rot_release(int key, int *rot);
void				v_rot(t_env *env, double rot);

void				h_rot_press(int key, int *rot);
void				h_rot_release(int key, int *rot);
void				h_rot(t_env *env, double rot);

t_color				get_wall_color(t_ray const ray);
void				draw_slice(t_img const img,
		t_ray const ray,
		int const x,
		t_player const player);

int					add_option(int const param, int const option);
int					rem_option(int const param, int const option);
t_map				get_map(char const *file);
t_player			get_player(t_map const map);
void				hook_init(t_env env);
int					key_hook(int key_code, t_env *env);
int					render(t_env *env);
#endif
