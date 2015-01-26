/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:48:00 by npineau           #+#    #+#             */
/*   Updated: 2015/01/26 14:16:32 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_env(t_img const img)
{
	t_pix	start;
	t_pix	end;

	start.pos = new_pos(0, 0, 0);
	end.pos = new_pos(W_WIDTH, W_HEIGHT / 2, 0);
	start.color = new_color(176, 216, 230);
	end.color = start.color;
	draw_rectangle(img, start, end);
	start.pos = new_pos(0, W_HEIGHT / 2, 0);
	end.pos = new_pos(W_WIDTH, W_HEIGHT, 0);
	start.color = new_color(150, 75, 0);
	end.color = start.color;
	draw_rectangle(img, start, end);
}

int			render(t_env *env)
{
	int		x;
	double	dist;
	t_ray	ray;

	clear_image(env->img);
	draw_env(env->img);
	move(env);
	rotate(env);
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
