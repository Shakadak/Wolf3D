/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:48:00 by npineau           #+#    #+#             */
/*   Updated: 2015/03/23 16:37:48 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "wolf3d.h"

static void	draw_env(t_img const img, t_player const p)
{
	t_pix	start;
	t_pix	end;

	start.pos = new_pos(0, 0, 0);
	end.pos = new_pos(W_WIDTH, W_HEIGHT * p.cam.z / 2, 0);
	start.color = new_color(176, 216, 230);
	end.color = start.color;
	draw_rectangle(img, start, end);
	start.pos = new_pos(0, W_HEIGHT * p.cam.z / 2, 0);
	end.pos = new_pos(W_WIDTH, W_HEIGHT, 0);
	start.color = new_color(150, 75, 0);
	end.color = start.color;
	draw_rectangle(img, start, end);
}

double		get_frame_time(void)
{
	static struct timeval	old;
	struct timeval			current;
	double					frame;

	gettimeofday(&current, NULL);
	frame = ((current.tv_sec - old.tv_sec) * 1000000
			+ (current.tv_usec - old.tv_usec));
	old = current;
	return (frame / 1000000);
}

void		rotate(t_env *env, double const rot)
{
	h_rot(env, rot);
	v_rot(env, rot);
}

int			render(t_env *env)
{
	int		x;
	t_ray	ray;
	double	frame;

	frame = get_frame_time();
	clear_image(env->img);
	move(env, SPEED * frame);
	rotate(env, ROT * frame);
	draw_env(env->img, env->player);
	x = 0;
	while (x < W_WIDTH)
	{
		ray = dda(new_ray(env->player, x), env->map);
		ray.dist = get_distance(ray, env->player);
		draw_slice(env->img, ray, x, env->player);
		++x;
	}
	apply_image(env->win, env->img, new_pos(0, 0, 0));
	mlx_do_sync(env->mlx);
	return (0);
}
