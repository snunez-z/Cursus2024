#include <stddef.h>
#include "ft_printf.h"
#include "dstr.h"
#include "list.h"
#include "map.h"
#include "map_verifications.h"

static	int	count_function(t_map_loop *map_loop) // cuenta una celda y se le llamara cuantas veces como celdas haya
{
	t_count_data	*count_data;

	count_data = (t_count_data *)map_loop->data;
	if (map_loop->ch == MAP_PLAYER_CHAR) // si me encuentro una p anoto
	{
		map_loop->map->player_x = map_loop->x; //guardo la posicion (estructura, dentro de la estructura)
		map_loop->map->player_y = map_loop->y;
		map_loop->map->at_player = '0'; // lo que hay debajo este a cero, no haya nada.
		count_data->player_count++;
	}
	else if (map_loop->ch == MAP_EXIT_CHAR)
		count_data->exit_count++;
	else if (map_loop->ch == MAP_FOOD_CHAR)
		map_loop->map->food_left++; // no anoto la comida porque dentro del mapa ya tengo una variable que hace recuento de las comidas

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
	if (map->width < 3)
		return(0);
	index = 1;
	while (index < map->height)
	{
		row_width = (int)dstr_length(list_get(map->rows, index));
		if (row_width != map->width) //si la siguiente. no tiene la misma long que la primera, es que esta mal
			return (0);
		index++;
	}

	return (1);// retorno true cuando se sale del bucle, que significa, todas las rows son iguales.
}

int	map_verify_items(t_map *map)
{
	t_count_data	count_data;

	ft_printf("Verifying elements in map...\n");
	count_data.exit_count = 0; // Inicializo la salida y el jugador a cero
	count_data.player_count = 0;
	map_loop(map, count_function, &count_data);	// map loop y por cada celda va a llamar a count_function y le pasa el puntero a la estructura
	if (map->food_left == 0 // si no hay ninguna comida
		|| count_data.exit_count != 1 // no hay exactamente uan salida
		|| count_data.player_count != 1) // o no hay un solo jugador
		return (0); // Falso
	return (1);
}
