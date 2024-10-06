/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:22:54 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 14:07:59 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "dstr.h"
#include "list.h"
#include "map.h"
#include "map_verifications.h"
#include "util.h"
#include "count_data.h"

static void	destroy_line(void *line)
{
	dstr_destroy ((t_dstr *) line);
}

static int	read_line_into_buffer(int fd, t_dstr *line)
{
	ssize_t	read_result;
	char	ch;

	read_result = read(fd, &ch, 1);
	while (read_result == 1 && ch != '\n')
	{
		if (dstr_append_char(line, ch) == NULL)
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

static t_dstr	*read_line(int fd) // lee una linea y devuelve el * a dstr, que es una linea.
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
	t_list	*rows; // las lista con cada una de las lineas
	t_dstr	*line; // una linea

	rows = NULL; // inicialmente no hay ninguna
	line = read_line(fd);
	while (line != NULL && dstr_length(line) > 0) // Mientras la linea sea leible y no este vacia- que haya \n al final.
	{
		rows = list_append(rows, line, destroy_line);//añade
		if (!rows)
			return (NULL);
		line = read_line(fd); 
	}
	if (line == NULL)
	{
		list_destroy(rows, destroy_line);
		return (NULL);
	}
	dstr_destroy(line);
	return (rows); // puede fallar al leer la linea , falla al añadir la linea 
}

static int	count_char_function(t_map *map, int x, int y, char ch, void *data)
{
	struct s_count_data	*count_data;

	(void)map;
	(void)x;
	(void)y;

	count_data = (struct s_count_data *)data;
	if (ch == count_data->char_to_find)
		count_data->count++;
	return (1);
}

static int	verify_map(t_map *map)
{
	if (!map_verify_square(map))
	{
		ft_printf("Error\nMap is not rectangular\n");
		return 0;
	}
		
	if (!map_verify_walls(map))
	{
		ft_printf("Error\nMap is not surrounded by walls\n");
		return 0;
	}
	if (!map_verify_items(map))
	{
		ft_printf("Error\nMap does not have the required elements\n");
		return 0;
	}
	if (!map_verify_player_position(map))
	{
		ft_printf("Error\nInvalid initial player position\n");
		return 0;
	}
	if (!map_verify_way(map))
	{
		ft_printf("Error\nMap does not have a valid way\n");
		return 0;
	}
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

void	map_destroy(t_map *map) // libera la reserva para el mapa (listas y el calloc)
{
	if (!map)
		return ;
	if (map->rows != NULL)
		list_destroy(map->rows, destroy_line);
	free(map);
}

int	map_get_width(t_map *map)
{
	return ((int)dstr_length((t_dstr *)list_get(map->rows, 0))); // retorna el ancho de la primera fila. 
}

int	map_get_height(t_map *map)
{
	return ((int)list_size(map->rows)); // tiene tantas filas como elemntos tenga la lista.
}

char	map_at(t_map *map, int column, int row, char ch)
{
	return (dstr_char_at(list_get(map->rows, row), column, ch));
}

void	map_write(t_map *map, int fd)
{
	t_list	*node;

	node = map->rows;
	while (node != NULL)
	{
		dstr_write((t_dstr *)node->data, fd, 1);
		node = node->next;
	}
}

int	map_move_player(t_map *map, int inc_x, int inc_y)
{
	int	new_x;
	int	new_y;

	new_x = map->player_x + inc_x; // nuevas posiciones 
	new_y = map->player_y + inc_y; // nuevas posiciones
	if (new_x < 0 || new_y < 0
		|| new_x >= map_get_width(map) || new_y >= map_get_height(map)
		|| map_at(map, new_x, new_y, 0) == MAP_WALL_CHAR)
		return (0); //no se puede mover

	map_at(map, map->player_x, map->player_y, map->at_player); //at player se mete lo que habia antes de que pase el jugador 
	map->player_x = new_x; // nuevo movimiento
	map->player_y = new_y;
	map->at_player = map_at(map, map->player_x, map->player_y, MAP_PLAYER_CHAR); // el jugador pasa a ese nuevo movimiento 
	if (map->at_player == MAP_FOOD_CHAR) // excepcion comida
		map->at_player = '0';

	return (1);
}

int	map_count_chars(t_map *map, char ch)
{
	struct s_count_data	count_data;

	count_data.char_to_find = ch;
	count_data.count = 0;

	map_loop(map, count_char_function, &count_data);
	return (count_data.count);
}

void	map_loop(t_map *map, int (*fn)(t_map *, int, int, char, void*), void *data)
{
	int	x;
	int	y;
	int	width;
	int	height;
	char	ch;

	width = map_get_width(map);
	height = map_get_height(map);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			ch = map_at(map, x, y, 0);
			if (!fn(map, x, y, ch, data))
				return ;
			x++;
		}
		y++;
	}
}

/*
int main(int argc, char **argv)
{
	list_t	*map;

	if (argc < 2)
		return 0;
	map = map_read(argv[1]);
	map_write(map, 0);
	map_destroy(map);
	return 0;
}
*/
