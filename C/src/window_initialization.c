/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:42:08 by npineau           #+#    #+#             */
/*   Updated: 2015/01/20 16:03:14 by npineau          ###   ########.fr       */
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

void	*new_image(void *mlx)
{
	void	*img;

	img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	if (img == NULL)
		ft_fatal("mlx_new_image", 1);
	return (img);
}
