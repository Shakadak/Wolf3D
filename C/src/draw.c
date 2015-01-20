/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 17:39:25 by npineau           #+#    #+#             */
/*   Updated: 2015/01/20 18:29:55 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pixel(t_pixel const pixel, t_env env)
{
	int	color;

	color = mlx_get_color_value(env.mlx, pixel.color.identifier);
	env.img.data[pixel.coordinate.y % env.img.lsize
	+ pixel.coordinate.x * env.img.bits] = color;
}
