/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:17:54 by r-afonso          #+#    #+#             */
/*   Updated: 2024/04/26 12:36:49 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	drawrays3d(t_data *data)
{
	if (data->map_size[0] > data->map_size[1])
		data->ray.max_view = data->map_size[0];
	else
		data->ray.max_view = data->map_size[1];
	data->ray.ra = data->p_angle - DR * 30;
	if (data->ray.ra < 0)
		data->ray.ra += 2 * PI;
	if (data->ray.ra > 2 * PI)
		data->ray.ra -= 2 * PI;
	for (data->ray.r = 0; data->ray.r < 60; data->ray.r++)
	{
		data->ray.dof = 0;
		data->ray.disH = 1000000;
		data->ray.hx = data->player_x;
		data->ray.hy = data->player_y;
		data->ray.aTan = -1 / tan(data->ray.ra);
		if (data->ray.ra > PI)
		{
			data->ray.ry = (((data->player_y) / data->cube_size) * data->cube_size)
				- 0.0001;
			data->ray.rx = (data->player_y - data->ray.ry) * data->ray.aTan + data->player_x;
			data->ray.yo = -data->cube_size;
			data->ray.xo = -data->ray.yo * data->ray.aTan;
		}
		if (data->ray.ra < PI)
		{
			data->ray.ry = (((data->player_y) / data->cube_size) * data->cube_size)
				+ data->cube_size;
			data->ray.rx = (data->player_y - data->ray.ry) * data->ray.aTan + data->player_x;
			data->ray.yo = data->cube_size;
			data->ray.xo = -data->ray.yo * data->ray.aTan;
		}
		if (data->ray.ra == 0 || data->ray.ra == PI)
		{
			data->ray.rx = data->player_x;
			data->ray.ry = data->player_y;
			data->ray.dof = data->ray.max_view;
		}
		while (data->ray.dof < data->ray.max_view)
		{
			data->ray.mx = (int)data->ray.rx / data->cube_size;
			data->ray.my = (int)data->ray.ry / data->cube_size;
			data->ray.mp = data->ray.my * data->map_size[0] + data->ray.mx;
			if (data->ray.mp > 0 && data->ray.mp < data->map_size[0] * data->map_size[1]
				&& data->map_lined[data->ray.mp] == '1')
			{
				data->ray.hx = data->ray.rx;
				data->ray.hy = data->ray.ry;
				data->ray.disH = dist(data, data->ray.hx, data->ray.hy);
				data->ray.dof = data->ray.max_view;
			}
			else
			{
				data->ray.rx += data->ray.xo;
				data->ray.ry += data->ray.yo;
				data->ray.dof += 1;
			}
		}
		data->ray.dof = 0;
		data->ray.disV = 1000000;
		data->ray.vx = data->player_x;
		data->ray.vy = data->player_y;
		data->ray.nTan = -tan(data->ray.ra);
		if (data->ray.ra > P2 && data->ray.ra < P3)
		{
			data->ray.rx = (((int)data->player_x / data->cube_size) * data->cube_size)
				- 0.0001;
			data->ray.ry = (data->player_x - data->ray.rx) * data->ray.nTan + data->player_y;
			data->ray.xo = -data->cube_size;
			data->ray.yo = -data->ray.xo * data->ray.nTan;
		}
		if (data->ray.ra < P2 || data->ray.ra > P3)
		{
			data->ray.rx = (((int)data->player_x / data->cube_size) * data->cube_size)
				+ data->cube_size;
			data->ray.ry = (data->player_x - data->ray.rx) * data->ray.nTan + data->player_y;
			data->ray.xo = data->cube_size;
			data->ray.yo = -data->ray.xo * data->ray.nTan;
		}
		if (data->ray.ra == 0 || data->ray.ra == PI)
		{
			data->ray.rx = data->player_x;
			data->ray.ry = data->player_y;
			data->ray.dof = data->ray.max_view;
		}
		while (data->ray.dof < data->ray.max_view)
		{
			data->ray.mx = (int)data->ray.rx / data->cube_size;
			data->ray.my = (int)data->ray.ry / data->cube_size;
			data->ray.mp = data->ray.my * data->map_size[0] + data->ray.mx;
			if (data->ray.mp > 0 && data->ray.mp < data->map_size[0] * data->map_size[1]
				&& data->map_lined[data->ray.mp] == '1')
			{
				data->ray.vx = data->ray.rx;
				data->ray.vy = data->ray.ry;
				data->ray.disV = dist(data, data->ray.vx, data->ray.vy);
				data->ray.dof = data->ray.max_view;
			}
			else
			{
				data->ray.rx += data->ray.xo;
				data->ray.ry += data->ray.yo;
				data->ray.dof += 1;
			}
		}
		if (data->ray.disV < data->ray.disH)
		{
			data->ray.rx = data->ray.vx;
			data->ray.ry = data->ray.vy;
			data->ray.disT = data->ray.disV;
			data->ray.color = 0x008000;
		}
		else
		{
			data->ray.rx = data->ray.hx;
			data->ray.ry = data->ray.hy;
			data->ray.disT = data->ray.disH;
			data->ray.color = 0x006400;
		}
		data->ray.ra += DR;
		if (data->ray.ra < 0)
			data->ray.ra += 2 * PI;
		if (data->ray.ra > 2 * PI)
			data->ray.ra -= 2 * PI;
		data->ray.ca = data->p_angle - data->ray.ra;
		if (data->ray.ca < 0)
			data->ray.ca += 2 * PI;
		if (data->ray.ca > 2 * PI)
			data->ray.ca -= 2 * PI;
		data->ray.disT *= cos(data->ray.ca);
		data->ray.lineH = (data->cube_size * 320) / data->ray.disT;
		if (data->ray.lineH > 500)
			data->ray.lineH = 500;
		data->ray.lineO = 250 - data->ray.lineH / 2;
		data->ray.ray_widht = (data->max_x / 2) / 60;
		draw_quadrilaters(((data->ray.r + 1) * data->ray.ray_widht) + (data->max_x / 2) + 30,
							(int)data->ray.lineO,
							data->ray.ray_widht + 1,
							(int)data->ray.lineH,
							data,
							data->ray.color);
		refresh(data);
	}
}
