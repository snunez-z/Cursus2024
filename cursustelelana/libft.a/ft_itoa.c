/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:06:54 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/19 18:13:45 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_cont_len(int n)

{
	int	size_n;
	
	if (n >= 0)
		size_n = 0;
	if (n < 0)
		size_n = 1;
	while (n != 0)
	{
		n = n/10;
		size_n++;
	}
	return (size_n +1);
} 

char	*ft_itoa(int n)
{
	char	last_figure;
    int		last_index;
	char	rest_number;
	char	*len;
		
	len = (char	*)malloc (ft_cont_len (n));
	if (len == 0)
	{
		return (0);
	}
	last_index = ft_cont_len (n) - 1;
	len [last_index] = '\0';
	last_index = last_index - 1;
	while (last_index >= 0)
	{
		last_figure = (n % 10) + '0';
		rest_number = n/10;
		n = rest_number;
		len [last_index] = last_figure;
		last_index--; 
	}	
	return (len);
}

int	main(void)
{
	char	*len;

	len = ft_itoa (1256); 
	printf ("%s", len);
	return (0);
}

/* queda hacer funcion de los casos que darian error, si me psan el valor cero en el que habria que reservar meoria para 2 y el caso de -2147483648 que se puede hacer con lcpy.*/
