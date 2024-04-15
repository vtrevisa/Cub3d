/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:43:27 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/15 15:38:22 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static unsigned long	ft_rgb_to_hex(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

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

static int	load_textures(t_data *data, char *str, char dir)
{
	int	i;

	if (dir == 'N')
		i = 0;
	if (dir == 'S')
		i = 1;
	if (dir == 'E')
		i = 2;
	if (dir == 'W')
		i = 3;
	data->textures[i] = ft_strdup(str);
	if (!data->textures[i])
		return (0);
	return (1);
}

static int	load_color_cf(t_data *data, char *str, char place)
{
	t_col	c;
	int		i;

	i = 0;
	c.col = malloc (sizeof (char *) * 4);
	while(str[i])
	{
		while (str[i] < '0' || str[i] > '9')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			c.col = ft_split(str + i, ',');
		}
		break ;
	}
	c.r = ft_atoi(c.col[0]);
	c.g = ft_atoi(c.col[1]);
	c.b = ft_atoi(c.col[2]);
	if (place == 'C')
		data->color_c = ft_rgb_to_hex(c.r, c.g, c.b);
	if (place == 'F')
		data->color_f = ft_rgb_to_hex(c.r, c.g, c.b);
}

int	config_loader(t_data *data, int *fd, char **map)
{
	char	*tmp;
	int		i;
	int		t;
	int		c;

	t = 0;
	c = 0;
	tmp = get_next_line(*fd);
	while (tmp)
	{
		i = 0;
		while (tmp[i] == ' ')
			i++;
		if (tmp[i] == '\n')
		{}
		else if ((tmp[i] == 'N' || tmp[i] == 'S' || tmp[i] == 'W' || tmp[i] == 'E') && (++t) <= 4)
			load_textures(data, tmp, tmp[i]);
		else if ((tmp[i] == 'F' || tmp[i] == 'C') && (++c) <= 2)
			load_color_cf(data, tmp, tmp[i]);
		else
		{
			*map = ft_strdup(tmp);
			free (tmp);
			return (1);
		}
		free(tmp);
		tmp = get_next_line(*fd);
	}
}

int	map_loader(t_data *data, int *fd, char **map)
{
	char	*tmp;

	tmp = *map;
	data->blocks_nbr = get_quantity_blocks \
		(&data->map_size[0], & data->map_size[1], ft_strjoin("./src/maps/", data->map_name));
	data->map = malloc(sizeof(char) * data->blocks_nbr);
	ft_bzero(data->map, data->blocks_nbr);
	while (tmp)
	{
		data->map = ft_strjoin(data->map, tmp);
		free(tmp);
		tmp = get_next_line(*fd);
	}

	return (1);
}

int	config_file_loader(t_data *data)
{
	int		fd;
	char	*map_name;
	int		ret;
	char	*map;

	map_name = ft_strjoin("./src/maps/", data->map_name);
	fd = open (map_name, O_RDONLY);
	free (map_name);
	if (fd < 0)
		return (map_error());
	if (!config_loader(data, &fd, &map))
		return (map_error());
	if (!map_loader(data, &fd, &map))
		return (map_error());
	data->map_lined = ft_split(data->map, '\n');
	return (1);
}