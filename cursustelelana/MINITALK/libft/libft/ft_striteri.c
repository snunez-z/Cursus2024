/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:30:39 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 18:17:20 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"
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
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		(*f)(index, &(s[index]));
		index++;
	}
}
/*
int	main(void)
{
	char str[] = " hola_ muchachita  LINDA";
	ft_striteri(str, ft_new_toupper);
	printf("%s\n", str);
	
	ft_striteri(str, ft_new_tolower);
	printf("%s\n", str);
	
	ft_striteri(str, ft_new_isspace);
	printf("%s\n", str);
	
	ft_striteri(str, convert_to_underscore);
	printf("%s\n", str);
	return(0);
}*/
