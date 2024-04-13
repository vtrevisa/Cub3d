/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:47:34 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/11 20:49:25 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

double	dist(t_data *data, double bx, double by)
{
	int	ax;
	int	ay;

	ax = data->player_x;
	ay = data->player_y;
	return (sqrt ((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	set_parameters(t_data *data, t_ray *r)
{
	r->r_angle = data->p_angle - DR * 30;
	if (r->r_angle < 0)
		r->r_angle += 2 * PI;
	if (r->r_angle > 2 * PI)
		r->r_angle -= 2 * PI;
	r->ray = 0;
}

void	set_parameters2(t_data *data, t_ray *r)
{
	r->dof = 0;
	r->disH = 1000000;
	r->hx = data->player_x;
	r->hy = data->player_y;
	r->aTan = -1 / tan (r->r_angle);
}

void	lking_up(t_data *data, t_ray *r)
{
	r->ray_y = (((int)data->player_y / data->size_y) * data->size_y) - 0.0001;
	r->ray_x = (data->player_y - r->ray_y) * r->aTan + data->player_x;
	r->ry_offset = -data->size_y;
	r->rx_offset = -r->ry_offset * r->aTan;
}

void	lking_down(t_data *data, t_ray *r)
{
	r->ray_y = (((int)data->player_y / data->size_y) * data->size_y) + \
		data->size_y;
	r->ray_x = (data->player_y - r->ray_y) * r->aTan + data->player_x;
	r->ry_offset = data->size_y;
	r->rx_offset = -r->ry_offset * r->aTan;
}
