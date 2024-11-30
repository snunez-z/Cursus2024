/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifications.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:05:15 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/20 18:08:34 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"
#include "dstr.h"
#include "list.h"
#include "map.h"
#include "map_verifications.h"

static void	count_function(t_map_loop *map_loop)
{
	t_count_data	*count_data;

	count_data = (t_count_data *)map_loop->data;
	if (map_loop->ch == MAP_PLAYER_CHAR)
	{
		map_loop->map->player_x = map_loop->x;
		map_loop->map->player_y = map_loop->y;
		map_loop->map->at_player = '0';
		count_data->player_count++;
	}
	else if (map_loop->ch == MAP_EXIT_CHAR)
		count_data->exit_count++;
	else if (map_loop->ch == MAP_FOOD_CHAR)
		map_loop->map->food_left++;
}

int	map_verify_min_size(t_map *map)
{
	t_dstr	*first_line;

	ft_printf("Verifying map is at least 3x3...\n");
	map->height = list_size(map->rows);
	if (map->height < 3)
		return (0);
	first_line = list_get(map->rows, 0);
	map->width = dstr_length(first_line);
	if (map->width < 3)
		return (0);
	return (1);
}

int	map_verify_square(t_map *map)
{
	t_list	*node;
	t_dstr	*line;
	int		line_width;

	ft_printf("Verifying map is rectangular...\n");
	node = map->rows;
	while (node != NULL)
	{
		line = node->line;
		line_width = dstr_length(line);
		if (line_width != map->width)
			return (0);
		node = node->next;
	}
	return (1);
}

int	map_verify_items(t_map *map)
{
	t_count_data	count_data;

	ft_printf("Verifying elements in map...\n");
	count_data.exit_count = 0;
	count_data.player_count = 0;
	map_loop(map, count_function, &count_data);
	if (map->food_left == 0
		|| count_data.exit_count != 1
		|| count_data.player_count != 1)
		return (0);
	return (1);
}
