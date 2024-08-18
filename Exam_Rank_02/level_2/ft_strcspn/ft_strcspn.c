/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:35:26 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/31 13:38:31 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strcspn (const char *s, const char *reject)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (reject [j] == s[i])
				return(i);
			j++;
		}
		i++;
	}
	return (i);	
}
/*
#include <stdio.h>

int	main(void)
{
	int	result;

	result = ft_strcspn ("Hola", "Hola");
	printf("%d\n", result);
	result = ft_strcspn ("Hola", "ola");
	printf("%d\n", result);
	result = ft_strcspn ("Hola", "la");
	printf("%d\n", result);
	result = ft_strcspn ("Hola", "DSC");
	printf("%d\n", result);

}*/

