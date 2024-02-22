#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*copy;

	copy =ft_strtrim ("    SUSANA   ", " ");
    printf("%s\n",copy);
	free (copy);
	copy =ft_strtrim ("``---**SUSANA*-", " `-*");
    printf("%s\n",copy);
	free (copy);
	copy =ft_strtrim ("anoSUSANAano", "ano");
    printf("%s\n",copy);
	free (copy);
	copy =ft_strtrim ("        ", " ");
    printf("[%s]\n",copy);
	free (copy);
}
