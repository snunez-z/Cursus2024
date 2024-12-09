/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:32:28 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 18:14:59 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

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
static int ft_isspace(char a)
{
	if(( a == '\t') ||( a == '\n') || (a == '\f') 
		|| (a == '\r') || (a == ' ') || (a == 11))
		return (1);
	else
		return (0);
}

char	convert_to_underscore(unsigned int no_lo_uso, char a)
{
	(void)no_lo_uso;
	if (ft_isspace(a))
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
}

char todo_espacios(unsigned int a, char ch)
{
		(void)a;
		(void)ch;
		return '.';
}

char copy_char(unsigned int a, char ch)
{
		(void)a;
		return ch;
}

char password_generate (unsigned int a, char ch)
{
		(void)a;
		if (ch == 'i' || ch == 'I')
				return '1';
		if (ch == 'a' || ch == 'A')
				return '@';
		if (ch == 'o' || ch == 'O')
				return '0';
		return ch;
}
*/
char	*ft_strmapi(char const	*s, char (*accion) (unsigned int, char))
{
	char	*copy;
	int		len;
	int		index;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	copy = (char *) malloc (len * sizeof (char));
	if (copy != NULL)
	{
		index = 0;
		while (s[index] != '\0' && index < len)
		{
			copy [index] = (*accion)(index, s[index]);
			index++;
		}
		copy [index] = 0;
	}
	return (copy);
}
/*
int	main(void)
{
	char	*copy;

	copy = str_copy2("hola MuchaChita");
	printf("%s\n", copy);
	copy = ft_strmapi("hola MuchaChita", convert_to_alpha);
	printf("%s\n", copy);
	copy = ft_strmapi("hola MuchaChita", todo_espacios);
	printf("%s\n", copy);
	copy = ft_strmapi("hola MuchaChita", copy_char);
	printf("%s\n", copy);
	copy = ft_strmapi("hola MuchaChita", convert_to_underscore);
	printf("%s\n", copy);
	copy = ft_strmapi("hola MuchaChita", pasword_generate);
	printf("%s\n", copy);
}*/
