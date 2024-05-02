/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:53:15 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/02 17:32:01 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_background (t_data *data)
{
	data->draw.initial_x = 0;
	data->draw.initial_y = 0;
	data->draw.size_x = data->max_x;
	data->draw.size_y = data->max_y/2;
	data->draw.color = data->color_c;
	draw_quadrilaters(data);
	data->draw.initial_y = data->max_y/2;
	data->draw.color = data->color_f;
	draw_quadrilaters(data);
	refresh(data);
}

void	draw_map(t_data *data)
{
	int	i;
	int	c;
	int	i_x;
	int	i_y;
	int	center;

	center = data->size_x / 2;
	i_x = data->initial_x;
	i_y = data->initial_y;
	draw_background(data);
	i = 0;
	while (data->map[i])
	{
		c = data->map[i];
		if (c == ' ')
		{i_x += data->size_x;}
		else if (c == '1')
		{
			data->draw.initial_x = i_x;
			data->draw.initial_y = i_y;
			data->draw.size_x = data->size_x - 2;
			data->draw.size_y = data->size_y - 2;
			data->draw.color = 0x00FF0000;
			draw_quadrilaters(data);
			i_x += data->size_x;
		}
		else if (c == '0')
		{
			data->draw.initial_x = i_x;
			data->draw.initial_y = i_y;
			data->draw.size_x = data->size_x - 2;
			data->draw.size_y = data->size_y - 2;
			data->draw.color = 0x666666;
			draw_quadrilaters(data);
			i_x += data->size_x;
		}
		else if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
		{
			data->draw.initial_x = i_x;
			data->draw.initial_y = i_y;
			data->draw.size_x = data->size_x - 2;
			data->draw.size_y = data->size_y - 2;
			data->draw.color = 0x00000000;
			draw_quadrilaters(data);
			if (data->upg == 0)
			{
				data->player_x = i_x + center;
				data->player_y = i_y + center;
			}
			i_x += data->size_x;
			data->upg = 1;
		}
		else if (c == '\n')
		{
			i_x = 0;
			i_y += data->size_y;
		}
		i++;
	}
	refresh(data);
}
