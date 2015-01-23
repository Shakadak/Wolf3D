/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:48:00 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 19:11:06 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	render(t_env *env)
{
	int		x;
	double	dist;
	t_ray	ray;

	clear_image(env->img);
	x = 0;
	while (x < W_WIDTH)
	{
		ray = dda(new_ray(env->player, x), env->map);
		dist = get_distance(ray, env->player);
		draw_slice(env->img, ray, x, dist);
		++x;
	}
	apply_image(env->win, env->img, new_pos(0, 0, 0));
	return (0);
}
