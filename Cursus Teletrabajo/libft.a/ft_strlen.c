/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:42:42 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/09 16:55:46 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_strlen(char	*str)
{
	int	len;

	len = 0;
	while (*str != 0)
	{
		str++;
		len++;
	}
	return (len);
}
/*
int	main(void)
{
	char	*texto;
	int		len;

	texto = "Hola";
	len = ft_strlen(texto);
	printf("El texto es :%s\n y la longitud es de %d caracteres\n", texto, len);
	return (0);
}*/
