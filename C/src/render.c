/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:59:15 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 12:18:08 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
		height = (double)GRAIN / distance * (double)((W_WIDTH / 2) / tan(tmp.fov / 2));
		//ft_putstr_fd("distance : ", 2);
		//ft_putendl_fd(ft_itoa(distance), 2);
		//printf("cosu ici: %f\n", cos(env->player.direction - tmp.direction));
		//printf("tanuki: %f\n", (double)((W_WIDTH / 2) / tan(tmp.fov / 2)));
		//ft_putendl_fd(ft_itoa(height), 2);
		draw_column(env, height, i);
		tmp.direction = correct_angle(tmp.direction - step);
		++i;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (1);
}
