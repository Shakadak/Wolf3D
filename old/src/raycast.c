/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 14:37:31 by npineau           #+#    #+#             */
/*   Updated: 2015/01/21 16:25:10 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	raycast(t_env *env)
{
	t_cam		c;
	t_screen	s;
	t_player	p;
	int			mod;

	c.pos.x = 2;
	c.pos.y = 2;
	c.dir.x = -0.707107;
	c.dir.y = -0.707107;
	c.plane.x = 0.466690;
	c.plane.y = -0.466690;
	c.time = 0;
	c.oldtime = 0;
	init(&s);
	trace(&s, &c, &p, world);
	while ((mod = move(&c, world)))
	{
		if (mod == 2)
			trace(&s, &c, &p, world);
	}
	close(&s);
}
