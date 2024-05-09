/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:53:15 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/08 21:38:25 by r-afonso         ###   ########.fr       */
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

void	draw_after_test(t_data *data, int *current_x, int *current_y,
		char character, int center)
{
	data->draw.initial_x = *current_x;
	data->draw.initial_y = *current_y;
	data->draw.size_x = data->size_x - 2;
	data->draw.size_y = data->size_y - 2;
	data->draw.color = (character == '1') ? 0x00FF0000 : 0x666666;
	draw_quadrilaters(data);
	if (character == 'W' || character == 'E' || character == 'N'
		|| character == 'S')
	{
		if (data->upg == 0)
		{
			data->player_x = *current_x + center;
			data->player_y = *current_y + center;
		}
		data->upg = 1;
	}
	*current_x += data->size_x;
}

void	draw_map(t_data *data)
{
	int	index;
	int	current_x;
	int	current_y;
	int	center;

	index = 0;
	current_x = data->initial_x;
	current_y = data->initial_y;
	center = data->size_x / 2;
	while (data->map[index])
	{
		if (data->map[index] == ' ')
			current_x += data->size_x;
		else if (data->map[index] == '1' || data->map[index] == '0'
				|| data->map[index] == 'W' || data->map[index] == 'E'
				|| data->map[index] == 'N' || data->map[index] == 'S')
			draw_after_test(data, &current_x, &current_y, data->map[index],
					center);
		else if (data->map[index] == '\n')
		{
			current_x = 0;
			current_y += data->size_y;
		}
		index++;
	}
}
