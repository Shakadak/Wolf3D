/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:40:13 by npineau           #+#    #+#             */
/*   Updated: 2015/01/16 16:26:09 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	cast(const int f_x, const int xstep, const int f_y, const int ystep, const char **map)
{
	if (check(f_x / GRAIN, f_y / GRAIN, map))
	{
		return (tuple(f_x, f_y));
	}
	else
	{
		return (cast(f_x + xstep, xstep, f_y + ystep, ystep, map));
	}
}

int	horizontal_cast(const double angle, const t_player player, const char **map)
{
	int	a_x;
	int	a_y;
	int	xstep;
	int	ystep;

	if (0 < angle && angle < M_PI)
	{
		a_y = player.y / 64 * 64 - 1;
		ystep = -GRAIN;
	}
	else if (M_PI < angle && angle < 2 * M_PI)
	{
		a_y = player.y / 64 * 64 + 64;
		ystep = GRAIN;
	}
	else
	{
		return (-1);
	}
	a_x = x + (y -a_y) / tan(angle);
	xstep = 64 / tan(angle);
	return (cast(a_x, xstep, a_y, ystep, map));
}

int	vertical_cast(const double angle, const t_player player, const char **map)
{
	int	a_x;
	int	a_y;
	int	xstep;
	int	ystep;

	if (M_PI_2 < angle && angle < M_PI + M_PI_2)
	{
		a_x = player.x / 64 * 64 - 1;
		ystep = -GRAIN;
	}
	else if ((M_PI + M_PI_2 < angle && angle <= 2 * M_PI)
			|| (0 <= angle && angle < M_PI_2))
	{
		a_y = player.y / 64 * 64 + 64;
		ystep = GRAIN;
	}
	else
	{
		return (-1);
	}
	a_x = x + (y -a_y) / tan(angle);
	xstep = 64 / tan(angle);
	return (cast(a_x, xstep, a_y, ystep, map));
}
