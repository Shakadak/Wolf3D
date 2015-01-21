/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:30:15 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:39:00 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	draw(t_env *env, t_ico draw, int x)
{
	t_pixel	pix;

	pix.coordinate.x = x;
	while (draw.x <= draw.y)
	{
		pix.coordinate.y = draw.x;
		put_pixel(env, pix);
		++draw.x;
	}
}
