#include "libftmlx.h"

void	*new_window(void *mlx)
{
	void	*win;

	win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, W_TITLE);
	if (win == NULL)
		ft_fatal("mlx_new_window", 1);
	return (win);
}
