/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:18:57 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 10:35:17 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * This module defines the game map and basic game logic such as map
 * verification, player movement and game over detection.
 * This modules is "display agnostic", meaning it doesn't assume where or how
 * the map will be displayed. As a result, this module has no dependency on
 * MinilibX.
 */
#ifndef MAP_H
# define MAP_H

# include "list.h"

/* The character for each item type */
# define MAP_EMPTY_CHAR	'0'
# define MAP_EXIT_CHAR	'E'
# define MAP_FOOD_CHAR	'C'
# define MAP_PLAYER_CHAR'P'
# define MAP_WALL_CHAR	'1'

/*
 * Structure this module uses. Fields are:
 * "rows" a list containing each line (row) of the map
 * "width" the width of the map (maximum X value)
 * "height" the height of th map (maximum Y value)
 * "player_x" current X position of the player
 * "player_y" current Y position of the player
 * "at_player" what was in current player's cell before moving to that cell.
 *             This is needed in order to know if the cell contained food
 *             (in which case, the food has to be "eaten") or the exit (in
 *             which case, the exit must be restored when the user moves away
 *             from the cell)
 * "food_left" how many food cells are yet to be eaten
 */
typedef struct s_map
{
	t_list	*rows;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	at_player;
	int		food_left;
}	t_map;

/*
 * This structe is passed as parameter to the callback function called from
 * "map_loop". Fields:
 * "map" the t_map instance of the map being "loop"ed
 * "x" current X position of the cell being inspected
 * "y" current Y position of the cell being inspected
 * "ch" the character in (x,y) cell
 * "data" extra data specified as last parameter to "map_loop"
 *
 * See "map_loop" function for more details
 */
typedef struct s_map_loop
{
	t_map	*map;
	int		x;
	int		y;
	char	ch;
	void	*data;
}	t_map_loop;

/*
 * Reads the map from a file and verifies the map is valid.
 * The following verifications are made:
 * - The map is rectagular (meaning all lines have the same length)
 * - The map is surrounded by walls
 * - There is one and only one player, one and only one exit and at least one
 *   food
 * - There is a valid way to eat all food and reach the exit
 * Parameters:
 * "file_name" the name of the file containing the map
 *
 * Returns the allocated, initialized and verified "t_map" instance or NULL if
 * any error (file reading, memory allocation or map verification) occurs
 */
t_map	*map_read(const char *file_name);

/*
 * Frees all the memory allocated in "map_read"
 * Parameter:
 * - "map" the "t_map" instance to free
 */
void	map_destroy(t_map *map); // libera todo lo que el mapa reserva.

/*
 * Returns the character in one cell of the map.
 * Optionally it can be changed too.
 * Parameters:
 * "map" the "t_map" instance to get/change the character from
 * "x" the X index of the cell to get/change
 * "y" the Y index of the cell to get/change
 * "ch" if zero, then the character at position "x,y" is not modified,
 *      otherwise, the character at position "pos" will be replaced by this one
 *
 * Returns the character that WAS at position "x,y" before replacing it
 */
char	map_at(t_map *map, int column, int row, char ch);

/*
 * Tries to move the player. If the movement is valid, this will change current
 * "player_x" and "player_y" fields.
 * Parameters:
 * - "map" the "t_map" to perform the movement into
 * - "inc_x" number of cells to move the player right (if positive)
 *           or left (if negative)
 * - "inc_y" number of cells to move the player down (if positive)
 *           or up (if negative)
 *
 * Returns true (non-zero) if the movement was valid and the player is now
 *         positioned in its new "player_x" and "player_y". Previous player
 *         location will now contain whatever character was there before,
 *         unless it was a food, in which case it will have disappeared
 *         (replaced by a MAP_EMPTY_CHAR character)
 * Returns false (zero) if movement was not valid (either tried to move into a
 *         wall or beyond map limits)
 */
int		map_move_player(t_map *map, int inc_x, int inc_y);

/*
 * Returns true (non-zero) if the player is located in the cell containing the exit
 *         and there is no food left to each
 * Returns false (zero) otherwise
 */
int		map_is_over(t_map *map);

/*
 * Function that visit each cell of the map and calls a function for each of
 * these cells.
 * Parameters:
 * - "map": the "t_map" instance to loop through
 * - "fn": the "callback" function to call for each cell. This function will
 *         receive a structure containing all the details for the cell being
 *         visited, giving the function the necessary information to do
 *         whichever duty it needs.
 * - "data": extra data passed to the callback function. This may be necessary
 *           if the "t_map_loop" information passed as parameter is not enough
 *           information for the duty it has to perform.
 *
 * Let's explain it with one example:
 * One of the map verifications checks whether there is one player, one exit
 * and at least one food. To perform this verification, this function is called
 * passing "t_count_data" (see "map_verifications.h") as extra "data".
 * So, for each cell, the callback function will be called with the character
 * in each cell. The callback function can then check the character and update
 * the "t_count_data" with the number of food, player and exits.
 */
void	map_loop(t_map *map, int (*fn)(t_map_loop*), void *data);

#endif
