/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:22:54 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/08 09:31:23 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "dstr.h"
#include "map.h"
#include "util.h"

void	map_destroy(t_map *map) 
{
	if (!map)
		return ;
	if (map->rows != NULL)
		ft_lstclear(&map->rows, free);
	free(map);
}

int	map_get_move_count(t_map *map)
{
	return map->move_count;
}

int	map_move_player(t_map *map, int inc_x, int inc_y) 
{
	int	new_x;
	int	new_y;

	new_x = map->player_x + inc_x; 
	new_y = map->player_y + inc_y; 
	if (new_x < 0 || new_y < 0
		|| new_x >= map->width || new_y >= map->height
		|| map_at(map, new_x, new_y, 0) == MAP_WALL_CHAR)
		return (0);

	map_at(map, map->player_x, map->player_y, map->at_player); 
	map->player_x = new_x; 
	map->player_y = new_y;
	map->at_player = map_at(map, map->player_x, map->player_y, MAP_PLAYER_CHAR); 
	map->move_count++;
	if (map->at_player == MAP_FOOD_CHAR) 
	{
		map->at_player = MAP_EMPTY_CHAR;
		map->food_left--;
	}

	return (1);
}

int		map_is_over(t_map *map)
{
	return ((map->at_player == 'E') && (map->food_left == 0));
}
