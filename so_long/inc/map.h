/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:18:57 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 10:35:17 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "list.h"

typedef struct map_s
{
	t_list	*rows;
	int		player_x;
	int		player_y;
	char	at_player;
}	t_map;

t_map	*map_read(const char *file_name);
void	map_destroy(t_map *map);
void	map_write(t_map *map, int fd);
int		map_get_width(t_map *map);
int		map_get_height(t_map *map);
char	map_at(t_map *map, int x, int y);
int		map_move_player(t_map *map, int inc_x, int inc_y);
int		map_count_chars(t_map *map, char ch);
void	map_loop(t_map *map, int (*fn)(t_map*, int, int, char, void *), void *data);

#endif
