/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:37:48 by npineau           #+#    #+#             */
/*   Updated: 2015/01/20 14:37:49 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "libft.h"

# define W_WIDTH 1900
# define W_HEIGHT 1200
# define W_TITLE "Wolf3D"
# define GRAIN 64
# define PLAYER_ORIGIN 2

typedef struct	s_ituple
{
	int			fst;
	int			snd;
	int			thd;
}				t_ituple;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_map
{
	int			width;
	int			height;
	char		**map;
}				t_map;

typedef struct	s_player
{
	t_point		coordinate;
	double		direction;
	double		fov;
}				t_player;

int				check(int const col, int const row, t_map const map);
void			ft_fatal(char const *const msg, int const flag);
t_map			get_map(char const *file);
t_player		get_player(t_map const map);
void			*init();
int				key_hook(int key_code);
void			*new_window(void *env);
#endif
