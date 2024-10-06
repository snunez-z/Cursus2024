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

# define MAP_EXIT_CHAR	'E'
# define MAP_FOOD_CHAR	'C'
# define MAP_PLAYER_CHAR	'P'
# define MAP_WALL_CHAR	'1'

typedef struct s_map
{
	t_list	*rows;
	int		player_x;
	int		player_y;
	char	at_player;
}	t_map;

t_map	*map_read(const char *file_name); // creacion devuelve el puntero (que es nu numero) que es lo que van a recibir el resot como argumento.
void	map_destroy(t_map *map); // libera todo lo que el mapa reserva.
void	map_write(t_map *map, int fd);// para quitar.
int		map_get_width(t_map *map); // nos devuelve el ancho del mapa para saber si podemos movernos, si hemos llegado a la pared.
int		map_get_height(t_map *map);// nos devuelve alto del mapa para saber si hemso llegado al muro.
char	map_at(t_map *map, int x, int y, char ch); // que caracter en una posicion y te permite ademas cambiarlo.
int		map_move_player(t_map *map, int inc_x, int inc_y); // Cambia de sitio la p
int		map_count_chars(t_map *map, char ch);//cuantos caracteres ch hay. Lo necesitamos para detectar cuando hemos comido.
void	map_loop(t_map *map, int (*fn)(t_map*, int, int, char, void *), void *data);//Recorrer el mapa.Contar carcateres.

#endif
