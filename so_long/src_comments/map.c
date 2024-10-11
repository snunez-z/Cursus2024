/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:22:54 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/11 13:18:44 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "dstr.h"
#include "list.h"
#include "map.h"
#include "util.h"

void	map_destroy(t_map *map) // libera la reserva para el mapa (listas y el calloc)
{
	if (!map)
		return ;
	if (map->rows != NULL)
		list_destroy(map->rows);
	free(map);
}

int	map_move_player(t_map *map, int inc_x, int inc_y) // mover el jugador de sitio 
{
	int	new_x;
	int	new_y;

	new_x = map->player_x + inc_x; // nuevas posiciones 
	new_y = map->player_y + inc_y; // nuevas posiciones
	if (new_x < 0 || new_y < 0
		|| new_x >= map->width || new_y >= map->height
		|| map_at(map, new_x, new_y, 0) == MAP_WALL_CHAR)
		return (0); //no se puede mover

	map_at(map, map->player_x, map->player_y, map->at_player); //at player se mete lo que habia antes de que pase el jugador 
	map->player_x = new_x; // nuevo movimiento
	map->player_y = new_y;
	map->at_player = map_at(map, map->player_x, map->player_y, MAP_PLAYER_CHAR); // el jugador pasa a ese nuevo movimiento 
	if (map->at_player == MAP_FOOD_CHAR) // excepcion comida
	{
		map->at_player = MAP_EMPTY_CHAR;
		map->food_left--;
	}
	return (1);
}

int		map_is_over(t_map *map)
{
	 /*Devuelve verdadero (distinto de cero) si el jugador está ubicado en la celda que contiene la salida y no queda comida para ninguno
     Devuelve falso (cero) en caso contrario*/
	return ((map->at_player == 'E') && (map->food_left == 0));
}

void	map_loop(t_map *map, int (*fn)(t_map_loop *), void *data)
{
	t_map_loop	map_loop; // estructura 

	map_loop.map = map; // campo mapa de la estructura es el mapa 
	map_loop.data = data; // lo que le pase yo como data
	map_loop.y = 0; // inicialzo la fila  y a cero
	while (map_loop.y < map->height)
	{
		map_loop.x = 0; // inicilizo las columnas a cero 
		while (map_loop.x < map->width) 
		{
			map_loop.ch = map_at(map, map_loop.x, map_loop.y, 0); // retorne lo que hay en cada celda sin cambiarlo
			if (fn(&map_loop) == 0) // si la funcion retorna cero para.
				return ;
			map_loop.x++; //sigue a la sigiente celda 
		}
		map_loop.y++;
	}
}
