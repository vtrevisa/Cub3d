/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:50:02 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/12/26 18:57:41 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
/*	
	x and y -> pixels to be painted
	size_x and y -> how many pixels will be painted
	img_x and y -> initial poition of the pixels to be painted
*/

static void	draw_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while(x < data->max_x)
	{
		y = 0;
		while (y < data->max_y)
		{
			if ((y < data->initial_y || y > data->initial_y + data->size_y) || (x < data->initial_x || x > data->initial_x + data->size_x))
				my_mlx_pixel_put(data, x, y, 0x00110000);
			y++;
		}
		x++;
	}
}


void	draw_square(int initial_x, int initial_y, int size_x, int size_y, t_data *data, int color)
{
	int img_x;
	int img_y;
	
	img_x = initial_x;
	img_y = initial_y;
/* 	draw_background(data); */
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
	square_drawn();
}
