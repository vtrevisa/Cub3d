/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:18:09 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/23 19:36:30 by vtrevisa         ###   ########.fr       */
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

	set_parameters(data, &r);
	while (r.ray < 60)
	{
		set_parameters2(data, &r);
		check_horizon(data, &r);
		while (r.dof < 8)
			while_no_wallh(data, &r);
		set_parameters3(data, &r);
		while (r.dof < 8)
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
			ry = (((data->player_y)>>6)<<6) - 0.0001;
			rx = (data->player_y - ry) * aTan + data->player_x;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI) // down
		{
			ry = (((data->player_y)>>6)<<6) + 64;
			rx = (data->player_y - ry) * aTan + data->player_x;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = data->player_x;
			ry = data->player_y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int) rx >> 6;
			my = (int) ry >> 6;
			mp = my * data->map_size[0] + mx;
			if (mp > 0 && mp < data->map_size[0] * data->map_size[1] && data->map_lined[mp] == '1')
			{
				hx = rx;
				hy = ry;
				disH = dist(data, hx, hy, ra);
				dof = 8;
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
			rx = (((int)data->player_x>>6)<<6) - 0.0001;
			ry = (data->player_x - rx) * nTan+data->player_y;
			xo = -64;
			yo = -xo * nTan;
		}
		if (ra < P2 || ra > P3) // right
		{
			rx = (((int)data->player_x>>6)<<6) + 64;
			ry = (data->player_x - rx) * nTan+data->player_y;
			xo = 64;
			yo = -xo * nTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = data->player_x;
			ry = data->player_y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int) rx >> 6;
			my = (int) ry >> 6;
			mp = my * data->map_size[0] + mx;
			if (mp > 0 && mp < data->map_size[0] * data->map_size[1] && data->map_lined[mp] == '1')
			{
				vx = rx;
				vy = ry;
				disV = dist(data, vx, vy, ra);
				dof = 8;
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
			color = 0x00FF00;
		}
		else
		{
			rx = hx;
			ry = hy;
			disT = disH;
			color = 0x0000FF;
		}
		draw_quadrilaters(rx-1, ry-1, 3, 3, data, color);
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
		if (lineH > 320)
			lineH  = 320;
		double lineO = 160 - lineH/2;
		draw_quadrilaters(((r + 1) * 4) + (data->max_y + data->max_y/3), (int)lineO, 4, (int)lineH, data, color);
	}
}