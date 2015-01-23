/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:30:23 by npineau           #+#    #+#             */
/*   Updated: 2015/01/23 12:50:36 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_dir		get_coordinate(t_map const map)
{
	t_dir	new;
	int		i;
	int		j;

	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			if (map.map[j][i] == PLAYER_ORIGIN)
			{
				new.y = j * GRAIN + GRAIN / 2;
				new.x = i * GRAIN + GRAIN / 2;
				new.z = GRAIN / 2;
				return (new);
			}
			++i;
		}
		++j;
	}
	ft_fatal("Player original coordinate not found.", 0);
	return (new);

}

t_player	get_player(t_map const map)
{
	t_player	new;

	new.dir.x = -1;
	new.dir.y = 0;
	new.cam.x = 0;
	new.cam.y = 0.66;
	new.pos = get_coordinate(map);
	return (new);
}