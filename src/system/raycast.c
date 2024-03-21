/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:12:34 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/03/21 19:16:36 by vtrevisa         ###   ########.fr       */
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
		/* data->dof = 0;
		printf("nTan: %f\nr_angle: %f\n", tan(data->r_angle), data->r_angle);
		float aTan = -1 / tan (data->r_angle);
		if (data->r_angle > PI) //looking up
		{
			data->ray_y = ((data->player_y / data->size_y)* data->size_y) - 0.0001;
			data->ray_x = (data->player_y - data->ray_y) * aTan+data->player_x;
			data->ry_offset = - data->size_y;
			data->rx_offset = - data->ry_offset*aTan;
		}
		if (data->r_angle < PI) //looking down
		{
			data->ray_y = (((int)data->player_y / data->size_y)* data->size_y) + data->size_y;
			data->ray_x = (data->player_y - data->ray_y) * aTan+data->player_x;
			data->ry_offset = data->size_y;
			data->rx_offset = - data->ry_offset*aTan;
		}
		if (data->r_angle == PI || data->r_angle  == 0) //looking horizontally
		{
			data->ray_y = data->player_y;
			data->ray_x = data->player_x;
			data->dof = 2;
		}
		while (data->dof < 8) 
		{
			data->mx = (int)(data->ray_x)/data->size_y;
			data->my = (int)(data->ray_y)/data->size_y + 1;
			data->mp = data->my * data->map_size[0] + data->mx;
			ft_printf(RED);
			ft_printf("my:%d\n", data->my);
			printf("ray_y:%f\n", data->ray_y);
			ft_printf("size_y:%d\n", data->size_y);
			ft_printf(WHITE);
			//ft_printf("my:%d\nmx:%d\n",data->my, data->mx);
			//ft_printf("my:%d\nmx:%d\nmp search: %d = %c\n",data->my, data->mx, data->mp, data->map_lined[data->mp]);
			if (data->mp < (data->map_size[0] * data->map_size[1]) && data->map_lined[data->mp] == '1')
			{
				draw_quadrilaters(data->ray_x - 1, data->ray_y, 3, 1, data, 0x0000ff);
				data->dof = 8;//hit a wall
			}
			else //next line
			{
					draw_quadrilaters(data->ray_x - 1, data->ray_y, 3, 1, data, 0x00ff00);
					data->ray_x += data->rx_offset;
					data->ray_y += data->ry_offset;
					data->dof += 1;
			}
		} */
		//CHECK VERTICAL LINES
		data->dof = 0;
		printf("nTan: %f\nr_angle: %f\n", -tan(data->r_angle), data->r_angle);
		float nTan = -tan (data->r_angle);
		if (data->r_angle > P2 && data->r_angle < P3) //looking left
		{
			data->ray_x = (((int)data->player_x / data->size_x)* data->size_x) - 0.0001;
			data->ray_y = (data->player_x - data->ray_x) * nTan+data->player_y;
			data->rx_offset = - data->size_y;
			data->ry_offset = - data->rx_offset*nTan;
		}
		if (data->r_angle < P2 || data->r_angle > P3) //looking right
		{
			data->ray_x = (((int)data->player_x / data->size_x)* data->size_x) + data->size_x;
			data->ray_y = (data->player_x - data->ray_x) * nTan+data->player_y;
			ft_printf(BLUE);
			printf("data->player_x: %d\n", data->player_x);
			printf("ray_y: %f\n", data->ray_y);
			printf("ray_x: %f\n", data->ray_x);
			printf("nTan: %f\n", nTan);
			printf("data->player_y: %d\n", data->player_y);
			ft_printf(WHITE);
			data->rx_offset = data->size_y;
			data->ry_offset = - data->rx_offset*nTan;
		}
		if (data->r_angle == PI || data->r_angle  == 0) //looking vertically
		{
			data->ray_y = data->player_y;
			data->ray_x = data->player_x;
			data->dof = 2;
		}
		while (data->dof < 8) 
		{
			data->mx = (int)(data->ray_x)/data->size_y;
			data->my = (int)(data->ray_y)/data->size_y + 1;
			data->mp = data->my * data->map_size[0] + data->mx;
 			ft_printf(RED);
			ft_printf("my:%d\n", data->my);
			printf("ray_y:%f\n", data->ray_y);
			ft_printf("size_y:%d\n", data->size_y);
			ft_printf(WHITE);
			if (data->mp < (data->map_size[0] * data->map_size[1]) && data->map_lined[data->mp] == '1')
			{
				draw_quadrilaters(data->ray_x - 1, data->ray_y, 3, 1, data, 0x0000ff);
				data->dof = 8;//hit a wall
			}
			else //next line
			{
				write (1, "ok4\n", 4);
					draw_quadrilaters(data->ray_x - 1, data->ray_y, 3, 1, data, 0x00ff00);
					data->ray_x += data->rx_offset;
					data->ray_y += data->ry_offset;
					data->dof += 1;
			}
		}
		data->ray++;
	}
}