/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mid_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:11:52 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/09 23:12:54 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_numbers_letters(char *line, char *line_guide, t_data *data, int i,
		int *is_closed, char *c)
{
	if (line_guide[i] == '1')
	{
		if (line[i] != ' ' && line[i] != '1')
			return (-1);
	}
	*c = line[i];
	if (*c == '1')
		*is_closed = 1;
	if (*c != '1' && *c != ' ')
		*is_closed = 0;
	if (*c == 'W' || *c == 'E' || *c == 'N' || *c == 'S')
	{
		data->player_dir = *c;
		if (data->flag)
			return (-1);
		else
			data->flag = 1;
	}
	return (1);
}

int	count_mid_lines(char *line, char *line_above, t_data *data, int i)
{
	if (line[i + 1] != ' ' && line[i + 1] != '1')
		return (-1);
	if (line_above[i] != ' ' && line_above[i] != '1')
		return (-1);
	if (line_above[i + 1] != ' ' && line_above[i + 1] != '1')
		return (-1);
	data->line_below[i] = '1';
	data->line_below[i + 1] = '1';
	if (i > 0)
	{
		if (line[i - 1] != ' ' && line[i - 1] != '1')
			return (-1);
		if (line_above[i - 1] != ' ' && line_above[i - 1] != '1')
			return (-1);
		data->line_below[i - 1] = '1';
	}
	return (1);
}

int	check_mid_lines(char *line_above, char *line, char *line_guide,
		t_data *data)
{
	int		i;
	char	c;
	int		is_closed;

	i = 0;
	is_closed = 0;
	while (line[i])
	{
		if (check_numbers_letters(line, line_guide, data, i, &is_closed,
				&c) < 0)
			return (map_error());
		if (c == ' ')
		{
			if (line[i + 1] == '\0' && is_closed == 1)
				return (1);
			if (count_mid_lines(line, line_above, data, i) < 0)
				return (map_error());
		}
		i++;
	}
	if (line[i - 1] != '1')
		return (map_error());
	return (1);
}
