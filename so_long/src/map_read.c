/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:22:54 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/20 18:20:18 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_printf.h"
#include "dstr.h"
#include "list.h"
#include "util.h"
#include "map.h"
#include "map_verifications.h"

static int	read_line_into_buffer(int fd, t_dstr *line)
{
	ssize_t	read_result;
	char	ch;

	read_result = read(fd, &ch, 1);
	while (read_result == 1 && ch != '\n')
	{
		if (!dstr_append_char(line, ch))
			return (0);
		read_result = read(fd, &ch, 1);
	}
	if (read_result < 0)
	{
		ft_printf("Error\nError reading map file\n");
		dstr_destroy(line);
		return (0);
	}
	return (1);
}

static t_dstr	*read_line(int fd)
{
	t_dstr	*line;

	line = dstr_create();
	if (!line)
		return (NULL);
	if (!read_line_into_buffer(fd, line))
		return (NULL);
	return (line);
}

static t_list	*read_file(int fd)
{
	t_list	*rows;
	t_dstr	*line;

	rows = NULL;
	line = read_line(fd);
	while (line != NULL && dstr_length(line) > 0)
	{
		rows = list_append(rows, line);
		if (!rows)
			return (NULL);
		line = read_line(fd);
	}
	if (line == NULL)
	{
		list_destroy(rows);
		return (NULL);
	}
	dstr_destroy(line);
	return (rows);
}

static int	verify_map(t_map *map)
{
	if (map == NULL || map->rows == NULL)
		return (0);
	if (!map_verify_min_size(map))
		return (util_display_error("Map does not have the minimum size", 0));
	if (!map_verify_square(map))
		return (util_display_error("Map is not rectangular", 0));
	if (!map_verify_walls(map))
		return (util_display_error("Map is not surrounded by walls", 0));
	if (!map_verify_items(map))
		return (util_display_error("Map doesn't have required elements", 0));
	if (!map_verify_way(map))
		return (util_display_error("Map does not have a valid way", 0));
	return (1);
}

t_map	*map_read(const char *file_name)
{
	t_map	*map;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nUnable to open map file: %s\n", file_name);
		return (NULL);
	}
	map = (t_map *)util_calloc(sizeof(t_map));
	if (map != NULL)
		map->rows = read_file(fd);
	close(fd);
	if (!verify_map(map))
	{
		map_destroy(map);
		return (NULL);
	}
	return (map);
}
