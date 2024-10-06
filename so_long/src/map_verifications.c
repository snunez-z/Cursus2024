#include <stddef.h>
#include "dstr.h"
#include "list.h"
#include "map.h"
#include "map_verifications.h"

static int	is_way_complete(t_map_way_verify *verify)
{
	return verify->food_left == 0 && verify->passed_exit;
}

static void	mark_cell(t_map *map, int x, int y)
{
	char	ch;

	ch = map_at(map, x, y, 0);
	map_at(map, x, y, (ch | 128));
}

static int	is_valid_cell(t_map *map, int x, int y)
{
	char	ch;

	if (x < 0 || x >= map_get_width(map) || y < 0 || y >= map_get_height(map))
		return (0);
	ch = map_at(map, x, y, 0);
	return (ch != '1') && ((ch & 0x80) == 0);
}

static int	visit_cell(t_map *map, int x, int y, t_map_way_verify *verify)
{
	char	ch;

	ch = map_at(map, x, y, 0);
	if (ch == MAP_FOOD_CHAR)
		verify->food_left--;
	else if (ch == MAP_EXIT_CHAR)
		verify->passed_exit++;

	mark_cell(map, x, y);

	return is_way_complete(verify);
}

static void walk_map(t_map *map, int x, int y, t_map_way_verify *verify)
{
	if (is_way_complete(verify) || !is_valid_cell(map, x, y) || visit_cell(map, x, y, verify))
		return;

	walk_map(map, x - 1, y, verify);
	walk_map(map, x + 1, y, verify);
	walk_map(map, x, y - 1, verify);
	walk_map(map, x, y + 1, verify);
}

static int	unmark_cell_function(t_map *map, int x, int y, char ch, void *data)
{
	(void)data;
	if (ch & 0x80)
		map_at(map, x, y, (ch & 0x7F));
	return (1);
}

static int	verify_all_walls(t_dstr *row)
{
	size_t	width;
	size_t	index;

	width = dstr_length(row);
	index = 0;
	while(index < width)
	{
		if (dstr_char_at(row, index, 0) != MAP_WALL_CHAR) // Si no se encuentra la constante 1, es falso 
			return (0);
		index++;
	}
	return (1); //retorna true si al salir del loop solo se ha encontrado 1
}

static int	verify_side_walls(t_dstr *row)
{
	size_t	width;

	width = dstr_length(row);
	if (dstr_char_at(row, 0, 0) != MAP_WALL_CHAR // 1ª pos ha de ser un 1
		|| dstr_char_at(row, width - 1, 0) != MAP_WALL_CHAR) // Ultima pos ha de ser un 1
		return (0);
	return (1);
}

static	int	find_player_function(t_map *map, int x, int y, char ch, void *data)
{
	(void)data;
	if (ch == MAP_PLAYER_CHAR)
	{
		map->player_x = x;
		map->player_y = y;
		map->at_player = '0';
		return (0);
	}
	return (1);
}

int	map_verify_square(t_map *map)
{
	size_t	row_count;
	size_t	index;
	size_t	width;

	if (!map || !map->rows) // si el mapa no esta bien
		return (0);
	row_count = list_size(map->rows);
	if (row_count < 3) // si al menos tienes 3 filas
		return (0);

	width = dstr_length(list_get(map->rows, 0));// longitud del primer elemento de la lista dstr
	index = 1;
	while (index < row_count)
	{
		if (dstr_length(list_get(map->rows, index)) != width) //si la siguiente. no tiene la misma long que la primera, es que esta mal
			return (0);
		index++;
	}

	return (1);// retirno true cuando se sale del bucle, que significa, todas las rows son iguales.
}

int	map_verify_walls(t_map *map)
{
	size_t	row_count;
	size_t	index;

	row_count = list_size(map->rows);
	if (!verify_all_walls((t_dstr*)list_get(map->rows, 0))) // es al primera 
		return (0);
	if (!verify_all_walls((t_dstr*)list_get(map->rows, row_count - 1))) // es la ultima, las listas empiezan en cero tambien.
		return (0);

	index = 1;
	while (index < (row_count - 1))
	{
		if (!verify_side_walls((t_dstr*)list_get(map->rows, index)))
			return (0);
		index++;
	}

	return (1);
}

int	map_verify_items(t_map *map)
{
	if (map_count_chars(map, MAP_FOOD_CHAR) == 0 // si no hay ninguna comida
		|| map_count_chars(map, MAP_EXIT_CHAR) != 1 // no hay exactamente uan salida
		|| map_count_chars(map, MAP_PLAYER_CHAR) != 1) // o no hay un solo jugador
		return (0); // Falso
	return (1);
}

int	map_verify_player_position(t_map *map)
{
	map->player_x = 0;
	map->player_y = 0;
	map_loop(map, find_player_function, NULL);
	return (map->player_x > 0 && map->player_y > 0);
}

int	map_verify_way(t_map *map)
{
	t_map_way_verify	verify;

	verify.food_left = map_count_chars(map, MAP_FOOD_CHAR);
	verify.passed_exit = 0;
	walk_map(map, map->player_x, map->player_y, &verify);
	map_loop(map, unmark_cell_function, NULL);
	return is_way_complete(&verify);
}
