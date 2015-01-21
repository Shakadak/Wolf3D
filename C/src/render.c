/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:59:15 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 15:58:17 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "wolf3d.h"

void	clear(t_env *env)
{
	ft_bzero(env->img.data, W_WIDTH * W_HEIGHT * (env->img.bits / 8));
}

int		correct_height(int incorrect)
{
	if (incorrect > W_HEIGHT)
		return(W_HEIGHT);
	if (incorrect < 0)
		return (0);
	return (incorrect);
}

int		render(t_env *env)
{
	t_player	tmp;
	int			i;
	double		len;
	double		step;

	tmp.coordinate = env->player.coordinate;
	tmp.fov = env->player.fov;
	step = tmp.fov / (double)W_WIDTH;
	tmp.direction = correct_angle(env->player.direction - tmp.fov / 2);
	i = 0;
	while (i < W_WIDTH)
	{
		len = (double)raycast(tmp, env->map);
		len = len * cos(env->player.direction - tmp.direction);
		len = ceil((double)GRAIN / len * ((double)(W_WIDTH / 2) / tan(tmp.fov / 2)));
		draw_column(env, correct_height(len), i);
		tmp.direction = correct_angle(tmp.direction + step);
		++i;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	clear(env);
	usleep(1000000 / 60);
	return (1);
}
