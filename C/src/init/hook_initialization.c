/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:45:24 by npineau           #+#    #+#             */
/*   Updated: 2015/01/26 14:20:52 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"
#include <stdio.h>

int		key_press(int key, t_env *env)
{
	if (key == XK_Escape)
		exit(0);
	else if (is_direction(key))
		direction_press(key, &env->player.mov);
	else
		rotation_press(key, &env->player.rot);
	return (render(env));
}

int		key_release(int key, t_env *env)
{
	if (key == XK_Escape)
		exit(0);
	else if (is_direction(key))
		direction_release(key, &env->player.mov);
	else
		rotation_release(key, &env->player.rot);
	return (render(env));
}

void	hook_init(t_env const env)
{
	mlx_do_key_autorepeatoff(env.mlx);
	mlx_hook(env.win.win, KeyPress, KeyPressMask, key_press, (void *)&env);
	mlx_hook(env.win.win, KeyRelease, KeyReleaseMask, key_release, (void *)&env);
	mlx_loop_hook(env.mlx, render, (void *)&env);
}
