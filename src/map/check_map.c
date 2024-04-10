/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:11:03 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/10 11:23:55 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	parse_map(t_data *data)
{

	map_reader(data);
/* Except for the map content, each type of element can be separated by one or
more empty line(s). */

/* Except for the map content which always has to be the last, each type of
element can be set in any order in the file. */

/* Except for the map, each type of information from an element can be separated
by one or more space(s). */

/* The map must be parsed as it looks in the file. Spaces are a valid part of the
map and are up to you to handle. You must be able to parse any kind of map,
as long as it respects the rules of the map.
 */

/* Each element (except the map) firsts information is the type identifier (composed by one 
or two character(s)), followed by all specific informations for each
object in a strict order
->North Texture:
"NO ./path_to_texture 

->Floor color
"F 220,100,0"
*/


//Only 1, 0, W, S, N, E on map
	
//map surronded by walls

/* If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice. */
	return (1);
}