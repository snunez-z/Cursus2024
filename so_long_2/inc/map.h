/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:18:57 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/20 16:46:03 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "list.h"

# define MAP_EMPTY_CHAR	'0'
# define MAP_EXIT_CHAR	'E'
# define MAP_FOOD_CHAR	'C'
# define MAP_PLAYER_CHAR 'P'
# define MAP_WALL_CHAR	'1'

typedef struct s_map
{
	t_list	*rows;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	at_player;
	int		food_left;
	int		move_count;
}	t_map;

typedef struct s_map_loop
{
	t_map	*map;
	int		x;
	int		y;
	char	ch;
	void	*data;
}	t_map_loop;

t_map	*map_read(const char *file_name);
void	map_destroy(t_map *map);
char	map_at(t_map *map, int column, int row, char ch);
int		map_move_player(t_map *map, int inc_x, int inc_y);
int		map_is_over(t_map *map);
void	map_loop(t_map *map, void (*fn)(t_map_loop*), void *data);

#endif
