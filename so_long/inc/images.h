#ifndef IMAGES_H
 #define IMAGES_H

#define IMAGE_SIZE	32

typedef struct images_s
{
	void	*mlx;
	void	*empty;
	void	*wall;
	void	*player;
	void	*food;
	void	*exit;
} images_t;

images_t	*images_load(void	*mlx);
void	images_destroy(images_t *images);

#endif