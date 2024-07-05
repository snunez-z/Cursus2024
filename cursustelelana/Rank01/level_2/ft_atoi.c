/*Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);*/

#include <stdio.h>

int	ft_atoi(const	char *str)
{
	int	value;
	int	is_negative;
		
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	is_negative = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = 1;
		else
			is_negative = 0;
		str++;
	}
	value = 0;
	while (*str != '\0')
	{
		value = (value * 10) + (*str - '0');
		str++;
	}	
	if (is_negative == 1)
		value = value * -1; 
	return (value);
}
/*
int	main(void)
{
	int	value;
	value = ft_atoi ("123");
	printf("%d\n", value);
	value = ft_atoi ("-123");
	printf("%d\n", value);
	value = ft_atoi ("   123");
	printf("%d\n", value);
	value = ft_atoi ("+123");
	printf("%d\n", value);
	value = ft_atoi ("-123");
	printf("%d\n", value);

}*/
