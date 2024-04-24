/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 1max_view:1max_view:09 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/24 15:00:41 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	check_horizon(t_data *data, t_ray *r)
{
	if (r->r_angle > PI)
		lking_up(data, r);
	if (r->r_angle < PI)
		lking_down(data, r);
	if (r->r_angle == PI || r->r_angle == 0)
	{
		r->ray_y = data->player_y;
		r->ray_x = data->player_x;
		r->dof = 8;
	}
}

void	check_vertical(t_data *data, t_ray *r)
{
	if (r->r_angle > P2 && r->r_angle < P3)
		lking_l(data, r);
	if (r->r_angle < P2 || r->r_angle > P3)
		lking_r(data, r);
	if (r->r_angle == PI || r->r_angle == 0)
	{
		r->ray_y = data->player_y;
		r->ray_x = data->player_x;
		r->dof = 8;
	}
}

/* void	drawrays3d(t_data *data)
{
	t_ray	r;

	data->r = &r;
	set_parameters(data, &r);
	while (r.ray < 60)
	{
		set_parameters2(data, &r);
		check_horizon(data, &r);
		while (r.dof < max_view)
			while_no_wallh(data, &r);
		set_parameters3(data, &r);
		while (r.dof < max_view)
			while_no_wallv(data, &r);
		att_dist(data, &r);
		draw3d(data, &r);
		r.ray++;
	}
} */

void	drawrays3d(t_data *data)
{
	int r, mx, my, mp, dof, hx, hy, vx, vy;
	double rx, ry, ra, xo, yo, disH, disV, disT;
	int	max_view;

	if (data->map_size[0] > data->map_size[1])
		max_view = data->map_size[0];
	else
		max_view = data->map_size[1];
	ra = data->p_angle-DR*30;
	if (ra < 0)
		ra += 2*PI;
	if (ra > 2*PI)
		ra -= 2*PI;
	for (r = 0; r < 60; r++)
	{
		//Horizontal
		dof = 0;
		disH = 1000000;
		hx = data->player_x;
		hy = data->player_y;
		double aTan = -1/tan(ra);
		if (ra > PI) // up
		{
			ry = (((data->player_y)/data->cube_size)*data->cube_size) - 0.0001;
			rx = (data->player_y - ry) * aTan + data->player_x;
			yo = -data->cube_size;
			xo = -yo * aTan;
		}
		if (ra < PI) // down
		{
			ry = (((data->player_y)/data->cube_size)*data->cube_size) + data->cube_size;
			rx = (data->player_y - ry) * aTan + data->player_x;
			yo = data->cube_size;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = data->player_x;
			ry = data->player_y;
			dof = max_view;
		}
		while (dof < max_view)
		{
			mx = (int) rx / data->cube_size;
			my = (int) ry / data->cube_size;
			mp = my * data->map_size[0] + mx;
			if (mp > 0 && mp < data->map_size[0] * data->map_size[1] && data->map_lined[mp] == '1')
			{
				hx = rx;
				hy = ry;
				disH = dist(data, hx, hy, ra);
				dof = max_view;
			/* ft_printf("Getting wall at: %d:%d\nFrom map[%d] = %c\n", mx, my, mp, data->map_lined[mp]);*/
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		//Vertical
		dof = 0;
		disV = 1000000;
		vx = data->player_x;
		vy = data->player_y;
		double nTan = -tan(ra);
		if (ra > P2 && ra < P3) // left
		{
			rx = (((int)data->player_x/data->cube_size)*data->cube_size) - 0.0001;
			ry = (data->player_x - rx) * nTan+data->player_y;
			xo = -data->cube_size;
			yo = -xo * nTan;
		}
		if (ra < P2 || ra > P3) // right
		{
			rx = (((int)data->player_x/data->cube_size)*data->cube_size) + data->cube_size;
			ry = (data->player_x - rx) * nTan+data->player_y;
			xo = data->cube_size;
			yo = -xo * nTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = data->player_x;
			ry = data->player_y;
			dof = max_view;
		}
		while (dof < max_view)
		{
			mx = (int) rx / data->cube_size;
			my = (int) ry / data->cube_size;
			mp = my * data->map_size[0] + mx;
			if (mp > 0 && mp < data->map_size[0] * data->map_size[1] && data->map_lined[mp] == '1')
			{
				vx = rx;
				vy = ry;
				disV = dist(data, vx, vy, ra);
				dof = max_view;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		int color;
		if (disV < disH)
		{
			rx = vx;
			ry = vy;
			disT = disV;
			color = 0x008000;
		}
		else
		{
			rx = hx;
			ry = hy;
			disT = disH;
			color = 0x006400;
		}
		//draw_quadrilaters(rx-1, ry-1, 3, 3, data, color);
		ra += DR;
		if (ra < 0)
			ra += 2*PI;
		if (ra > 2*PI)
			ra -= 2*PI;
		//DRAW 3D
		double ca = data->p_angle - ra;
		if (ca < 0)
			ca += 2*PI;
		if (ca > 2*PI)
			ca -= 2*PI;
		disT *= cos(ca);
		double lineH = (data->cube_size * 320)/disT;
		if (lineH > 500)
			lineH  = 500;
		double lineO = 250 - lineH/2;
		int	ray_widht = (data->max_x/2) / 60;
		draw_quadrilaters(((r + 1) * ray_widht) + (data->max_x/2) + 30, (int)lineO, ray_widht + 1, (int)lineH, data, color);
		refresh(data);
	}
}