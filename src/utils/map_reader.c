/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:43:27 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/10 20:08:13 by vtrevisa         ###   ########.fr       */
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

char	*remove_line_breaks(t_data *data, char *str)
{
	char	*cleaned_string;
	int		source_index;
	int		target_index;
	int		line_char_index;

	source_index = 0;
	target_index = 0;
	line_char_index = 0;
	cleaned_string = (char *)malloc(sizeof(char) * data->max_x);
	while (str[source_index])
	{
		if (str[source_index] != '\n')
		{
			cleaned_string[target_index++] = str[source_index++];
			line_char_index++;
		}
		else
		{
			while (line_char_index < data->map_size[0])
				cleaned_string[target_index++] = ' ', line_char_index++;
			source_index++, line_char_index = 0;
		}
	}
	return (cleaned_string);
}
int	is_valid_character(char c)
{
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') ||
		(c == '1' || c == '0') ||
		(c == ' '))
		return (1);
	return (0);
}

static int	get_total_blocks_map(int *max_width, int *max_height, char *map)
{
	int	index;
	int	current_line_width;
	int	total_lines;
	int	total_blocks;

	index = 0;
	current_line_width = 0;
	total_lines = 0;
	total_blocks = 0;
	while (map[index])
	{
		if (is_valid_character(map[index]))
		{
			current_line_width++;
			total_blocks++;
		}
		else if (map[index] == '\n')
		{
			if (current_line_width > *max_width)
				*max_width = current_line_width;
			current_line_width = 0;
			total_lines++;
		}
		index++;
	}
	if (map[index] == '\0' && map[index - 1] != '\n')
	total_lines += 1;
	*max_height = total_lines;
	ft_printf("Lines: %d\n", total_lines);
	return (total_blocks);
}

static unsigned long	ft_rgb_to_hex(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int	check_texture_path(t_data *data, char *str, char face)
{
	if (face == 'N' && !data->textures[0])
		return ((data->textures[0] = ft_strdup(str)), 1);
	if (face == 'S' && !data->textures[1])
		return ((data->textures[1] = ft_strdup(str)), 2);
	if (face == 'E' && !data->textures[2])
		return ((data->textures[2] = ft_strdup(str)), 3);
	if (face == 'W' && !data->textures[3])
		return ((data->textures[3] = ft_strdup(str)), 4);
	return (-1);
}

static int	load_textures(t_data *data, char *str)
{
	int		index;
	int		result;
	char	*trimmed;

	index = 2;
	result = -1;
	if ((str[0] == 'N' && str[1] == 'O') || (str[0] == 'S' && str[1] == 'O') ||
		(str[0] == 'W' && str[1] == 'E') || (str[0] == 'E' && str[1] == 'A'))
	{
		while (str[index] == ' ')
			index++;
		trimmed = ft_strtrim(str + index, "\n");
		result = check_texture_path(data, trimmed, str[0]);
		free(trimmed);
	}
	if (result < 0)
		return (-1);
	data->txt_ok += 1;
	return (1);
}

static int	is_valid_color_string(const char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	while (str[i] == 'F' || str[i] == 'C' || str[i] == ' ')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	else
		return (0);
}

static int	extract_color_values(const char *str, int *rgb)
{
	int		i;
	char	**col;

	i = 0;
	while (str[i] == 'F' || str[i] == 'C' || str[i] == ' ')
		i++;
	col = ft_split(str + i, ',');
	if (!col)
		return (0);
	for (i = 0; i < 3; ++i)
	{
		if (!col[i])
		{
			while (--i >= 0)
				free(col[i]);
			free(col);
			return (0);
		}
		rgb[i] = ft_atoi(col[i]);
		free(col[i]);
	}
	free(col);
	return (1);
}

static int	load_color_cf(t_data *data, char *str, char place)
{
	int	rgb[3];

	if (!is_valid_color_string(str))
		return (-1);
	if (!extract_color_values(str, rgb))
		return (0);
	if (place == 'C')
		data->color_c = ft_rgb_to_hex(rgb[0], rgb[1], rgb[2]);
	else if (place == 'F')
		data->color_f = ft_rgb_to_hex(rgb[0], rgb[1], rgb[2]);
	if (data->color_c == 0)
		data->color_c = 1;
	if (data->color_f == 0)
		data->color_f = 1;
	data->col_ok++;
	return (1);
}

int	line_equal_to_nl(char *line, int index, t_data *data, char **map)
{
	if (line[index] == 'N' || line[index] == 'S' || line[index] == 'W'
		|| line[index] == 'E')
		load_textures(data, line);
	else if (line[index] == 'F' || line[index] == 'C')
		load_color_cf(data, line, line[index]);
	else
	{
		*map = ft_strdup(line);
		free(line);
		return (0) ;
	}
	return (1);
}

void	config_loader(t_data *data, int *fd, char **map)
{
	char	*line;
	int		index;

	line = get_next_line(*fd);
	while (line)
	{
		index = 0;
		while (line[index] == ' ')
			index++;
		if (line[index] != '\n')
		{
			if (!line_equal_to_nl(line, index, data, map))
				return ;
		}
		free(line);
		line = get_next_line(*fd);
	}
	free(line);
}

static void	map_loader(t_data *data, int *fd, char **map)
{
	char	*line;
	char	*newMapContent;

	line = ft_strdup(*map);
	data->map = NULL;
	while (line)
	{
		if (!data->map)
			data->map = ft_strdup(line);
		else
		{
			newMapContent = ft_strjoin(data->map, line);
			free(data->map);
			data->map = newMapContent;
		}
		free(line);
		line = get_next_line(*fd);
	}
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
											&data->map_size[1],
											data->map);
	data->map_lined = remove_line_breaks(data, data->map);
	data->map_array = fill_map_array(data);
	if (parse_config_file(data) < 0)
		return (free(map), -1);
	free(map);
	return (1);
}

/* char	*remove_line_breaks(t_data *data, char *str)
{
	char	*cleaned_string;
	int		source_index;
	int		target_index;
	int		line_char_index;

	source_index = 0;
	target_index = 0;
	line_char_index = 1;
	cleaned_string = (char *)malloc(sizeof(char) * ((data->map_size[0] * 4) * data->map_size[1]));
	cleaned_string[target_index++] = ' ';
	while (str[source_index])
	{
		if (str[source_index] != '\n')
		{
			cleaned_string[target_index++] = str[source_index++];
			line_char_index++;
		}
		else
		{
			while (line_char_index < data->map_size[0] + 1)
			{
				cleaned_string[target_index++] = ' ';
				line_char_index++;
			}
			source_index++;
			line_char_index = 0;
		}
	}
	cleaned_string[target_index] = '\0';
	data->map_size[0] += 2;
	return (cleaned_string);
} */