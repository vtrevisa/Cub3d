/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:07:31 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/01/05 14:40:15 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	get_quantity_blocks(int *x, int *y, char *map_name)
{
	char	*tmp;
	int		x_tmp;
	int		blocks_nbr;
	int		fd;

	fd = open(map_name, O_RDONLY);
	tmp = get_next_line(fd);
	x[0] = ft_strlen_spaceless(tmp);
	y[0] = 0;
	blocks_nbr = x[0];
	while (tmp)
	{
		free (tmp);
		tmp = get_next_line(fd);
		if (tmp)
		{
			x_tmp = ft_strlen_spaceless(tmp);
			blocks_nbr += x_tmp;
			if (x_tmp > x[0])
				x[0] = x_tmp;
		}
		y[0]++;
	}
	close (fd);
	return (blocks_nbr);
}

int	check_map(char *str)
{
	int		i;
	char	c;
	
	i = 0;
	while(str[i])
	{
		c = str[i];
		if (c == '1' || c == '0')
			i++;
		else if (c == 'N' || c == 'S')
			i++;
		else if (c == 'W' || c == 'E' || c == ' ')
			i++;
		else if (c == '\n' || c == '\0')
		{
			return (1);
		}
		else
			return (map_error());
	}
	return (0);
}

int	map_reader(t_data *data)
{
	int		fd;
	char	*tmp;
	char	*map_name;
	int	l = 1;

	map_name = ft_strjoin("./src/maps/", data->map_name);
	fd = open(map_name, O_RDONLY);
	//GET_MAP_PARAMS
	data->blocks_nbr = get_quantity_blocks(&data->map_size[0],& data->map_size[1], map_name);
	show_map_nbrs(data);
	tmp = get_next_line(fd);
	data->map = malloc(sizeof(char) * data->blocks_nbr);
	ft_bzero(data->map, data->blocks_nbr);
	while(tmp)
	{
	//LOAD_MAP
		data->map = ft_strjoin(data->map, tmp);
	//CHECK_MAP
		if (check_map(tmp) < 0)
			return (-1);
		free(tmp);
		tmp = get_next_line(fd);
	}
		map_loaded(data->map_name);
		show_map(data->map);
}