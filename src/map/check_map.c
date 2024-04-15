/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:11:03 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/11 19:13:07 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

/* Except for the map content, each type of element can be separated by one or
		more empty line(s). */
		
		/* Except for the map content which always has to be the last, each type of
		element can be set in any order in the file. */

		/* Except for the map, each type of information from an element can be separated
		by one or more space(s). */

		/* Each element (except the map) firsts information is the type identifier (composed by one 
		or two character(s)), followed by all specific informations for each
		object in a strict order
			->North Texture:
			"NO ./path_to_texture 

			->Floor color
			"F 220,100,0"
*/

static int	parse_configs(t_data *data, int *fd)
{
	char	*tmp;
	int		i;
	
	tmp = get_next_line(*fd);
	while (tmp)
	{
		i = 0;
		while (tmp[i] == ' ')
			i++;
		if (tmp[i] == '\n')
		{}
		else if (tmp[i] == 'N' || tmp[i] == 'S' || tmp[i] == 'W' || tmp[i] == 'E')
			ft_printf("Texture:\n%s\n", tmp);
		else if (tmp[i] == 'F' || tmp[i] == 'C')
			ft_printf("Color:\n%s\n", tmp);
		else
		{
			ft_printf("MAP BEGINS\n");
			free (tmp);
			return (1);
		}
		free(tmp);
		tmp = get_next_line(*fd);
	}
	return (0);
}

/* The map must be parsed as it looks in the file. Spaces are a valid part of the
map and are up to you to handle. You must be able to parse any kind of map,
as long as it respects the rules of the map.*/

//Only 1, 0, W, S, N, E on map
	
//map surronded by walls

/* If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice.*/
static int	parse_map(t_data *data, int *fd)
{

	return (1);
}

int	parse_map_file(t_data *data)
{
	int		fd;
	char	*map_name;
	int		ret;

	map_name = ft_strjoin("./src/maps/", data->map_name);
	fd = open (map_name, O_RDONLY);
	if (fd < 0)
		return (map_error());
	if (!parse_configs(data, &fd))
		return (map_error());
	if (!parse_map(data, &fd))
		return (map_error());
	return (1);
}