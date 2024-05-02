/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_second.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:17:54 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/02 17:32:01 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	check_vertical_ray_is_true(t_data *data)
{
	if (data->ray.ra > P2 && data->ray.ra < P3)
	{
		data->E_W = 0;
		data->ray.rx = (((int)data->player_x / data->cube_size)
				* data->cube_size) - 0.0001;
		data->ray.ry = (data->player_x - data->ray.rx) * data->ray.nTan
			+ data->player_y;
		data->ray.xo = -data->cube_size;
		data->ray.yo = -data->ray.xo * data->ray.nTan;
	}
	if (data->ray.ra < P2 || data->ray.ra > P3)
	{
		data->E_W = 1;
		data->ray.rx = (((int)data->player_x / data->cube_size)
				* data->cube_size) + data->cube_size;
		data->ray.ry = (data->player_x - data->ray.rx) * data->ray.nTan
			+ data->player_y;
		data->ray.xo = data->cube_size;
		data->ray.yo = -data->ray.xo * data->ray.nTan;
	}
	if (data->ray.ra == 0 || data->ray.ra == PI)
	{
		data->ray.rx = data->player_x;
		data->ray.ry = data->player_y;
		data->ray.dof = data->ray.max_view;
	}
}

static void	check_vertical_ray_with_walls(t_data *data)
{
	while (data->ray.dof < data->ray.max_view)
	{
		data->ray.mx = (int)data->ray.rx / data->cube_size;
		data->ray.my = (int)data->ray.ry / data->cube_size;
		data->ray.mp = data->ray.my * data->map_size[0] + data->ray.mx;
		if (data->ray.mp > 0 && data->ray.mp < data->map_size[0]
			* data->map_size[1] && data->map_lined[data->ray.mp] == '1')
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
}

static void	check_minor_distance_v_h(t_data *data)
{
	if (data->ray.disV < data->ray.disH)
	{
		data->ray.rx = data->ray.vx;
		data->ray.ry = data->ray.vy;
		data->ray.disT = data->ray.disV;
		if (data->E_W == 0)
			data->ray.color = 0x008000;
		if (data->E_W == 1)
			data->ray.color = 0xFF5A36;
	}
	else
	{
		data->ray.rx = data->ray.hx;
		data->ray.ry = data->ray.hy;
		data->ray.disT = data->ray.disH;
		if (data->N_S == 0)
			data->ray.color = 0x4B0082;
		if (data->N_S == 1)
			data->ray.color = 0x8B0000;
	}
}

static void	calc_ray_situation(t_data *data)
{
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
	data->ray.ray_width = data->max_x / 60;
}

void	drawrays3d_second(t_data *data)
{
	check_vertical_ray_is_true(data);
	check_vertical_ray_with_walls(data);
	check_minor_distance_v_h(data);
	calc_ray_situation(data);
	data->draw.initial_x = ((data->ray.r) * data->ray.ray_width);
	data->draw.initial_y = (int)data->ray.lineO;
	data->draw.size_x = data->ray.ray_width + 1;
	data->draw.size_y = (int)data->ray.lineH;
	data->draw.color = data->ray.color;
	draw_quadrilaters(data);
	refresh(data);
	data->ray.r++;
}
