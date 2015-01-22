/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 11:26:29 by npineau           #+#    #+#             */
/*   Updated: 2015/01/22 13:34:08 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLX_H
# define LIBMLX_H

#include <mlx.h>
#include <string.h>

typedef struct		s_pos
{
	int				x;
	int				y;
	int				z;
}					t_pos;

typedef union		u_color
{
	unsigned int	id;
	unsigned char	rgb[4];
}					t_color;

typedef struct		s_pix
{
	t_pos			pos;
	t_color			color;
}					t_pix;

typedef struct		s_img
{
	void			*img;
	int				width;
	int				height;
	char			*data;
	int				bits;
	int				lsize;
	int				endian;
}					t_img;

typedef struct		s_win
{
	void			*win;
	int				width;
	int				height;
	char			*title;
}					t_win;

void				*new_mlx(void);
t_img				new_image(void *mlx, int width, int height);
t_win				new_window(void *mlx, int width, int height, char *title);

void				put_pixel_to_image(t_img *img, t_pix const pixel);
void				clear_image(t_img *img);
void				draw_line(t_img *img, t_pix start, t_pix end)

void				ft_fatal(char const *const msg, int const flag);

#endif
