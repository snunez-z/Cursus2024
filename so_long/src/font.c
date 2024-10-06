/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:20:31 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 11:32:05 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "mlx.h"
#include "font.h"
#include "util.h"

#define FILE_NAME_SIZE	100

static int	get_char_index(char ch)
{
	return (ch - ' ' - 1);
}

static char	*get_char_file_name(char ch) // ./font/***.xpm
{
	static char	buffer[FILE_NAME_SIZE + 1];
	char	*char_num;

	ft_strlcpy(buffer, "./font/", FILE_NAME_SIZE);
	char_num = buffer + ft_strlen(buffer);
	char_num[0] = (ch / 100) + '0';
	char_num[1] = ((ch % 100) / 10) + '0';
	char_num[2] = (ch % 10) + '0';
	char_num[3] = 0;
	ft_strlcat(buffer, ".xpm", FILE_NAME_SIZE);
	return (buffer);
}

t_font	*font_load(void	*mlx)
{
	t_font	*font;
	char	ch;

	ft_printf("Loading font images\n");
	font = (t_font *) util_calloc(sizeof(t_font));
	if (!font)
		return (NULL);
	font->mlx = mlx;
	ch = ' ' + 1;
	while (ch <= FONT_LAST_CHAR)
	{
		font->char_images[get_char_index(ch)] = util_load_image(mlx, get_char_file_name(ch));
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
