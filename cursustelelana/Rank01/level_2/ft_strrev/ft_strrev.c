/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:29:31 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/31 17:03:13 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrev(char	*str)
{
	int	len;
	char	aux;
	int	i;

	i = 0;
	len = 0;

        while (str[len] != '\0')
		len++;
	len = len -1;
	while (i < len)
	{	
		aux = str[i];
		str[i] = str[len];
		str[len] = aux;
		i++;	
		len--;
	}
	return (str);
}
/*
#include <stdio.h>

int	main (void)
{
	char	message [] = " HOLA AMIGA DEL ALMA";
	
	printf( "%s\n", ft_strrev (message));
	return (0);
}*/
