/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:53:15 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/11 15:28:43 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_background(t_data *data)
{
	data->draw.initial_x = 0;
	data->draw.initial_y = 0;
	data->draw.size_x = data->max_x;
	data->draw.size_y = data->max_y / 2;
	data->draw.color = data->color_c;
	draw_quadrilaters(data);
	data->draw.initial_y = data->max_y / 2;
	data->draw.color = data->color_f;
	draw_quadrilaters(data);
}

void	draw_after_test(t_data *data, int *current_x, int *current_y, char c)
{
	data->draw.initial_x = *current_x + 2;
	data->draw.initial_y = *current_y + 2;
	data->draw.size_x = data->cube_size - 2;
	data->draw.size_y = data->cube_size - 2;
	if (c == '1')
		data->draw.color = 0x00FF0000;
	else
		data->draw.color = 0x666666;
	draw_quadrilaters(data);
	if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
	{
		if (data->upg == 0)
		{
			data->player_x = *current_x + 2;
			data->player_y = *current_y + 2;
		}
		data->upg = 1;
	}
	*current_x += data->cube_size;
}

static int	is_valid_character(char c)
{
	return (c == '1' || c == '0' || c == 'W' || c == 'E' || c == 'N'
		|| c == 'S');
}

void	draw_map(t_data *data)
{
	int	index;
	int	current_x;
	int	current_y;

	index = 0;
	current_x = data->initial_x;
	current_y = data->initial_y;
	while (data->map[index])
	{
		if (data->map[index] == ' ')
			current_x += data->cube_size;
		else if (is_valid_character(data->map[index]))
		{
			draw_after_test(data, &current_x, &current_y, data->map[index]);
		}
		else if (data->map[index] == '\n')
		{
			current_x = data->initial_x;
			current_y += data->cube_size;
		}
		index++;
	}
}
