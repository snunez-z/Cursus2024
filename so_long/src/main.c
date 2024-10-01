#include "ft_printf.h"
#include "game.h"
#include "util.h"

int	main(int argc, char **argv)
{
	game_t	*game;

	if (argc < 2)
	{
		ft_printf("Error\nUsage: %s <path_to_map_file>\n");
		return (1);
	}

	game = game_create(argv[1]);
	if (game != NULL)
		game_run(game);

	return (0);
}