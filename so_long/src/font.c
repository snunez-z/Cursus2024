#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "mlx.h"
#include "font.h"
#include "util.h"

#define FILE_NAME_SIZE	100
#define GET_CHAR_INDEX(ch)	(ch - ' ' - 1)

static void	itoa(char ch, char *buffer)
{
	buffer[0] = (ch / 100) + '0';
	buffer[1] = ((ch % 100) / 10) + '0';
	buffer[2] = (ch % 10) + '0';
	buffer[3] = 0;
}

static char	*get_char_file_name(char ch)
{
	static char buffer[FILE_NAME_SIZE + 1];

	ft_strlcpy(buffer, "./font/", FILE_NAME_SIZE);
	itoa(ch, buffer + ft_strlen(buffer));
	ft_strlcat(buffer, ".xpm", FILE_NAME_SIZE);
	return buffer;
}

font_t	*font_load(void	*mlx)
{
	font_t	*font;
	char	ch;

	ft_printf("Loading font images\n");
	font = (font_t*)util_calloc(sizeof(font_t));
	if (!font)
		return (NULL);

	font->mlx = mlx;
	ch = ' ' + 1;
	while (ch <= FONT_LAST_CHAR)
	{
		font->char_images[GET_CHAR_INDEX(ch)] = util_load_image(mlx, get_char_file_name(ch));
		ch++;
	}

	return font;
}

void	font_destroy(font_t *font)
{
	char ch;

	ft_printf("Destroying font...\n");
	ch = ' ' + 1;
	while (ch <= FONT_LAST_CHAR)
	{
		util_destroy_image(font->mlx, font->char_images[GET_CHAR_INDEX(ch)]);
		ch++;
	}
	free(font);
}

void	*font_get(font_t *font, char ch)
{
	int	pos;

	pos = GET_CHAR_INDEX(ch);
	if (pos < 0 || pos >= GET_CHAR_INDEX(FONT_LAST_CHAR))
		return (NULL);
	if (font->char_images[pos] == NULL)
		ft_printf("No image for '%c'\n", ch);
	return font->char_images[pos];
}