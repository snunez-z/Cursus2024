#include <stddef.h>
#include "ft_printf.h"
#include "dstr.h"
#include "list.h"
#include "map.h"
#include "map_verifications.h"

static	int	count_function(t_map_loop *map_loop)
{
	t_count_data	*count_data;

	count_data = (t_count_data*)map_loop->data;
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

	return (1);
}

int	map_verify_square(t_map *map)
{
	int	index;
	int row_width;

	if (!map || !map->rows) // si el mapa no esta bien
		return (0);
	ft_printf("Verifying map is rectangular...\n");
	map->height = list_size(map->rows);
	if (map->height < 3) // si al menos tienes 3 filas
		return (0);

	map->width = dstr_length(list_get(map->rows, 0));// longitud del primer elemento de la lista dstr
	index = 1;
	while (index < map->height)
	{
		row_width = (int)dstr_length(list_get(map->rows, index));
		if (row_width != map->width) //si la siguiente. no tiene la misma long que la primera, es que esta mal
			return (0);
		index++;
	}

	return (1);// retirno true cuando se sale del bucle, que significa, todas las rows son iguales.
}

int	map_verify_items(t_map *map)
{
	t_count_data	count_data;

	ft_printf("Verifying elements in map...\n");
	count_data.exit_count = 0;
	count_data.player_count = 0;
	map_loop(map, count_function, &count_data);	
	if (map->food_left == 0 // si no hay ninguna comida
		|| count_data.exit_count != 1 // no hay exactamente uan salida
		|| count_data.player_count != 1) // o no hay un solo jugador
		return (0); // Falso
	return (1);
}
