/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:53:15 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/23 19:09:29 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_background (t_data *data)
{
	draw_quadrilaters(0, 0, data->max_x, data->max_y, data, 0x0);
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
			draw_quadrilaters(i_x, i_y, data->size_x - 2, data->size_y - 2, data, 0x00FF0000);
			i_x += data->size_x;
		}
		else if (c == '0')
		{
			draw_quadrilaters(i_x, i_y, data->size_x - 2, data->size_y - 2, data, 0x666666);
			i_x += data->size_x;
		}
		else if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
		{
			draw_quadrilaters(i_x, i_y, data->size_x - 2, data->size_y - 2, data, 0x666666);
			if (data->upg == 0)
			{
				data->player_x = i_x + center;
				data->player_y = i_y + center;
			}
			i_x += data->size_x;
		}
		else if (c == '\n')
		{
			i_x = 0;
			i_y += data->size_y;
		}
		i++;
	}
	data->upg = 1;
	refresh(data);
}
