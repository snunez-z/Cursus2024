/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:07:57 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/17 09:14:00 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	unsigned int	size;
	char			*copy;

	size = ft_strlen(src) + 1;
	copy = malloc(size * sizeof(char));
	ft_strlcpy(copy, src, size);
	return (copy);
}

int	main(void)
{
	char	*copy;

	copy = ft_strdup("Hola");
	printf("%s\n", copy);
	free(copy);
	return (0);
}
