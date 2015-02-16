/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:45:24 by npineau           #+#    #+#             */
/*   Updated: 2015/02/16 14:18:12 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"

int		key_press(int key, t_env *env)
{
	if (key == XK_Escape)
		exit(0);
	v_mov_press(key, &env->player.mov);
	h_mov_press(key, &env->player.mov);
	v_rot_press(key, &env->player.rot);
	h_rot_press(key, &env->player.rot);
	return (0);
}

int		key_release(int key, t_env *env)
{
	if (key == XK_Escape)
		exit(0);
	v_mov_release(key, &env->player.mov);
	h_mov_release(key, &env->player.mov);
	v_rot_release(key, &env->player.rot);
	h_rot_release(key, &env->player.rot);
	return (0);
}

void	hook_init(t_env const *env)
{
	mlx_do_key_autorepeatoff(env->mlx);
	mlx_hook(env->win.win, KeyPress, KeyPressMask, key_press, (void *)env);
	mlx_hook(env->win.win,
			KeyRelease, KeyReleaseMask, key_release, (void *)env);
	mlx_loop_hook(env->mlx, render, (void *)env);
}
