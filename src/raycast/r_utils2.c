/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:31:44 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/25 20:09:11 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	set_parameters3(t_data *data, t_ray *r)
{
	r->dof = 0;
	r->disV = 1000000;
	r->vx = data->player_x;
	r->vy = data->player_y;
	r->nTan = -tan (r->r_angle);
}

void	lking_l(t_data *data, t_ray *r)
{
	r->ray_x = (((int)data->player_x / data->size_y) * data->size_y) - 0.0001;
	r->ray_y = (data->player_x - r->ray_x) * r->nTan + data->player_y;
	r->rx_offset = -data->size_y;
	r->ry_offset = -r->rx_offset * r->nTan;
}

void	lking_r(t_data *data, t_ray *r)
{
	r->ray_x = (((int)data->player_x / data->size_y) * data->size_y) \
		+ data->size_y;
	r->ray_y = (data->player_x - r->ray_x) * r->nTan + data->player_y;
	r->rx_offset = data->size_y;
	r->ry_offset = -r->rx_offset * r->nTan;
}

void	while_no_wallv(t_data *data, t_ray *r)
{
	r->mx = (int)(r->ray_x) / data->size_y;
	r->my = (int)(r->ray_y) / data->size_y;
	r->mp = r->my * data->map_size[0] + r->mx;
	if (r->mp > 0 && r->mp < (data->map_size[0] * data->map_size[1]) \
		&& data->map_lined[r->mp] == '1')
	{
		r->vy = r->ray_y;
		r->vx = r->ray_x;
		r->disV = dist(data, r->vx, r->vy);
		r->dof = 8;
	}
	else
	{
			r->ray_x += r->rx_offset;
			r->ray_y += r->ry_offset;
			r->dof += 1;
	}
}

void	att_dist(t_ray *r)
{
	if (r->disV < r->disH)
	{
		r->ray_x = r->vx;
		r->ray_y = r->vy;
		r->disT = r->disV;
		r->color = 0x00FE00;
	}
	if (r->disH < r->disV)
	{
		r->ray_x = r->hx;
		r->ray_y = r->hy;
		r->disT = r->disH;
		r->color = 0x00FF00;
	}
}
