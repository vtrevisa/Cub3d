/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:33:11 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/01 18:02:08 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_first_line(char *line, t_data *data)
{
	int		i;
	char	c;

	i = 0;
	while (line[i])
	{
		c = line[i];
		if (c != '1' && c != ' ')
			return (0);
		if (c == ' ')
		{
			if (line [i + 1] != ' ' && line[i + 1] != '1')
			{
				if (line[i + 1] == '\0')
					return (1);
				ft_printf("error1 at line[%d]", i);
				return (0);
			}
			data->line_below[i] = '1';
			data->line_below[i + 1] = '1';
			if (i > 0)
			{
				if (line [i - 1] != ' ' && line [i - 1] != '1')
				{
					ft_printf("error2 at line[%d]", i);
					return (0);
				}
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
			{
				ft_printf("erro17 at line[%d]", i);
				return (0);
			}
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
			{
				ft_printf("erro16 at line[%d]", i);
				return (0);
			}
			else
				data->flag = 1;
		}
		if (c == ' ')
		{
			if (line[i + 1] == '\0' && is_closed == 1)
			{ft_printf("%s\n", data->line_below);	return (1);}
			if (line [i + 1] != ' ' && line[i + 1] != '1')
			{
				ft_printf("erro3 at line[%d]", i);
				return (0);
			}
			if (line_above[i] != ' ' && line_above[i] != '1')
			{
				ft_printf("error4 above line[%d]", i);
				return (0);
			}
			if (line_above[i + 1] != ' ' && line_above[i + 1] != '1')
			{
				ft_printf("error5 above line[%d]", i);
				return (0);
			}
			data->line_below[i] = '1';
			data->line_below[i + 1] = '1';
			if (i > 0)
			{
				if (line [i - 1] != ' ' && line [i - 1] != '1')
				{
					ft_printf("error6 at line[%d]", i);
					return (0);
				}
				if (line_above[i - 1] != ' ' && line_above[i - 1] != '1')
				{
					ft_printf("error7 above line[%d]", i);
					return (0);
				}
				data->line_below[i - 1] = '1';
			}
		}
		i++;
	}
	if (line[i - 1] != '1')
	{
		ft_printf("error8 at line[%d]", i);
		return (0);
	}
	return (1);
}

int	check_last_line(char *line_above, char *line, char *line_guide, t_data *data)
{
	int		i;
	char	c;

	i = 0;
	while (line[i])
	{
		c = line[i];
		if (line_guide[i] == '1')
		{
			if (line[i] != ' ' && line[i] != '1')
			{
				ft_printf("erro17 at line[%d]", i);
				return (0);
			}
		}
		if (c != '1' && c != ' ')
		{
			ft_printf("erro15 at line[%d]", i);
			return (0);
		}
		if (c == ' ')
		{
			if (line [i + 1] != ' ' && line[i + 1] != '1')
			{
				ft_printf("erro9 at line[%d]", i);
				return (0);
			}
			if (line_above[i] != ' ' && line_above[i] != '1')
			{
				ft_printf("error10 above line[%d]", i);
				return (0);
			}
			if (line_above[i + 1] != ' ' && line_above[i + 1] != '1')
			{
				ft_printf("error11 above line[%d]", i);
				return (0);
			}
			if (i > 0)
			{
				if (line [i - 1] != ' ' && line [i - 1] != '1')
				{
					ft_printf("error12 at line[%d]", i);
					return (0);
				}
				if (line_above[i - 1] != ' ' && line_above[i - 1] != '1')
				{
					ft_printf("error13 above line[%d]", i);
					return (0);
				}
			}
		}
		i++;
	}
	if (line[i - 1] != '1')
	{
		ft_printf("error14 at line[%d]", i);
		return (0);
	}
	ft_printf("%s\n\n", data->line_below);
	return (1);
}

int	parse_config_file(t_data *data)
{
	int	y;
	//int	x;
	//int	has_wx;
	//int	has_wy[data->map_size[0]];

	y = 0;
	//has_wx = 1;
	data->line_below = malloc (data->map_size[0]);
	if (data->txt_ok != 4)
		return (txt_fail());
	if (data->col_ok != 2)
		return (col_fail());
	show_map_array(data->map_array, data->map_size[1]);
	while (y <= data->map_size[1])
	{
		data->line_below = ft_memset(data->line_below, '0', data->map_size[0]);
		data->line_below[0] = '1';
		//CHECK FIRST LINE
		if (y == 0)
			if (!check_first_line(data->map_array[0], data))
				return (0);
		//CHECK MID LINES
		if (y > 0 && y < data->map_size[1])
			if (!check_mid_lines(data->map_array[y - 1], data->map_array[y], data->line_below, data))
				return (0);
		//CHECK LAST LINE
		if (y == data->map_size[1])
			if (!check_last_line(data->map_array[y - 1], data->map_array[y], data->line_below, data))
				return (0);
		y++;
	}
	if (!data->flag)
		return (0);
	return (1);
}