/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:11:29 by npineau           #+#    #+#             */
/*   Updated: 2015/01/20 13:44:50 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
