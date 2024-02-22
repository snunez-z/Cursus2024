#include <stdio.h>
#include "libft.h"

static void ft_convert_to_upper(unsigned int c, char *s)
{
	(void)c;
	*s = ft_toupper(*s);
}

int	main(void)
{
	char	buffer [25];

	ft_strlcpy(buffer, "susana nunez zamora", 25);
	ft_striteri (buffer, ft_convert_to_upper);
	printf("%s\n", buffer);
	return (0);	
}
