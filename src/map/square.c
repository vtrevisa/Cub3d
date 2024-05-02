/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:50:02 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/02 17:15:25 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_quadrilaters(int initial_x, int initial_y, int size_x, int size_y, t_data *data, int color)
{
	int	img_x;
	int	img_y;

	img_x = initial_x;
	img_y = initial_y;
	while (initial_y <= size_y + img_y)
	{
		initial_x = img_x;
		while (initial_x <= size_x + img_x)
		{
			my_mlx_pixel_put(data, initial_x, initial_y, color);
			initial_x++;
		}
		initial_y++;
	}
}

void	draw_quadrilaters_2(t_data *data)
{
	int	img_x;
	int	img_y;

	img_x = data->draw.initial_x;
	img_y = data->draw.initial_y;
	while (data->draw.initial_y <= data->draw.size_y + img_y)
	{
		data->draw.initial_x = img_x;
		while (data->draw.initial_x <= data->draw.size_x + img_x)
		{
			my_mlx_pixel_put(data, data->draw.initial_x, data->draw.initial_y, data->draw.color);
			data->draw.initial_x++;
		}
		data->draw.initial_y++;
	}
}
