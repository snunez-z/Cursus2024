#include <stdio.h>
#include "libft.h"

int main(void)
{
	char	*copy;

	copy = ft_strjoin("hola", "susana");
	printf("%s\n", copy);
	free (copy);
	return (0);
}
