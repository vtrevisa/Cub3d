/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:17:54 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/09 23:33:34 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	set_params_ray(t_data *data)
{
	data->ray.r = 0;
	if (data->map_size[0] > data->map_size[1])
		data->ray.max_view = data->map_size[0];
	else
		data->ray.max_view = data->map_size[1];
	data->ray.ra = data->p_angle - DR * 33;
	if (data->ray.ra < 0)
		data->ray.ra += 2 * PI;
	if (data->ray.ra > 2 * PI)
		data->ray.ra -= 2 * PI;
}

static void	check_direction_ray(t_data *data)
{
	if (data->ray.ra == 0 || data->ray.ra == PI)
	{
		data->ray.rx = data->player_x;
		data->ray.ry = data->player_y;
		data->ray.dof = data->ray.max_view;
	}
	else
	{
		data->n_s = (data->ray.ra > PI);
		data->ray.ry = ((int)(data->player_y / data->cube_size)
				* data->cube_size) + (data->n_s ? -0.0001 : data->cube_size);
		data->ray.rx = (data->player_y - data->ray.ry) * data->ray.aTan
			+ data->player_x;
		data->ray.yo = (data->n_s ? -data->cube_size : data->cube_size);
		data->ray.xo = -data->ray.yo * data->ray.aTan;
	}
}

static void	check_horizontal_ray_with_walls(t_data *data)
{
	while (data->ray.dof < data->ray.max_view)
	{
		data->ray.mx = clamp((int)(data->ray.rx / data->cube_size), 0,
				data->map_size[0] - 1);
		data->ray.my = clamp((int)(data->ray.ry / data->cube_size), 0,
				data->map_size[1] - 1);
		data->ray.mp = data->ray.my * data->map_size[0] + data->ray.mx;
		if (data->ray.mp > 0 && data->ray.mp < data->map_size[0]
			* data->map_size[1] && data->map_lined[data->ray.mp] == '1')
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
	reset_ray(data);
}

void	drawrays3d(t_data *data)
{
	set_params_ray(data);
	while (data->ray.r < 66)
	{
		reset_ray_2(data);
		check_direction_ray(data);
		check_horizontal_ray_with_walls(data);
		drawrays3d_second(data);
	}
}
