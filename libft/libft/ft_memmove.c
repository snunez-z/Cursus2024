/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:39:37 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 18:48:27 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t len)
{
	int			index;
	char		*dest1;
	const char	*src1;

	dest1 = (char *) dst;
	src1 = (const char *) src;
	if ((dest1 > src1) && (src1 + len) > dest1)
	{
		index = len - 1;
		while (index >= 0)
		{
			dest1 [index] = src1 [index];
			index--;
		}
		return (dst);
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
/*
int	main(void)
{
	char	buffer [100] = "Hola";
	char	dest [20] = "";
	char	*src = &(buffer [0]);
	char	*dest1 = &(buffer [2]);

	ft_memmove(dest, buffer, 5);
	printf("%s\n", dest);
	ft_strlcpy(buffer, "Hola Caracola", 14);
	ft_memmove(dest1, src, 7);
	printf("%s\n", buffer);
	ft_strlcpy(buffer, "Hola Caracola", 14);
	src = &(buffer[2]);
	dest1 = &(buffer[0]);
	ft_memmove(dest1, src, 7);
	printf("%s\n", buffer);
	ft_strlcpy(buffer, "Hola Caracola", 14);
	src = &(buffer[2]);
	dest1 = &(buffer[0]);
	ft_memmove(dest1, src, 0);
	printf("%s\n", buffer);
	return (0);
}*/
/*
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int             main(int argc, const char *argv[])
{
        char    src[] = "lorem ipsum dolor sit amet";
        char    *dest;
        int             arg;

        dest = src + 1;
        if (argc == 1)
                return (0);
        else if ((arg = atoi(argv[1])) == 1)
        {
                if (dest != ft_memmove(dest, "consectetur", 5))
                        write(1, "dest's adress was not returned\n", 31);
                write(1, dest, 22);
        }
        else if (arg == 2)
        {
                if (dest != ft_memmove(dest, "con\0sec\0\0te\0tur", 10))
                        write(1, "dest's adress was not returned\n", 31);
                write(1, dest, 22);
        }
        else if (arg == 3)
        {
                if (dest != ft_memmove(dest, src, 8))
                        write(1, "dest's adress was not returned\n", 31);
                write(1, dest, 22);
        }
        else if (arg == 4)
        {
                if (src != ft_memmove(src, dest, 8))
                        write(1, "dest's adress was not returned\n", 31);
                write(1, dest, 22);
        }
        else if (arg == 5)
        {
                if (src != ft_memmove(src, dest, 0))
                        write(1, "dest's adress was not returned\n", 31);
               write(1, dest, 22);
        }
        return (0);
}
*/
