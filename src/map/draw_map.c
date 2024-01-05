/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:53:15 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/01/05 15:16:31 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

/* static int	calculate_blocks(t_data *data)
{
	data->size_x = 800 / data->map_size[0];
	data->size_y = 600 / data->map_size[1];
	if (data->size_x < data->size_y)
		return(data->size_x);
	else
		return (data->size_y);
} */

void	draw_background (t_data *data)
{
	draw_quadrilaters(0, 0, 800, 300, data, 0x00CCFFFF);
	draw_quadrilaters(0, 300, 800, 300, data, 0x00999999);
	refresh(data);
}

void	draw_map(t_data *data)
{
	int	i;
	int	c;
	int	size;
	
	draw_background(data);
/* 	size = calculate_blocks(data); */
	i = 0;
	while (data->map[i])
	{
		c = data->map[i];
		if (c == '1')
		{
			draw_quadrilaters(data->initial_x, data->initial_y, data->size_x, data->size_y, data, 0x00FF0000);
			data->initial_x += data->size_x + 5;
		}
		else if (c == '0')
		{
			draw_quadrilaters(data->initial_x, data->initial_y, data->size_x, data->size_y, data, 0x00000000);
			data->initial_x += data->size_x + 5;
		}
		else if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
		{
			draw_quadrilaters(data->initial_x, data->initial_y, data->size_x, data->size_y, data, 0x0033CC00);
			data->initial_x += data->size_x + 5;
		}
		else if (c == '\n')
		{
			data->initial_x = 0;
			data->initial_y += data->size_y + 5;
		}
		i++;
	}
	refresh(data);
}