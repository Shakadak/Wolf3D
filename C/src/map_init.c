/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:47:35 by npineau           #+#    #+#             */
/*   Updated: 2015/01/19 18:33:07 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "wolf3d.h"

static t_map	init_map(char const * const line)
{
	t_map	new;
	char	**dim;

	dim = ft_strsplit(line, ' ');
	new.width = ft_atoi(dim[0]);
	new.height = ft_atoi(dim[1]);
	ft_array_free((void **)dim);
	return (new);
}

t_map	get_map(char const * const file)
{
	int		fd;
	char	*line;
	t_map	map;

	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	map = init_map(line);
	free(line);
	close(fd);
	return (map);
}
