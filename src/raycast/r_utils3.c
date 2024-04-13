/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:00:33 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/11 20:52:13 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw3d(t_data *data, t_ray *r)
{
	r->ca = (data->p_angle - r->r_angle);
	if (r->ca < 0)
		r->ca += 2 * PI;
	if (r->ca > 2 * PI)
		r->ca -= 2 * PI;
	r->disT *= cos(r->ca);
	r->lineH = (data->size_x * data->max_y) / r->disT;
	if (r->lineH > 600)
		r->lineH = 600;
	r->lineO = (data->max_y / 2) - r->lineH / 2;
	r->ini_x = ((r->ray + 1) * 4) + data->max_y;
	r->ini_y = (int)r->lineO;
	r->size_x = 4;
	r->size_y = (int)r->lineH;
	draw_3d_quadrilaters(r, data);
	// refresh(data);
	r->r_angle += DR;
	if (r->r_angle < 0)
		r->r_angle += 2 * PI;
	if (r->r_angle > 2 * PI)
		r->r_angle -= 2 * PI;
}

void	while_no_wallh(t_data *data, t_ray *r)
{
	r->mx = (int)(r->ray_x) / data->size_y;
	r->my = (int)(r->ray_y) / data->size_y;
	r->mp = r->my * data->map_size[0] + r->mx;
	if (r->mp > 0 && r->mp < (data->map_size[0] * data->map_size[1]) \
		&& data->map_lined[r->mp] == '1')
	{
		r->hy = r->ray_y;
		r->hx = r->ray_x;
		r->disH = dist(data, r->hx, r->hy);
		r->dof = 8;
	}
	else
	{
			r->ray_x += r->rx_offset;
			r->ray_y += r->ry_offset;
			r->dof += 1;
	}
}
