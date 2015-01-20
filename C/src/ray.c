/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:40:13 by npineau           #+#    #+#             */
/*   Updated: 2015/01/20 14:39:14 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	cast(t_player const p,
		t_point current, t_point const step, t_map const m)
{
	if (check(current.x / GRAIN, current.y / GRAIN, m))
	{
		return (sqrt(pow(p.coordinate.x - current.x, 2) +
		pow(p.coordinate.x - current.x, 2)));
	}
	else
	{
		current.x += step.x;
		current.y += step.y;
		return (cast(p, current, step, m));
	}
}

static int	horizontal_cast(t_player const player, t_map const map)
{
	t_point	current;
	t_point	step;

	if (0 < player.direction && player.direction < M_PI)
	{
		current.y = player.coordinate.y / 64 * 64 - 1;
		step.y = -GRAIN;
	}
	else if (M_PI < player.direction && player.direction < 2 * M_PI)
	{
		current.y = player.coordinate.y / 64 * 64 + 64;
		step.y = GRAIN;
	}
	else
	{
		return (-1);
	}
	current.x = player.coordinate.x
		+ (player.coordinate.y - current.y) / tan(player.direction);
	step.x = 64 / tan(player.direction);
	return (cast(player, current, step, map));
}

static int	vertical_cast(t_player const player, t_map const map)
{
	t_point	current;
	t_point	step;

	if (M_PI_2 < player.direction && player.direction < M_PI + M_PI_2)
	{
		current.x = player.coordinate.x / 64 * 64 - 1;
		step.x = -GRAIN;
	}
	else if ((M_PI + M_PI_2 < player.direction && player.direction <= 2 * M_PI)
			|| (0 <= player.direction && player.direction < M_PI_2))
	{
		current.x = player.coordinate.y / 64 * 64 + 64;
		step.x = GRAIN;
	}
	else
	{
		return (-1);
	}
	current.y = player.coordinate.y + (player.coordinate.x - current.x)
				* tan(player.direction);
	step.y = 64 * tan(player.direction);
	return (cast(player, current, step, map));
}

int			raycast(t_player const player, t_map const map)
{
	int	dv;
	int	dh;

	dh = horizontal_cast(player, map);
	dv = vertical_cast(player, map);
	if (dv >= 0 && dh < 0)
		return (dv);
	else if (dv < 0 && dh >= 0)
		return (dh);
	else
		return (dv < dh ? dv : dh);
}
