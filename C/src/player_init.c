/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:30:23 by npineau           #+#    #+#             */
/*   Updated: 2015/01/22 12:05:59 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_player	get_player(t_map const map)
{
	t_player	new;
	int			i;
	int			j;

	new.direction = M_PI_2;
	new.fov = M_PI / 2;
	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			if (map.map[j][i] == PLAYER_ORIGIN)
			{
				new.coordinate.y = j * GRAIN + GRAIN / 2;
				new.coordinate.x = i * GRAIN + GRAIN / 2;
				new.coordinate.z = GRAIN / 2;
				return (new);
			}
			++i;
		}
		++j;
	}
	ft_fatal("Player original coordinate not found.", 0);
	return (new);
}
