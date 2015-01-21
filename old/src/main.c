/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 13:41:16 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:23:56 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(void)
{
	t_env	env;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./wolf3d path/to/map", 2);
		return (1);
	}
	env.map = get_map(argv[1]);
	env.player = get_player(env.map);
	env.mlx = init();
	env.win = new_window(env.mlx);
	env.img = new_image(env.mlx);
	hook_init(env);
	mlx_loop(env.mlx);
	return (0);
	raycast(world);
}