/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:20:31 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/11 13:55:15 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "mlx.h"
#include "font.h"
#include "util.h"

#define FILE_NAME_SIZE	100

Devuelve el índice dentro de la matriz "char_images" donde se almacena la imagen de un
carácter específico. Por ejemplo, '!' (ASCII 33) se almacena
en la primera posición de la matriz, '"' (ASCII 34) se almacena en la
segunda posición de la matriz, y así sucesivamente.

static int	get_char_index(char ch)
{
	return (ch - ' ' - 1);
}

/*
* El nombre del archivo que contiene cada carácter utiliza un formato de nombre específico:
* "./font/---.xpm", donde "---" es el número de tres dígitos del valor ASCII
* del carácter.
* Esta función almacena en "buffer" el nombre del archivo donde se almacena la imagen
* del carácter "ch".
* Por ejemplo, para '!' (ASCII 33), almacenará "./font/033.xpm" en "buffer"
*/
static char	*get_char_file_name(char ch, char *buffer) // ./font/***.xpm
{
	ft_strlcpy(buffer, "./font/", FILE_NAME_SIZE);
	// Hundreds
	buffer[7] = (ch / 100) + '0';
	// Tenths
	buffer[8] = ((ch % 100) / 10) + '0';
	// Units
	buffer[9] = (ch % 10) + '0';
	// Always terminate strings with '\0' :)
	buffer[10] = '\0';
	ft_strlcat(buffer, ".xpm", FILE_NAME_SIZE);
	return (buffer);
}

t_font	*font_load(void	*mlx)
{
	t_font	*font;
	char	buffer[FILE_NAME_SIZE + 1];
	char	ch;
	int		index;

	ft_printf("Loading font images\n");
	font = (t_font *) util_calloc(sizeof(t_font));
	if (!font)
		return (NULL);
	font->mlx = mlx;
	ch = ' ' + 1;
	while (ch <= FONT_LAST_CHAR)
	{
		index = get_char_index(ch);
		font->char_images[index] = util_load_image(mlx,
			get_char_file_name(ch, buffer));
		ch++;
	}
	return (font);
}

void	font_destroy(t_font *font)
{
	char	ch;

	ft_printf("Destroying font...\n");
	ch = ' ' + 1;
	while (ch <= FONT_LAST_CHAR)
	{
		util_destroy_image(font->mlx, font->char_images[get_char_index(ch)]);
		ch++;
	}
	free(font);
}

void	*font_get(t_font *font, char ch)
{
	int	pos;

	pos = get_char_index(ch);
	if (pos < 0 || pos >= get_char_index(FONT_LAST_CHAR))
		return (NULL);
	if (font->char_images[pos] == NULL)
		ft_printf("No image for '%c'\n", ch);
	return (font->char_images[pos]);
}
