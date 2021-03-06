/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 15:57:48 by npineau           #+#    #+#             */
/*   Updated: 2015/02/16 14:19:59 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "wolf3d.h"

int main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./wolf3d path/to/map", 2);
		return (1);
	}
	env.map = get_map(argv[1]);
	env.player = get_player(env.map);
	env.mlx = new_mlx();
	env.win = new_window(env.mlx, W_WIDTH, W_HEIGHT, W_TITLE);
	env.img = new_image(env.mlx, W_WIDTH, W_HEIGHT);
	hook_init(&env);
	mlx_loop(env.mlx);
	return (0);
}
