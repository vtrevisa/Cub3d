/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:18:09 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/10 12:01:31 by vtrevisa         ###   ########.fr       */
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

void	drawrays3d(t_data *data)
{
	t_ray	r;

	data->r = &r;
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
}
