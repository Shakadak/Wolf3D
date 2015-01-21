/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:40:13 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:00:40 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	cast(t_player const p,
		t_point current, t_point const step, t_map const m)
{
	int	x;
	int	y;

	if (check(current.x / GRAIN, current.y / GRAIN, m))
	{
		x =(p.coordinate.x - current.x) * (p.coordinate.x - current.x);
		y =(p.coordinate.y - current.y) * (p.coordinate.y - current.y);
		return (sqrt(x + y));
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
		current.y = (player.coordinate.y / GRAIN) * GRAIN - 1;
		step.y = -GRAIN;
	}
	else if (M_PI < player.direction && player.direction < 2 * M_PI)
	{
		current.y = (player.coordinate.y / GRAIN) * GRAIN + GRAIN - 1;
		step.y = GRAIN;
	}
	else
		return (-1);
	current.x = player.coordinate.x
		+ (player.coordinate.y - current.y) / tan(player.direction);
	step.x = GRAIN / tan(player.direction);
	return (cast(player, current, step, map));
}

static int	vertical_cast(t_player const player, t_map const map)
{
	t_point	current;
	t_point	step;

	if (M_PI_2 < player.direction && player.direction < M_PI + M_PI_2)
	{
		current.x = (player.coordinate.x / GRAIN) * GRAIN - 1;
		step.x = -GRAIN;
	}
	else if ((M_PI + M_PI_2 < player.direction && player.direction <= 2 * M_PI)
			|| (0 <= player.direction && player.direction < M_PI_2))
	{
		current.x = (player.coordinate.y / GRAIN) * GRAIN + GRAIN - 1;
		step.x = GRAIN;
	}
	else
		return (-1);
	current.y = player.coordinate.y + (player.coordinate.x - current.x)
				* tan(player.direction);
	step.y = GRAIN * tan(player.direction);
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
