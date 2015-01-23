/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:48:00 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 14:04:38 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	render(t_env *env)
{
	int	x;
	int	height;

	clear_image(&env->img);
	x = 0;
	while (x < W_WIDTH)
	{
		height = distance(dda(new_ray(env->player, x), env->map), env->player);
	}
	apply_image(env->win, env->img, new_pos(0, 0, 0));
	return (0);
}
