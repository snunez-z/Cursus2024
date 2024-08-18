/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:38:49 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 14:40:12 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     search_max(int  *numbers, int num_num)
{
        int     i;
        int     max;
        int     j;

        i = 0;
        j = 0;
        max = numbers[j];
        while (i < num_num)
        {

                if (numbers[i] >= max)
                {
                        max = numbers[i];
                        j = i;
                }
                i++;
        }
        return (j);
}


void sort_int_tab (int *tab, unsigned int size)
{
        int pos_max;
	int	aux;

        if(size <= 1)
            return;         
        pos_max = search_max(tab, size);
        aux = tab[size - 1];
        tab [size - 1] = tab [pos_max];
        tab[pos_max] = aux;
        
        sort_int_tab(tab, size - 1);
}

#include <stdio.h>

int     main(void)
{
        int     numbers [] = {4,8,2,6,3,9, 8,120,6,80};
        int     i;

        sort_int_tab (numbers, 10);
        i = 0;
        while (i < 10)
        {
                printf ("%d ", numbers[i]);
                i++;
        }
        return (0);
}

