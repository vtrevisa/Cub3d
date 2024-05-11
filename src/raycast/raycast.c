/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:17:54 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/11 19:49:28 by r-afonso         ###   ########.fr       */
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

static void	set_ray_direction(t_data *data)
{
	double	base_ry;

	base_ry = ((int)(data->player_y / data->cube_size) * data->cube_size);
	if (data->ray.ra > PI)
	{
		data->n_s = 1;
		data->ray.ry = base_ry - 0.0001;
		data->ray.yo = -data->cube_size;
	}
	else
	{
		data->n_s = 0;
		data->ray.ry = base_ry + data->cube_size;
		data->ray.yo = data->cube_size;
	}
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
		set_ray_direction(data);
		data->ray.rx = (data->player_y - data->ray.ry) * data->ray.aTan
			+ data->player_x;
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
}

void	drawrays3d(t_data *data)
{
	set_params_ray(data);
	while (data->ray.r < 66)
	{
		reset_ray(data, 1);
		check_direction_ray(data);
		check_horizontal_ray_with_walls(data);
		reset_ray(data, 0);
		if (data->ray.ra == 0 || data->ray.ra == PI)
		{
			data->ray.rx = data->player_x;
			data->ray.ry = data->player_y;
			data->ray.dof = data->ray.max_view;
		}
		else
			check_vertical_ray_is_true(data);
		drawrays3d_second(data);
	}
}
