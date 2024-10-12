/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:22:54 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/08 09:31:23 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "util.h"
#include "map.h"
#include "map_verifications.h"

static void	append_line_to_list(t_list **list, char *line)
{
	int		len;
	t_list	*line_node;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = 0;
	line_node = ft_lstnew(line);
	if (line_node == NULL)
	{
		ft_lstclear(list, free);
		return;
	}
	ft_lstadd_back(list, line_node);
}

static t_list	*read_file(int fd)
{
	t_list	*rows; 
	char	*line; 

	rows = NULL; 
	line = get_next_line(fd);
	while (line != NULL && ft_strlen(line) > 0) 
	{
		append_line_to_list(&rows, line);
		if (!rows)
			return (NULL);
		line = get_next_line(fd);
	}
	if (line == NULL)
	{
		ft_printf("Error reading file\n");
		ft_lstclear(&rows, free);
		return (NULL);
	}
	free(line);
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
