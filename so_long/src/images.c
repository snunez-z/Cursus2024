#include <stdlib.h>
#include "ft_printf.h"
#include "mlx.h"
#include "images.h"
#include "util.h"

static void	*load_image(void *mlx, char *file_name)
{
	void	*image;
	int	width;
	int	height;

	image = mlx_xpm_file_to_image(mlx, file_name, &width, &height);
	if (!image)
		ft_printf("Error\nError reading image file '%s'\n", file_name);
	return (image);
}

static void	destroy_image(void* mlx, void	*image)
{
	if (image != NULL)
		mlx_destroy_image(mlx, image);
}

images_t	*images_load(void *mlx)
{
	images_t	*images;

	images = (images_t*)util_calloc(sizeof(images_t));
	if (!images)
		return (NULL);

	images->mlx = mlx;
	images->empty = load_image(mlx, "images/empty.xpm");
	images->wall = load_image(mlx, "images/wall.xpm");
	images->player = load_image(mlx, "images/player.xpm");
	images->food = load_image(mlx, "images/food.xpm");
	images->exit = load_image(mlx, "images/exit.xpm");
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
	destroy_image(images->mlx, images->empty);
	destroy_image(images->mlx, images->wall);
	destroy_image(images->mlx, images->player);
	destroy_image(images->mlx, images->food);
	destroy_image(images->mlx, images->exit);
	free(images);
}
