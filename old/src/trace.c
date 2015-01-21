/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:30:37 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:56:37 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	trace(t_env *env, t_cam *c)
{
	int		x;

	x = 0;
	clear_screen(env);
	while (x < W_WIDTH)
	{
		init_player(c, env->player, x);
		init_step_dist(env->player);
		bump(env->playerp, env->map.map);
		color(env, env->player);
		draw(env, line_height(env->player), x);
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}
