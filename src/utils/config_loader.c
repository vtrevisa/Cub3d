/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:40:40 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/11 18:17:24 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
	i = -1;
	while (i++, i < 3)
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
		return (0);
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
