/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:45:24 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 12:49:34 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>

int		key_hook(int key_code, t_env *env)
{
	if (key_code == XK_Escape)
		exit(0);
	if (key_code == XK_Left || key_code == XK_Right)
	{
		env->player.dir.x += (key_code == XK_Left ? M_PI_4 : -M_PI_4);
	}
	return (0);
}

void	hook_init(t_env const env)
{
	mlx_key_hook(env.win.win, key_hook, (void *)&env);
	mlx_loop_hook(env.mlx, render, (void *)&env);
}
