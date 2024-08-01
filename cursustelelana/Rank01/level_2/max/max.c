/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:49:58 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 16:53:23 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int	*tab, unsigned int len)
{
	unsigned	int i;
	int	max;

	i = 0;
	max = 0;
	while (i < len)
	{
		if (tab[i] >= max)
		       max = tab[i];
		i++;
	}
	return (max);	
}

#include <stdio.h>

int	main (void)
{
	int	tab[] = {5,10,40,100,8,54,10,9};

	printf("%d\n", max (tab, 8));
	return (0);
}
