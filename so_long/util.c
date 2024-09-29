#include <stdlib.h>
#include <unistd.h>
#include "util.h"

static void write_number(size_t number)
{
	char digit;

	if (number >= 10)
		write_number(number / 10);
	digit = (number % 10) + '0';
	write(1, &digit, 1);
}

void util_write(const char *str)
{
	while (*str)
	{
		write(0, str, 1);
		str++;
	}
}

void util_write_line(const char *str)
{
	util_write(str);
	util_write("\n");
}

void util_write_position(size_t x, size_t y, char ch)
{
	write_number(x);
	write(1, "x", 1);
	write_number(y);
	write(1, "=", 1);
	write(1, &ch, 1);
	write(1, "\n", 1);
}

void	*util_calloc(size_t size)
{
	char	*buffer;
	size_t	pos;

	buffer = malloc(size);
	if (!buffer)
	{
		util_write_line("Not enough memory");
		return (NULL);
	}
	pos = 0;
	while (pos < size)
	{
		buffer[pos] = 0;
		pos++;
	}
	return buffer;
}