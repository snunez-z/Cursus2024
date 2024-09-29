#include "game.h"
#include "util.h"

static int usage(char *program_name)
{
	util_write("Usage: ");
	util_write(program_name);
	util_write(" <path_to_map_file>\n");
	return (1);
}

int	main(int argc, char **argv)
{
	game_t	*game;

	if (argc < 2)
		return usage(argv[0]);

	game = game_create(argv[1]);
	if (game != NULL)
		game_run(game);

	return (0);
}