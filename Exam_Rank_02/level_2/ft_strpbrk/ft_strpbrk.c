/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:02:09 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/02 10:00:10 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strpbrk(const char	*s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j= 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				return ((char *) &s1[i]);
			j++;
		}	
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*o_found;

	o_found = ft_strpbrk ("Hola", "milasnu");
	printf("%s\n", o_found);
	return (0);
}*/
