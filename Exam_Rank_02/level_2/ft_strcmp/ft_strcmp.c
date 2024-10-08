/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 08:47:00 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/15 13:22:16 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strcmp (char	*s1, char *s2)
{
	while (*s1 != '\0' && *s2 != 0 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/* Main to check the function
#include <stdio.h>

int	main (int argc, char	**argv)
{
	int	result;

	if (argc < 3)
	{
		printf("usage %s <strings>", argv[1]);
		return (-1);
	}
	result = ft_strcmp (argv[1], argv[2]);
	printf("%d\n",result);
	return (0);
} */
