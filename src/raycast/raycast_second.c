/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_second.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:17:54 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/09 23:21:31 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	check_vertical_ray_is_true(t_data *data)
{
    if (data->ray.ra == 0 || data->ray.ra == PI)
    {
        data->ray.rx = data->player_x;
        data->ray.ry = data->player_y;
        data->ray.dof = data->ray.max_view;
    }
    else
    {
        if (data->ray.ra > P2 && data->ray.ra < P3)
        {
            data->e_w = 0;
            data->ray.rx = ((int)(data->player_x / data->cube_size) * data->cube_size) - 0.0001;
            data->ray.xo = -data->cube_size;
        }
        else
        {
            data->e_w = 1;
            data->ray.rx = ((int)(data->player_x / data->cube_size) * data->cube_size) + data->cube_size;
            data->ray.xo = data->cube_size;
        }
        data->ray.ry = (data->player_x - data->ray.rx) * data->ray.nTan + data->player_y;
        data->ray.yo = -data->ray.xo * data->ray.nTan;
    }
}

static void check_vertical_ray_with_walls(t_data *data)
{
    while (data->ray.dof < data->ray.max_view)
    {
        data->ray.mx = (int)data->ray.rx / data->cube_size;
        data->ray.mx = clamp(data->ray.mx, 0, data->map_size[0] - 1);
        data->ray.my = (int)data->ray.ry / data->cube_size;
        data->ray.my = clamp(data->ray.my, 0, data->map_size[1] - 1);

        data->ray.mp = data->ray.my * data->map_size[0] + data->ray.mx;
        if (data->ray.mp > 0 && data->ray.mp < data->map_size[0] * data->map_size[1] && data->map_lined[data->ray.mp] == '1')
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
            data->ray.dof++;
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
		if (data->e_w == 0)
			data->ray.color = get_color(data->textures[0]);
		if (data->e_w == 1)
			data->ray.color = get_color(data->textures[1]);
	}
	else
	{
		data->ray.rx = data->ray.hx;
		data->ray.ry = data->ray.hy;
		data->ray.disT = data->ray.disH;
		if (data->n_s == 0)
			data->ray.color = get_color(data->textures[2]);
		if (data->n_s == 1)
			data->ray.color = get_color(data->textures[3]);
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
	data->ray.lineH = (data->cube_size * data->max_y) / data->ray.disT;
	if (data->ray.lineH > data->max_y)
		data->ray.lineH = data->max_y;
	data->ray.lineO = (int)data->max_y/2 - data->ray.lineH / 2;
	data->ray.ray_width = data->max_x / 66;
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
	if (data->draw.size_y > 85)
		draw_quadrilaters(data);
	draw_map(data);
	draw_player(data);
	refresh(data);
	data->ray.r++;
}
