/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:59:15 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 11:21:00 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	clear(t_env *env)
{
	ft_bzero(env->img.data, W_WIDTH * W_HEIGHT * env->img.bits);
}

int	render(t_env *env)
{
	t_player	tmp;
	int			i;
	int			distance;
	int			height;
	double		step;

	tmp.coordinate = env->player.coordinate;
	tmp.fov = env->player.fov;
	step = tmp.fov / W_WIDTH;
	tmp.direction = correct_angle(env->player.direction + tmp.fov / 2);
	i = 0;
	while (i < W_WIDTH)
	{
		distance = raycast(tmp, env->map);
		distance = distance * cos(env->player.direction - tmp.direction);
		height = GRAIN / distance * (W_WIDTH / 2) / tan(tmp.fov / 2);
		draw_column(env, height, i);
		tmp.fov = correct_angle(tmp.fov - step);
		++i;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (1);
}
