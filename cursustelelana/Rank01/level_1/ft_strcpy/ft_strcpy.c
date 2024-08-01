/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:58:09 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/30 09:59:00 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int index;

    index = 0;
    while (s2[index] != '\0')
    {
        s1 [index] = s2 [index];
        index++;   
    }
    s1 [index] = '\0';
    return (s1);
}

/* int main (void)
{
    char    buffer [100];

   ft_strcpy (buffer, "Hola buena amiga");
   printf("%s\n", buffer);
}*/
