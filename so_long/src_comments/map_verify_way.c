#include <stddef.h>
#include "ft_printf.h"
#include "map.h"
#include "map_verifications.h"

static int	is_valid_cell(t_map *map, int x, int y)
{
	char	ch;

	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	ch = map_at(map, x, y, 0);
	if(ch == MAP_WALL_CHAR || (ch & 128) != 0)
		return (0);
	else
		return (1);
}

static void	visit_cell(t_map *map, int x, int y, t_map_way_verify *verify)
{
	char	ch;

	ch = map_at(map, x, y, 0); //que char hay en esa posicion (C,E,0)
	if (ch == MAP_FOOD_CHAR)
		verify->food_left--; //me quedan por comer una menos
	else if (ch == MAP_EXIT_CHAR)
		verify->passed_exit = 1; // hay un camino a la salida

	map_at(map, x, y, (ch | 128)); //Para que el jugador no pase por donde ya ha pasado 
								  //o borro lo que habia cuando ha pasado o me hago una copia del mapa o pongo una marca. Un bit
}

static void walk_map(t_map *map, int x, int y, t_map_way_verify *verify)
{
	if ((verify->food_left == 0 && verify->passed_exit) // Fin de recursividad si he pasado por la salida y me he comido todo
		|| !is_valid_cell(map, x, y)) //o si no es valida la celda porque se ha salido o chocado con una pared
		return;

	visit_cell(map, x, y, verify);  //Visita la posicion del jugador
	walk_map(map, x - 1, y, verify); //al llamarse recursivamente visita derecha a izquiera
	walk_map(map, x + 1, y, verify); //al llamarse recursivamente visita izda a derecha
	walk_map(map, x, y - 1, verify); //al llamarse recursivamente visita abajo a arriba
	walk_map(map, x, y + 1, verify); //al llamarse recursivamente visita arriba a abajo
}

static int	unmark_cell_function(t_map_loop *map_loop)
{
	map_at(map_loop->map, map_loop->x, map_loop->y, (map_loop->ch & 127));
	return (1);
}

int	map_verify_way(t_map *map)
{
	t_map_way_verify	verify;

	ft_printf("Verifying map has a solution...\n");
	verify.food_left = map->food_left;
	verify.passed_exit = 0;
	walk_map(map, map->player_x, map->player_y, &verify); //pone una banderita por donde pasa
	map_loop(map, unmark_cell_function, NULL); // cuando acaba hace un loop por el map para quitar las banderitas 
	if (verify.food_left == 0 && verify.passed_exit) //despues de recorrer todo el mapa, me he comido todo y he pasado por la salida
													// el mapa tiene solucion.
		return (1);
	else
		return (0);
}
