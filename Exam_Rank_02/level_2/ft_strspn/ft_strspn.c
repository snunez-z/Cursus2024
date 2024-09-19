/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:06:42 by snunez-z          #+#    #+#             */
/*   Updated: 2024/09/19 16:09:12 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	int	ocurrence;
	
	i = 0;
	while (s[i] != '\0')
	{
		ocurrence = 0;
		j = 0;
		while (accept[j] !='\0')
		{
			if (s[i] == accept [j])
				ocurrence = 1;
			j++;
		}
		if (ocurrence == 0)
			return (i);
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main (void)
{
	size_t	num_ocurrences;

	num_ocurrences = ft_strspn ("olia", "olas");
	printf ("%ld\n", num_ocurrences);
	return (0);
}*/


