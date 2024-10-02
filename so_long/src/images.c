#include <stdlib.h>
#include "ft_printf.h"
#include "mlx.h"
#include "images.h"
#include "util.h"

images_t	*images_load(void *mlx)
{
	images_t	*images;

	ft_printf("Loading images\n");
	images = (images_t*)util_calloc(sizeof(images_t));
	if (!images)
		return (NULL);

	images->mlx = mlx;
	images->empty = util_load_image(mlx, "images/empty.xpm");
	images->wall = util_load_image(mlx, "images/wall.xpm");
	images->player = util_load_image(mlx, "images/player.xpm");
	images->food = util_load_image(mlx, "images/food.xpm");
	images->exit = util_load_image(mlx, "images/exit.xpm");
	if (!images->empty || !images->wall || !images->player
		|| !images->food || !images->exit)
	{
		images_destroy(images);
		return (NULL);
	}

	return images;
}

void	images_destroy(images_t *images)
{
	util_destroy_image(images->mlx, images->empty);
	util_destroy_image(images->mlx, images->wall);
	util_destroy_image(images->mlx, images->player);
	util_destroy_image(images->mlx, images->food);
	util_destroy_image(images->mlx, images->exit);
	free(images);
}
