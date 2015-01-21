/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:37:48 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 15:43:26 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "libft.h"

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

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef union		u_color
{
	unsigned int	id;
	unsigned char	rgb[4];
}					t_color;

typedef struct		s_pixel
{
	t_point			coordinate;
	t_color			color;
}					t_pixel;

typedef struct		s_map
{
	int				width;
	int				height;
	char			**map;
}					t_map;

typedef struct		s_player
{
	t_point			coordinate;
	double			direction;
	double			fov;
}					t_player;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bits;
	int				lsize;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_player		player;
	t_map			map;
}					t_env;

int					check(int const col, int const row, t_map const map);
double				correct_angle(double incorrect);
void				draw_column(t_env *env, int height, int col);
void				ft_fatal(char const *const msg, int const flag);
t_map				get_map(char const *file);
t_player			get_player(t_map const map);
void				hook_init(t_env env);
void				*init();
int					key_hook(int key_code, t_env *env);
void				*new_window(void *env);
t_img				new_image(void *mlx);
int					raycast(t_player const player, t_map const map);
int					render(t_env *env);
#endif
