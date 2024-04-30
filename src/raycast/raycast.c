/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:17:54 by r-afonso          #+#    #+#             */
/*   Updated: 2024/04/30 15:40:31 by r-afonso         ###   ########.fr       */
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
	data->ray.ra = data->p_angle - DR * 30;
	if (data->ray.ra < 0)
		data->ray.ra += 2 * PI;
	if (data->ray.ra > 2 * PI)
		data->ray.ra -= 2 * PI;
}

static void	set_ray_in_loop(t_data *data)
{
	data->ray.dof = 0;
	data->ray.disH = 1000000;
	data->ray.hx = data->player_x;
	data->ray.hy = data->player_y;
	data->ray.aTan = -1 / tan(data->ray.ra);
}

static void	check_direction_ray(t_data *data)
{
	if (data->ray.ra > PI)
	{
		data->ray.ry = (((data->player_y) / data->cube_size) * data->cube_size)
			- 0.0001;
		data->ray.rx = (data->player_y - data->ray.ry) * data->ray.aTan
			+ data->player_x;
		data->ray.yo = -data->cube_size;
		data->ray.xo = -data->ray.yo * data->ray.aTan;
	}
	if (data->ray.ra < PI)
	{
		data->ray.ry = (((data->player_y) / data->cube_size) * data->cube_size)
			+ data->cube_size;
		data->ray.rx = (data->player_y - data->ray.ry) * data->ray.aTan
			+ data->player_x;
		data->ray.yo = data->cube_size;
		data->ray.xo = -data->ray.yo * data->ray.aTan;
	}
	if (data->ray.ra == 0 || data->ray.ra == PI)
	{
		data->ray.rx = data->player_x;
		data->ray.ry = data->player_y;
		data->ray.dof = data->ray.max_view;
	}
}

static void	check_horinzotal_ray_with_walls(t_data *data)
{
	while (data->ray.dof < data->ray.max_view)
	{
		data->ray.mx = (int)data->ray.rx / data->cube_size;
		data->ray.my = (int)data->ray.ry / data->cube_size;
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
	data->ray.dof = 0;
	data->ray.disV = 1000000;
	data->ray.vx = data->player_x;
	data->ray.vy = data->player_y;
	data->ray.nTan = -tan(data->ray.ra);
}

void	drawrays3d(t_data *data)
{
	set_params_ray(data);
	while (data->ray.r < 60)
	{
		set_ray_in_loop(data);
		check_direction_ray(data);
		check_horinzotal_ray_with_walls(data);
		drawrays3d_second(data);
	}
}
