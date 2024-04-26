/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:17:54 by r-afonso          #+#    #+#             */
/*   Updated: 2024/04/26 12:09:04 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	drawrays3d(t_data *data)
{
	int		max_view;
	double	aTan;
	double	nTan;
	int		color;
	double	ca;
	double	lineH;
	double	lineO;
	int		ray_widht;

	int r, mx, my, mp, dof, hx, hy, vx, vy;
	double rx, ry, ra, xo, yo, disH, disV, disT;
	if (data->map_size[0] > data->map_size[1])
		max_view = data->map_size[0];
	else
		max_view = data->map_size[1];
	ra = data->p_angle - DR * 30;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	for (r = 0; r < 60; r++)
	{
		dof = 0;
		disH = 1000000;
		hx = data->player_x;
		hy = data->player_y;
		aTan = -1 / tan(ra);
		if (ra > PI)
		{
			ry = (((data->player_y) / data->cube_size) * data->cube_size)
				- 0.0001;
			rx = (data->player_y - ry) * aTan + data->player_x;
			yo = -data->cube_size;
			xo = -yo * aTan;
		}
		if (ra < PI)
		{
			ry = (((data->player_y) / data->cube_size) * data->cube_size)
				+ data->cube_size;
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
			mx = (int)rx / data->cube_size;
			my = (int)ry / data->cube_size;
			mp = my * data->map_size[0] + mx;
			if (mp > 0 && mp < data->map_size[0] * data->map_size[1]
				&& data->map_lined[mp] == '1')
			{
				hx = rx;
				hy = ry;
				disH = dist(data, hx, hy);
				dof = max_view;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		dof = 0;
		disV = 1000000;
		vx = data->player_x;
		vy = data->player_y;
		nTan = -tan(ra);
		if (ra > P2 && ra < P3)
		{
			rx = (((int)data->player_x / data->cube_size) * data->cube_size)
				- 0.0001;
			ry = (data->player_x - rx) * nTan + data->player_y;
			xo = -data->cube_size;
			yo = -xo * nTan;
		}
		if (ra < P2 || ra > P3)
		{
			rx = (((int)data->player_x / data->cube_size) * data->cube_size)
				+ data->cube_size;
			ry = (data->player_x - rx) * nTan + data->player_y;
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
			mx = (int)rx / data->cube_size;
			my = (int)ry / data->cube_size;
			mp = my * data->map_size[0] + mx;
			if (mp > 0 && mp < data->map_size[0] * data->map_size[1]
				&& data->map_lined[mp] == '1')
			{
				vx = rx;
				vy = ry;
				disV = dist(data, vx, vy);
				dof = max_view;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
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
		ra += DR;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		ca = data->p_angle - ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		disT *= cos(ca);
		lineH = (data->cube_size * 320) / disT;
		if (lineH > 500)
			lineH = 500;
		lineO = 250 - lineH / 2;
		ray_widht = (data->max_x / 2) / 60;
		draw_quadrilaters(((r + 1) * ray_widht) + (data->max_x / 2) + 30,
							(int)lineO,
							ray_widht + 1,
							(int)lineH,
							data,
							color);
		refresh(data);
	}
}
