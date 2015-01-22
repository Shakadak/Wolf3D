#include "libmlx.h"

t_img	new_image(void *mlx)
{
	t_img	img;

	img.img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	if (img.img == NULL)
		ft_fatal("mlx_new_image", 1);
	img.data = mlx_get_data_addr(img.img, &img.bits, &img.lsize, &img.endian);
	return (img);
}
