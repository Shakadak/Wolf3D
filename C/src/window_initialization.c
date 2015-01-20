/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:42:08 by npineau           #+#    #+#             */
/*   Updated: 2015/01/20 18:25:17 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	*init(void)
{
	void	*mlx;
	mlx = mlx_init();
	if (mlx == NULL)
		ft_fatal("mlx_init", 1);
	return (mlx);
}

void	*new_window(void *mlx)
{
	void	*win;

	win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, W_TITLE);
	if (win == NULL)
		ft_fatal("mlx_new_window", 1);
	return (win);
}

t_img	new_image(void *mlx)
{
	t_img	img;

	img.img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	if (img.img == NULL)
		ft_fatal("mlx_new_image", 1);
	img.data = mlx_get_data_addr(img.img, &img.bits, &img.lsize, &img.endian);
	return (img);
}
