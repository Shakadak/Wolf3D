#ifndef LIBMLX_H
# define LIBMLX_H

#include <mlx.h>
#include <string.h>

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
void				*new_window(void *mlx);

void				put_pixel_to_image(t_img *img, t_pixel const pixel);

void				ft_fatal(char const *const msg, int const flag);

#endif
