/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:22:36 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/20 17:01:44 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"

void	*util_calloc(size_t size)
{
	void	*buffer;

	buffer = ft_calloc(size, 1);
	if (!buffer)
		ft_printf("Error:\nNot enough memory\n");
	return (buffer);
}

void	*util_load_image(void *mlx, char *file_name)
{
	void	*image;
	int		width;
	int		height;

	ft_printf("Loading image: %s\n", file_name);
	image = mlx_xpm_file_to_image(mlx, file_name, &width, &height);
	if (!image)
		ft_printf("Error\nError reading image file '%s'\n", file_name);
	return (image);
}

void	util_destroy_image(void *mlx, void *image)
{
	if (image != NULL)
		mlx_destroy_image(mlx, image);
}

int	util_display_error(const char *message, int return_code)
{
	ft_printf("Error\n%s\n", message);
	return (return_code);
}
