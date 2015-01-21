/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 17:39:25 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 10:58:08 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pixel(t_env *env, t_pixel const pixel)
{
	int	color;

	color = mlx_get_color_value(env->mlx, pixel.color.id);
	env->img.data[pixel.coordinate.y % env->img.lsize
	+ pixel.coordinate.x * env->img.bits] = color;
}

void	draw_column(t_env *env, int height, int col)
{
	int		i;
	t_pixel	pix;

	i = 0;
	pix.color.id = (255 << 8) + (255 << 16);
		pix.coordinate.x = col;
	while (i < height)
	{
		pix.coordinate.y = i + ((W_HEIGHT - height) / 2);
		put_pixel(env, pix);
	}
}
