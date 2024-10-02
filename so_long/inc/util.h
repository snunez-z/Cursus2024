#ifndef UTIL_H
 #define UTIL_H

void	*util_calloc(size_t size);
void	*util_load_image(void *mlx, char *file_name);
void	util_destroy_image(void *mlx, void *image);

#endif