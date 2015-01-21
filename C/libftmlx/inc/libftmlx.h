#ifndef LIBFTMLX_H
# define LIBFTMLX_H

#include <mlx.h>

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

void	put_pixel_to_image(t_img *img, t_pixel const pixel);

#endif
