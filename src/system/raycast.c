/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:12:34 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/03/19 15:00:51 by vtrevisa         ###   ########.fr       */
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
			data->ray_y = (((int)data->player_y / data->size_y)* data->size_y) - 0.0001;
			data->ray_x = (data->player_y - data->ray_y) * aTan+data->player_x;
			data->ry_offset = - data->size_y;
			data->rx_offset = - data->ry_offset*aTan;
			/*dda (data->player_x, data->ray_x, data->player_y, data->ray_y, 0x00ff00, data);
			ft_printf(GREEN);
			ft_printf("looking up ray draw\n");
			ft_printf(WHITE); */
		}
		if (data->r_angle < PI) //looking down
		{
			data->ray_y = (((int)data->player_y / data->size_y)* data->size_y) + data->size_y;
			data->ray_x = (data->player_y - data->ray_y) * aTan+data->player_x;
			data->ry_offset = data->size_y;
			data->rx_offset = - data->ry_offset*aTan;
		/*	dda (data->player_x, data->ray_x, data->player_y, data->ray_y, 0x00ff00, data);
			ft_printf(GREEN);
			ft_printf("looking down ray draw\n");
			ft_printf(WHITE); */
		}
		if (data->r_angle == PI || data->r_angle  == 0) //looking horizontally
		{
			data->ray_y = data->player_y;
			data->ray_x = data->player_x;
			data->dof = 2;
/* 			dda (data->player_x, data->ray_x, data->player_y, data->ray_y, 0x00ff00, data);
			ft_printf(GREEN);
			ft_printf("looking horizon ray draw\n");
			ft_printf(WHITE); */
		}
		while (data->dof < 2) 
		{
			data->mx = (int)(data->ray_x)/data->size_y;
			data->my = (int)(data->ray_y)/data->size_y + 1;
			data->mp = data->my * data->map_size[0] + data->mx;
			ft_printf("my:%d\nmx:%d\nmp search: %d = %c\n",data->my, data->mx, data->mp, data->map_lined[data->mp]);
			if (data->mp < (data->map_size[0] * data->map_size[1]) && data->map_lined[data->mp] == '1')
			{
				draw_quadrilaters(data->ray_x - 1, data->ray_y, 3, 1, data, 0x0000ff);
				data->dof = 2;//hit a wall
			}
			else //next line
			{
					draw_quadrilaters(data->ray_x - 1, data->ray_y, 3, 1, data, 0x00ff00);
					data->ray_x += data->rx_offset;
					data->ray_y += data->ry_offset;
					data->dof += 1;
			}
		}
		data->ray++;
	}
}