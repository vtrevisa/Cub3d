/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:43:27 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/12 00:55:56 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	**fill_map_array(t_data *data)
{
	char	**ret;
	int		x;
	int		y;
	int		i;

	i = 0;
	y = -1;
	ret = malloc(sizeof(char *) * data->map_size[1] + 1);
	while (++y < data->map_size[1])
	{
		x = -1;
		ret[y] = malloc(data->map_size[0] + 1);
		while (++x < data->map_size[0])
		{
			ret[y][x] = data->map_lined[i];
			i++;
		}
		ret[y][x] = 0;
	}
	return (ret);
}

char	*create_clean_string(int size)
{
	char	*cleaned_string;

	cleaned_string = (char *)malloc(sizeof(char) * size);
	ft_bzero(cleaned_string, size);
	return ((char *)cleaned_string);
}

char	*remove_line_breaks(t_data *data, char *str)
{
	data->remove_l.cleaned_str = create_clean_string(data->max_x);
	if (!data->remove_l.cleaned_str)
		return (NULL);
	while (str[data->remove_l.source_index] != '\0')
	{
		if (str[data->remove_l.source_index] != '\n')
		{
			data->remove_l.cleaned_str[data->remove_l.target_index]
				= str[data->remove_l.source_index];
			data->remove_l.target_index++;
			data->remove_l.line_c_index++;
		}
		else
		{
			while (data->remove_l.line_c_index < data->map_size[0])
			{
				data->remove_l.cleaned_str[data->remove_l.target_index] = ' ';
				data->remove_l.target_index++;
				data->remove_l.line_c_index++;
			}
			data->remove_l.line_c_index = 0;
		}
		data->remove_l.source_index++;
	}
	return ((char *)data->remove_l.cleaned_str);
}

static void	map_loader(t_data *data, int *fd, char **map)
{
	char	*line;
	char	*new_map_content;

	line = ft_strdup(*map);
	data->map = NULL;
	while (line)
	{
		if (!data->map)
			data->map = ft_strdup(line);
		else
		{
			new_map_content = ft_strjoin(data->map, line);
			free(data->map);
			data->map = new_map_content;
		}
		free(line);
		line = get_next_line(*fd);
	}
	new_map_content = ft_strjoin(data->map, "\n\0");
	free(data->map);
	data->map = new_map_content;
}

int	config_file_loader(t_data *data)
{
	int		fd;
	char	*map_name;
	char	*map;
	int		ret;

	ret = ft_strncmp(data->map_name + (ft_strlen(data->map_name) - 4), ".cub",
			4);
	if (ret)
		return (wrong_file_name());
	map_name = ft_strjoin("./src/maps/", data->map_name);
	fd = open(map_name, O_RDONLY);
	free(map_name);
	if (fd < 0)
		return (open_error());
	config_loader(data, &fd, &map);
	map_loader(data, &fd, &map);
	data->blocks_nbr = get_total_blocks_map(&data->map_size[0],
			&data->map_size[1], data->map);
	data->map_lined = remove_line_breaks(data, data->map);
	data->map_array = fill_map_array(data);
	if (parse_config_file(data) < 0)
		return (free(map), -1);
	free(map);
	return (1);
}
