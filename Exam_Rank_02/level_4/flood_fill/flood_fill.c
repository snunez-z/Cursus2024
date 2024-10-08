/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:38:06 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 14:38:10 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char content;
	t_point movement;

	content = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';

	// Abajo: y + 1
	movement.x = begin.x;
	movement.y = begin.y + 1;
	if (movement.y < size.y && tab[movement.y][movement.x] == content)
		flood_fill(tab, size, movement);

	// Arriba: y - 1
	movement.x = begin.x;
	movement.y = begin.y - 1;
	if (movement.y >= 0 && tab[movement.y][movement.x] == content)
		flood_fill(tab, size, movement);

	// Izquierda: x - 1
	movement.y = begin.y;
	movement.x = begin.x - 1;
	if (movement.x >= 0 && tab[movement.y][movement.x] == content)
		flood_fill(tab, size, movement);

	// Derecha: x + 1
	movement.y = begin.y;
	movement.x = begin.x + 1;
	if (movement.x < size.x && tab[movement.y][movement.x] == content)
		flood_fill(tab, size, movement);
}
