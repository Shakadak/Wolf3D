/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 16:48:33 by npineau           #+#    #+#             */
/*   Updated: 2015/01/28 16:48:35 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	collide(double const x, double const y, t_map const map)
{
	if (check(x + 0.25, y + 0.25, map))
		return (!0);
	else if (check(x - 0.25, y - 0.25, map))
		return (!0);
	else
		return(0);
}

int	check(const int col, const int row, const t_map map)
{
	if (col < 0 || row < 0 || col >= map.width || row >= map.height)
	{
		return (!0);
	}
	else
	{
		return (map.map[row][col] == 1);
	}
}
