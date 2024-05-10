/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:47:34 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/09 23:31:49 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

double	dist(t_data *data, double bx, double by)
{
	int	ax;
	int	ay;

	ax = data->player_x;
	ay = data->player_y;
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

int	clamp(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

int	get_color(char *texture)
{
	if (compare_strings(texture, "texture_1") == 0)
		return (0x008000);
	else if (compare_strings(texture, "texture_2") == 0)
		return (0xFF5A36);
	else if (compare_strings(texture, "texture_3") == 0)
		return (0x4B0082);
	else
		return (0x8B0000);
}

void	reset_ray_2(t_data *data)
{
	data->ray.dof = 0;
	data->ray.disH = 1000000;
	data->ray.hx = data->player_x;
	data->ray.hy = data->player_y;
	data->ray.aTan = -1 / tan(data->ray.ra);
}

void	reset_ray(t_data *data)
{
	data->ray.dof = 0;
	data->ray.disV = 1000000;
	data->ray.vx = data->player_x;
	data->ray.vy = data->player_y;
	data->ray.nTan = -tan(data->ray.ra);
}