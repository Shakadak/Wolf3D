/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:45:24 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 18:59:41 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"
#include <stdio.h>

int		key_hook(int key_code, t_env *env)
{
	printf("keycode: %d\n", key_code);
	if (key_code == XK_Escape)
		exit(0);
	else
	{
		move(key_code, env);
	}
	return (render(env));
}

void	hook_init(t_env const env)
{
	mlx_key_hook(env.win.win, key_hook, (void *)&env);
	mlx_loop_hook(env.mlx, render, (void *)&env);
}
