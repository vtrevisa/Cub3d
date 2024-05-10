/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:06:05 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/09 23:06:20 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	process_character(char *line, int i, int *is_closed, t_data *data)
{
	char	c;

	c = line[i];
	if (c == '1')
		*is_closed = 1;
	else if (c != ' ')
		return (0);
	else
	{
		if (line[i + 1] != ' ' && line[i + 1] != '1')
		{
			if (line[i + 1] == '\0' && *is_closed == 1)
				return (1);
			return (0);
		}
		data->line_below[i] = '1';
		data->line_below[i + 1] = '1';
		if (i > 0 && line[i - 1] != ' ' && line[i - 1] != '1')
			return (0);
		if (i > 0)
			data->line_below[i - 1] = '1';
	}
	return (1);
}

int	check_first_line(char *line, t_data *data)
{
	int	i;
	int	is_closed;

	i = 0;
	is_closed = 0;
	while (line[i])
	{
		if (!process_character(line, i, &is_closed, data))
			return (map_error());
		i++;
	}
	data->line_below[i] = '\0';
	if (i > 0)
		data->line_below[i - 1] = '1';
	return (1);
}
