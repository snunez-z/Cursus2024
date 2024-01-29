#include <stdio.h>
#include "libft.h"
/*
void ft_new_toupper(unsigned int index, char *s)
{
	(void) index;
	*s = ft_toupper(*s);
}

void	ft_new_tolower(unsigned int index, char *s)
{
	(void) index;
	*s = ft_tolower (*s);
}

void	ft_new_isspace(unsigned int index, char *s)
{
	(void) index;
	if ((*s == '\t') || (*s == '\n') || (*s == '\f') || (*s == '\r')
		|| (*s == ' ') || (*s == 11))
	*s = '0';
}

void convert_to_underscore(unsigned int index, char *s)
{
	(void) index;
	if (*s == '_')
	*s = ' ';
}
*/
void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	int	index;

	index = 0;
	while (str [index] != '\0')
	{
		(*f)(index, &(str[index]));
		index++;
	}
}
/*
int	main(void)
{
	char str[] = " hola_ muchachita  LINDA";
	ft_convert_to_upper(str, ft_new_toupper);
	printf("%s\n", str);
	
	ft_convert_to_upper(str, ft_new_tolower);
	printf("%s\n", str);
	
	ft_convert_to_upper(str, ft_new_isspace);
	printf("%s\n", str);
	
	ft_convert_to_upper(str, convert_to_underscore);
	printf("%s\n", str);
	return(0);
}*/
