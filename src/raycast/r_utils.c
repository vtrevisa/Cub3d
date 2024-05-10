/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:47:34 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/10 11:16:36 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include <X11/X.h>

void	draw_texture_walls(t_data *data)
{
	int	img_x;
	int	img_y;
	int	save_color;

	img_x = data->draw.initial_x;
	img_y = data->draw.initial_y;
	save_color = data->draw.color;
	while (data->draw.initial_y <= data->draw.size_y + img_y)
	{
		
		if (data->draw.initial_y >= 3 * (data->draw.size_y / 4)+ img_y)
			data->draw.color = save_color + 0x003000;
		else
		 	data->draw.color = save_color;
		data->draw.initial_x = img_x;
		while (data->draw.initial_x <= data->draw.size_x + img_x)
		{
			my_mlx_pixel_put(data, data->draw.initial_x, data->draw.initial_y,
					data->draw.color);
			data->draw.initial_x++;
		}
		data->draw.initial_y++;
	}
}

double	dist(t_data *data, double bx, double by)
{
	return (sqrt((bx - data->player_x) * (bx - data->player_x) + (by
				- data->player_y) * (by - data->player_y)));
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

void	reset_ray(t_data *data, int horizontal)
{
	data->ray.dof = 0;
	if (horizontal)
	{
		data->ray.disH = 1000000;
		data->ray.hx = data->player_x;
		data->ray.hy = data->player_y;
		data->ray.aTan = -1 / tan(data->ray.ra);
	}
	else
	{
		data->ray.disV = 1000000;
		data->ray.vx = data->player_x;
		data->ray.vy = data->player_y;
		data->ray.nTan = -tan(data->ray.ra);
	}
}
