/*Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);*/

/*
int	ft_strcmp (char	*s1, char *s2)
{
	
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{

		s1++;
		s2++;
	}
	return (*s1 - *s2);
}	*/

int	ft_strcmp (char	*s1, char *s2)
{
	while (*s1 != '\0' && *s2 != 0)
	{
		if(*s1 == '\0' && *s2 == '\0')
			return (0);
		else if (*s1 != '\0' && *s2 == '\0')
		       return (1);
		else if (*s1 ==	'\0' && *s2 != '\0')
			return (-1);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}


#include <stdio.h>

int	main (int argc, char	**argv)
{
	int	result;

	if (argc < 3)
	{
		printf("usage %s <strings>", argv[1]);
		return (-1);
	}
	result = ft_strcmp (argv[1], argv[2]);
	printf("%d\n",result);
	return (0);
}
