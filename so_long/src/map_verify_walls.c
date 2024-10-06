#include <stddef.h>
#include "ft_printf.h"
#include "dstr.h"
#include "list.h"
#include "map.h"
#include "map_verifications.h"

static int	verify_all_walls(t_dstr *row)
{
	int	width;
	int	index;

	width = dstr_length(row);
	index = 0;
	while (index < width)
	{
		if (dstr_char_at(row, index, 0) != MAP_WALL_CHAR) // Si no se encuentra la constante 1, es falso 
			return (0);
		index++;
	}
	return (1); //retorna true si al salir del loop solo se ha encontrado 1
}

static int	verify_side_walls(t_dstr *row)
{
	int	width;

	width = dstr_length(row);
	if (dstr_char_at(row, 0, 0) != MAP_WALL_CHAR // 1ª pos ha de ser un 1
		|| dstr_char_at(row, width - 1, 0) != MAP_WALL_CHAR) // Ultima pos ha de ser un 1
		return (0);
	return (1);
}

int	map_verify_walls(t_map *map)
{
	int	index;

	ft_printf("Verifying map walls...\n");
	if (!verify_all_walls(list_get(map->rows, 0))) // es al primera 
		return (0);
	if (!verify_all_walls(list_get(map->rows, map->height - 1))) // es la ultima, las listas empiezan en cero tambien.
		return (0);
	index = 1;
	while (index < (map->height - 1))
	{
		if (!verify_side_walls(list_get(map->rows, index)))
			return (0);
		index++;
	}
	return (1);
}
