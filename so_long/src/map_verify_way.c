#include <stddef.h>
#include "libft.h"
#include "ft_printf.h"
#include "map.h"
#include "map_verifications.h"
#include "util.h"

static void	add_coordinate(t_map *map, t_list **visited, int x, int y)
{
	char			ch;
	t_list			*new_node;
	t_coordinate	*coordinate;

	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return;
	ch = map_get_char_at(map, x, y);
	if (ch == MAP_WALL_CHAR || (ch & 128))
		return;
	coordinate = util_calloc(sizeof(t_coordinate));
	if (!coordinate)
		ft_lstclear(visited, free);
	else
	{
		coordinate->x = x;
		coordinate->y = y;
		new_node = ft_lstnew(coordinate);
		if (!new_node)
			ft_lstclear(visited, free);
		else
			ft_lstadd_front(visited, new_node);
	}
}

static void	pop_coordinate(t_list **visited, t_map_way_verify *verify)
{
	t_list	*node;

	node = *visited;
	verify->x = ((t_coordinate*)node->content)->x;
	verify->y = ((t_coordinate*)node->content)->y;
	*visited = node->next;
	ft_lstdelone(node, free);
}

static void	visit_cell(t_map *map, t_map_way_verify *verify)
{
	char	ch;

	ch = map_get_char_at(map, verify->x, verify->y);
	if (ch == MAP_FOOD_CHAR)
		verify->food_left--; 
	else if (ch == MAP_EXIT_CHAR)
		verify->passed_exit = 1; 

	map_set_char_at(map, verify->x, verify->y, (ch | 128));
}

static int	unmark_cell_function(t_map_loop *map_loop)
{
	char unmarked_char;

	unmarked_char = (map_loop->ch & 127);
	map_set_char_at(map_loop->map,
	                map_loop->x,
	                map_loop->y,
	                unmarked_char);
	return (1);
}

int	map_verify_way(t_map *map)
{
	t_map_way_verify	verify;
	t_list				*visited;

	ft_printf("Verifying map has a solution...\n");
	verify.food_left = map->food_left;
	verify.passed_exit = 0;
	visited = NULL;
	add_coordinate(map, &visited, map->player_x, map->player_y);
	while (visited != NULL && (verify.food_left > 0 || verify.passed_exit == 0))
	{
		pop_coordinate(&visited, &verify);
		visit_cell(map, &verify);
		add_coordinate(map, &visited, verify.x - 1, verify.y);
		add_coordinate(map, &visited, verify.x + 1, verify.y);
		add_coordinate(map, &visited, verify.x, verify.y - 1);
		add_coordinate(map, &visited, verify.x, verify.y + 1);
	}
	ft_lstclear(&visited, free);
	map_loop(map, unmark_cell_function, NULL); 
	return (verify.food_left == 0 && verify.passed_exit);
}
