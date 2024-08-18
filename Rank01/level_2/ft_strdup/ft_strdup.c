/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:43:45 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/31 15:19:00 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char	*src)
{
	char	*copy;
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	copy = malloc ((i + 1) * sizeof (char));
	if (copy == NULL)
	{
		free (copy);
		return (NULL);
	}
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*copy;
	
	copy = ft_strdup ("Hola");
	printf("%s\n", copy);
	free (copy);
	return (0);
}*/
