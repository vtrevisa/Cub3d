/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:33:11 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/06 16:44:32 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_first_line(char *line, t_data *data)
{
	int		i;
	char	c;
	int		is_closed;

	i = 0;
	is_closed = 0;
	while (line[i])
	{
		c = line[i];
		if (c == '1')
			is_closed = 1;
		if (c != '1' && c != ' ')
			is_closed = 0;
		if (c != '1' && c != ' ')
			return (map_error());
		if (c == ' ')
		{
			if (line [i + 1] != ' ' && line[i + 1] != '1')
			{
				if (line[i + 1] == '\0' && is_closed == 1)
					return (1);
				return (map_error());
			}
			data->line_below[i] = '1';
			data->line_below[i + 1] = '1';
			if (i > 0)
			{
				if (line [i - 1] != ' ' && line [i - 1] != '1')
					return (map_error());
				data->line_below[i - 1] = '1';
			}
		}
		i++;
	}
	data->line_below[i - 1] = '1';
	data->line_below[i] = '\0';
	return (1);
}

int	check_mid_lines(char *line_above, char *line, char *line_guide, t_data *data)
{
	int		i;
	char	c;
	int		is_closed;

	i = 0;
	is_closed = 0;
	while (line[i])
	{
		if (line_guide[i] == '1')
		{
			if (line[i] != ' ' && line[i] != '1')
				return (map_error());
		}
		c = line[i];
		if (c == '1')
			is_closed = 1;
		if (c != '1' && c != ' ')
			is_closed = 0;
		if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
		{
			data->player_dir = c;
			if (data->flag)
				return (map_error());
			else
				data->flag = 1;
		}
		if (c == ' ')
		{
			if (line[i + 1] == '\0' && is_closed == 1)
				return (1);
			if (line [i + 1] != ' ' && line[i + 1] != '1')
				return (map_error());
			if (line_above[i] != ' ' && line_above[i] != '1')
				return (map_error());
			if (line_above[i + 1] != ' ' && line_above[i + 1] != '1')
				return (map_error());
			data->line_below[i] = '1';
			data->line_below[i + 1] = '1';
			if (i > 0)
			{
				if (line [i - 1] != ' ' && line [i - 1] != '1')
					return (map_error());
				if (line_above[i - 1] != ' ' && line_above[i - 1] != '1')
					return (map_error());
				data->line_below[i - 1] = '1';
			}
		}
		i++;
	}
	if (line[i - 1] != '1')
		return (map_error());
	return (1);
}

int	check_last_line(char *line_above, char *line, char *line_guide)
{
	int		i;
	char	c;
	int		is_closed;

	i = 0;
	is_closed = 0;
	while (line[i])
	{
		c = line[i];
		if (c == '1')
			is_closed = 1;
		if (c != '1' && c != ' ')
			is_closed = 0;
		if (line_guide[i] == '1')
		{
			if (line[i] != ' ' && line[i] != '1')
				return (map_error());
		}
		if (c != '1' && c != ' ')
			return (map_error());
		if (c == ' ')
		{
			if (line[i + 1] == '\0' && is_closed == 1)
				return (1);
			if (line [i + 1] != ' ' && line[i + 1] != '1')
				return (map_error());
			if (line_above[i] != ' ' && line_above[i] != '1')
				return (map_error());
			if (line_above[i + 1] != ' ' && line_above[i + 1] != '1')
				return (map_error());
			if (i > 0)
			{
				if (line [i - 1] != ' ' && line [i - 1] != '1')
					return (map_error());
				if (line_above[i - 1] != ' ' && line_above[i - 1] != '1')
					return (map_error());
			}
		}
		i++;
	}
	if (line[i - 1] != '1')
		return (map_error());
	return (1);
}

int	parse_config_file(t_data *data)
{
	int	y;
	char	*line_guide;

	y = 0;
	if (data->txt_ok != 4)
		return (txt_error());
	if (data->col_ok != 2)
		return (col_error());
	data->line_below = malloc (data->map_size[0] + 1);
	ft_bzero(data->line_below, data->map_size[0] + 1);
	line_guide = malloc (data->map_size[0] + 1);
	while (y <= data->map_size[1])
	{
		if (line_guide)
			free(line_guide);
		if (data->line_below)
			line_guide = ft_strdup(data->line_below);
		data->line_below = ft_memset(data->line_below, '0', data->map_size[0]);
		data->line_below[0] = '1';
		//CHECK FIRST LINE
		if (y == 0)
			if (check_first_line(data->map_array[0], data) < 0)
			{
				free (line_guide);
				free (data->line_below);
				return (-1);
			}
		//CHECK MID LINES
		if (y > 0 && y < data->map_size[1] - 1)
			if (check_mid_lines(data->map_array[y - 1], data->map_array[y], line_guide, data) < 0)
			{
				free (data->line_below);
				free (line_guide);
				return (-1);
			}
		//CHECK LAST LINE
		if (y == data->map_size[1] - 1)
			if (check_last_line(data->map_array[y - 1], data->map_array[y], line_guide) < 0)
			{
				free (data->line_below);
				free (line_guide);
				return (-1);
			}
		y++;
	}
	free (line_guide);
	free (data->line_below);
	if (!data->flag)
		return (no_player_position());
	return (1);
}