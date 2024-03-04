/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:32:28 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/20 15:46:20 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const	*s, char (*accion) (unsigned int, char))
{
	char	*copy;
	int		len;
	int		index;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	copy = (char *) malloc (len * sizeof (char));
	if (copy != NULL)
	{
		index = 0;
		while (s[index] != '\0' && index < len)
		{
			copy [index] = (*accion)(index, s[index]);
			index++;
		}
		copy [index] = 0;
	}
	return (copy);
}
