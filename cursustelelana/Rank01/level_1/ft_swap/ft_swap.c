/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:43:39 by snunez-z          #+#    #+#             */
/*   Updated: 2024/07/30 12:44:01 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_swap (int *a, int *b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}
/*
#include <stdio.h>
int main (void)
{
    int a = 13;
    int b = 15;
   
    ft_swap (&a, &b);
    printf("Ahora a vale = %d ", a);
    printf ("Ahora b vale = %d,", b);
    return (0);
}*/
