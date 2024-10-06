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

#ifndef MAP_VERIFICATIONS_H
# define MAP_VERIFICATIONS_H

# include "map.h"

typedef struct s_count_data
{
	int		exit_count;
	int		player_count;
}	t_count_data;

typedef struct s_map_way_verify
{
	int		food_left;
	int		passed_exit;
}	t_map_way_verify;

int	map_verify_square(t_map *map);
int	map_verify_fits_into_screen(t_map *map);
int	map_verify_walls(t_map *map);
int	map_verify_items(t_map *map);
int	map_verify_way(t_map *map);

#endif
