/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:47:35 by npineau           #+#    #+#             */
/*   Updated: 2015/01/20 12:12:32 by npineau          ###   ########.fr       */
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

	dim = ft_strxsplit(line, ft_isspace);
	new.width = ft_atoi(dim[0]);
	new.height = ft_atoi(dim[1]);
	ft_freesplit((void **)dim);
	new.map = (char **) malloc(new.height * sizeof(char *));
	return (new);
}

static void		fill_line(char *dest, char const *src)
{
	char			**tab;
	unsigned int	i;

	tab = ft_strxsplit(src, ft_isspace);
	i = 0;
	while (tab[i])
	{
		dest[i] = ft_atoi(tab[i]);
		++i;
	}
	dest[i] = 0;
	ft_freesplit((void **)tab);
}

t_map			get_map(char const * const file)
{
	int		fd;
	int		i;
	char	*line;
	t_map	map;

	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	map = init_map(line);
	free(line);
	i = 0;
	while (get_next_line(fd, &line) > 0 && i < map.height)
	{
		map.map[i] = ft_strnew(map.width);
		fill_line(map.map[i], line);
		free(line);
	}
	close(fd);
	return (map);
}
