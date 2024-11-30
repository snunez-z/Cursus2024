/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa_lower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:28:41 by snunez-z          #+#    #+#             */
/*   Updated: 2024/03/12 11:57:32 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

char	*ft_htoa_lower(unsigned long n)
{
	char	*result;
	int		index;

	result = ft_htoa (n);
	if (!result)
		return (NULL);
	index = 0;
	while (result [index] != '\0')
	{
		result[index] = ft_tolower(result [index]);
		index++;
	}
	return (result);
}
/*
int	main(void)
{
	char	*result;

	result = ft_htoa_lower(255);
	printf("%s\n", result);
	free (result);
	result = ft_htoa_lower(0);
	printf("%s\n", result);
	free (result);
	result = ft_htoa_lower(15);
	printf("%s\n", result);
	free (result);
	result = ft_htoa_lower(2568945);
	printf("%s\n", result);
	free (result);
}*/
