/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:28:34 by npineau           #+#    #+#             */
/*   Updated: 2014/01/19 18:00:36 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	bump(t_player *p, int world[MAPW][MAPH])
{
	while (p->hit == 0)
	{
		if (p->side.x < p->side.y)
		{
			p->side.x += p->delta.x;
			p->map.x += p->step.x;
			p->orientation = 0;
		}
		else
		{
			p->side.y += p->delta.y;
			p->map.y += p->step.y;
			p->orientation = 1;
		}
		if (world[p->map.x][p->map.y] > 0)
			p->hit = 1;
	}
}
