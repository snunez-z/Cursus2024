/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:57:25 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/20 16:59:13 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstr.h"
#include "list.h"
#include "map.h"

char	map_at(t_map *map, int column, int row, char ch)
{
	t_dstr	*line;

	line = list_get(map->rows, row);
	return (dstr_char_at(line, column, ch));
}
