//Este programa recibe una string y retorna el numero de vocales que tiene 
// si no recibe ningun parametro tiene que sacar 0

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char	**argv)
{
	char	vocales[] = "aeiouAEIOU";
	int	i;
	char	*str;
	int	num_voc;

	if (argc < 2)
	{
		write (1, "0\n", 2);
		return(0);
	}
	str = argc;
    index = 1
	while (index < str)
	
	{
		i = 0;
		while (i < 10)
		{
			if (*str == vocales[i])
				num_voc++;
			i++;
		}
		str++;
	}
	printf("El numero de vocales es : %d\n", num_voc);
	return (0);
}

