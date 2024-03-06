/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:12:34 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/03/06 19:06:18 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	drawRays3D (t_data *data)
{
	data->r_angle = data->p_angle;
	data->ray = 0;
	while (data->ray < 1)
	{
		//CHECK HORIZONTAL LINES
		data->dof = 0;
		float aTan = -1 / tan (data->r_angle);
		if (data->r_angle > PI) //looking up
		{
			data->ray_y = (((int)data->player_y >> 6)<< 6) - 0.0001;
			data->ray_x = (data->player_y - data->ray_y) * aTan+data->player_x;
			data->ry_offset = - 64;
			data->rx_offset = - data->ry_offset*aTan;
			dda (data->player_x, data->ray_x, data->player_y, data->ray_y, 0x00ff00, data);
		}
		if (data->r_angle < PI) //looking down
		{
			data->ray_y = (((int)data->player_y >> 6)<< 6) + 64;
			data->ray_x = (data->player_y - data->ray_y) * aTan+data->player_x;
			data->ry_offset = 64;
			data->rx_offset = - data->ry_offset*aTan;
			dda (data->player_x, data->ray_x, data->player_y, data->ray_y, 0x00ff00, data);
		}
		if (data->r_angle == PI || data->r_angle  == 0) //looking horizontally
		{
			data->ray_y = data->player_y;
			data->ray_x = data->player_x;
			data->dof = 8;
			dda (data->player_x, data->ray_x, data->player_y, data->ray_y, 0x00ff00, data);
		}
		while (data->dof < 8)
		{
			data->mx = (int)(data->ray_x)>>6;
			data->my = (int)(data->ray_y)>>6;
			data->mp = data->my * data->map_size[0] + data->mx;
			if (data->mp < (data->map_size[0] * data->map_size[1]) && data->map[data->mp] == '1')
			{
				data->dof = 8;//hit a wall
			}
			else //next line
			{
					data->ray_x += data->rx_offset;
					data->ray_y += data->ry_offset;
					data->dof += 1; 
			}
		}
		data->ray++;
	}
}