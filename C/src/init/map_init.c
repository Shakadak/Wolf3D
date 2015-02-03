/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:47:35 by npineau           #+#    #+#             */
/*   Updated: 2015/02/03 13:52:39 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "wolf3d.h"

static t_map	init_map(char const *const line)
{
	t_map	new;
	char	**dim;

	dim = ft_strxsplit(line, ft_isspace);
	if (dim == NULL)
		ft_fatal("failed to allocate dimension", 1);
	if (dim[0] == NULL || dim[1] == NULL || dim[2] != NULL)
		ft_fatal("incorrect map format", 0);
	new.width = ft_atoi(dim[0]);
	new.height = ft_atoi(dim[1]);
	if (new.width < 1 || new.height < 1)
		ft_fatal("incorrect map size", 0);
	ft_freesplit((void **)dim);
	new.map = (int **)malloc((new.height + 1) * sizeof(int *));
	return (new);
}

static void		fill_line(int *dest, char const *const src, int const width)
{
	char	**tab;
	int		i;

	tab = ft_strxsplit(src, ft_isspace);
	i = 0;
	while (tab[i] && i < width)
	{
		dest[i] = ft_atoi(tab[i]);
		++i;
	}
	dest[i] = 0;
	ft_freesplit((void **)tab);
}

t_map			get_map(char const *const file)
{
	int		fd;
	int		i;
	char	*line;
	t_map	map;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_fatal(file, 1);
	get_next_line(fd, &line);
	map = init_map(line);
	free(line);
	i = 0;
	while (get_next_line(fd, &line) > 0 && i < map.height)
	{
		map.map[i] = (int *)ft_strnew(map.width * sizeof(**map.map));
		fill_line(map.map[i], line, map.width);
		free(line);
		++i;
	}
	map.map[i] = NULL;
	map.height = i;
	close(fd);
	return (map);
}
