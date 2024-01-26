/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:48:34 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/26 10:42:44 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
/*
char	convert_to_alpha_upper(unsigned	int a, char b)
{
	if (a == 0)
		return (ft_toupper (b) );
	else 
		return (b);
}

char	convert_to_alpha_lower(unsigned	int a, char b)
{	
	if (a == 0)
		return (0);
	else
		return (ft_tolower(b));	
}

static int isspace(char a)
{
	if(( a == '\t') ||( a == '\n') || (a == '\f') || (a == '\r') || (a == ' ') || (a == 11))
		return (1);
	else
		return (0);
}

char	convert_to_underscore(char a)
{
	if (isspace(a))
		return ( '_');
	else
		return (a);
}

char	convert_to_alpha(unsigned int a, char b)
{	
	if (a == 0) 
		return (convert_to_alpha_upper(a, b));
	else  
		return (convert_to_alpha_lower(a, b));
}*/

char	*copy_string(const char	*str)
{
	char	*copy;
	int		len;
	int 	index;
	
	len = ft_strlen(str) + 1;
    copy = (char *)malloc( len * sizeof(char));
	if (copy)
	{
		index = 0;
		while (*str != 0 && index < len )
		{
			copy [index] = str [index];
			str++;
		}
	*copy = 0;
	while(*str != '\0')
		index++;
	return (index);
	}
	return(copy);
}

int	main(void)
{
	char	*copy;

	copy = copy_string( "Hola muchachita");
	printf("%s\n", copy);
}
/*char	*ft_strmapi(const char *str, (*f) (unsigned int, char b)*/
