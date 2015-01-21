/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 17:39:25 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 13:51:25 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//////
#include "wolf3d.h"

void	put_pixel(t_env *env, t_pixel const pixel)
{
	int	color;
	int	pos;

	color = mlx_get_color_value(env->mlx, pixel.color.id);
	pos = pixel.coordinate.y * env->img.lsize
	+ pixel.coordinate.x * (env->img.bits / 8);
	env->img.data[pos] = color &255;
	env->img.data[pos + 1] = color >> 8 &255;
	env->img.data[pos + 2] = color >> 16 &255;
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
		++i;
	}
}
