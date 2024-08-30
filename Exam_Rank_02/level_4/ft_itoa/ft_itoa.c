/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:52:01 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/30 17:21:47 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr);

int	ft_cont_len (int num)
{
	int	size_num;

	if(num == 0)
		return (2);
	if (num < 0)
		size_num = 1;
	if (num > 0)
		size_num = 0;

	while (num != '\0')
	{
		num = num / 10;
		size_num++;
	}
	return (size_num + 1);

}

int	last_digit(int nbr)
{
	int	last_digit;
	
	if (nbr > 0)
		last_digit = (nbr % 10) + '0';
	if (nbr < 0)
		last_digit = '0' - (nbr % 10);
	return (last_digit);
}

char	*ft_itoa (int nbr)
{
	char 	*num;
	int	last_index;

	num = (char *) malloc(ft_cont_len (nbr) * sizeof(char));
	if (num == NULL)
		return (NULL);
	num [ft_con_len (nbr) -1] = '\0'
	if (nbr == 0)
	{	
		num [0] = '0';
	return (num);
	}
	if (nbr < 0)
		num [0] = '-';
	last_index = ft_cont_len(nbr) - 2;
	while (nbr != 0)
	{
		num[last_index] = last_digit(nbr);
		nbr = nbr / 10;
		last_index --;
	}
	return (num);

}

/* to check the function
#include <stdio.h>

int	main(void)
{
	char	*num;
	num = ft_itoa (123);
	printf("%s\n", num);
	num = ft_itoa (-123);
	printf("%s\n", num);
	num = ft_itoa (-2147483648);
	printf("%s\n", num);
	num = ft_itoa (2147483647);
	printf("%s\n", num);
	return (0);
}*/	
