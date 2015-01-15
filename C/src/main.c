/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 15:57:48 by npineau           #+#    #+#             */
/*   Updated: 2015/01/15 19:37:05 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "wolf3d.h"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./wolf3d path/to/map", 2);
		return (1);
	}
	new_window(init());
	sleep(5);
	return (0);
}
