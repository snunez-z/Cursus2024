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

	map_at(map, x, y, (ch | 128));

	return (verify->food_left == 0 && verify->passed_exit);
}

static void walk_map(t_map *map, int x, int y, t_map_way_verify *verify)
{
	if ((verify->food_left == 0 && verify->passed_exit)
		|| !is_valid_cell(map, x, y) || visit_cell(map, x, y, verify))
		return;

	walk_map(map, x - 1, y, verify);
	walk_map(map, x + 1, y, verify);
	walk_map(map, x, y - 1, verify);
	walk_map(map, x, y + 1, verify);
}

static int	unmark_cell_function(t_map_loop *map_loop)
{
	if (map_loop->ch & 0x80)
		map_at(map_loop->map, map_loop->x, map_loop->y, (map_loop->ch & 0x7F));
	return (1);
}

int	map_verify_way(t_map *map)
{
	t_map_way_verify	verify;

	ft_printf("Verifying map has a solution...\n");
	verify.food_left = map->food_left;
	verify.passed_exit = 0;
	walk_map(map, map->player_x, map->player_y, &verify);
	map_loop(map, unmark_cell_function, NULL);
	return verify.food_left == 0 && verify.passed_exit;
}
