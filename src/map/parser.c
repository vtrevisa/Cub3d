/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:33:11 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/09 23:13:42 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	handle_one_space(char c, char *line, char *line_above, int i, int is_closed)
{
	if (c != '1' && c != ' ')
		return (-1);
	if (c == ' ')
	{
		if (line[i + 1] == '\0' && is_closed == 1)
			return (1);
		if (line[i + 1] != ' ' && line[i + 1] != '1')
			return (-1);
		if (line_above[i] != ' ' && line_above[i] != '1')
			return (-1);
		if (line_above[i + 1] != ' ' && line_above[i + 1] != '1')
			return (-1);
		if (i > 0)
		{
			if (line[i - 1] != ' ' && line[i - 1] != '1')
				return (-1);
			if (line_above[i - 1] != ' ' && line_above[i - 1] != '1')
				return (-1);
		}
	}
	return (0);
}

int	check_last_line(char *line_above, char *line, char *line_guide)
{
	int		i;
	int		is_closed;
	char	c;
	int		space_handling_result;

	i = 0;
	is_closed = 0;
	while (line[i])
	{
		c = line[i];
		if (c == '1')
			is_closed = 1;
		else if (c != ' ')
			is_closed = 0;
		if (line_guide[i] == '1' && c != ' ' && c != '1')
			return (map_error());
		space_handling_result = handle_one_space(c, line, line_above, i,
				is_closed);
		if (space_handling_result < 0)
			return (map_error());
		else if (space_handling_result == 1)
			return (1);
		i++;
	}
	return (line[i - 1] == '1' ? 1 : map_error());
}

int	process_lines(t_data *data, char *line_guide)
{
	int	y;

	y = 0;
	while (y <= data->map_size[1])
	{
		if (line_guide)
			free(line_guide);
		line_guide = ft_strdup(data->line_below);
		ft_memset(data->line_below, '0', data->map_size[0]);
		data->line_below[0] = '1';
		if ((y == 0 && check_first_line(data->map_array[0], data) < 0) ||
			(y > 0 && y < data->map_size[1] - 1
					&& check_mid_lines(data->map_array[y - 1],
						data->map_array[y], line_guide, data) < 0) ||
			(y == data->map_size[1] - 1 && check_last_line(data->map_array[y
						- 1], data->map_array[y], line_guide) < 0))
		{
			return (0);
		}
		y++;
	}
	return (1);
}

int	parse_config_file(t_data *data)
{
	char	*line_guide;

	if (data->txt_ok != 4)
		return (txt_error());
	if (data->col_ok != 2)
		return (col_error());
	data->line_below = (char *)malloc(data->map_size[0] + 1);
	ft_bzero(data->line_below, data->map_size[0] + 1);
	line_guide = (char *)malloc(data->map_size[0] + 1);
	if (!process_lines(data, line_guide))
	{
		free(data->line_below);
		free(line_guide);
		return (-1);
	}
	free(line_guide);
	free(data->line_below);
	return (data->flag ? 1 : no_player_position());
}
