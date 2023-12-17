/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:50:02 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/12/17 14:38:02 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
/*	
	x and y -> pixels to be painted
	size_x and y -> how many pixels will be painted
	img_x and y -> initial poition of the pixels to be painted
*/


void	draw_square(int initial_x, int initial_y, int size_x, int size_y, t_data *data)
{
	int img_x;
	int img_y;
	
	img_x = initial_x;
	img_y = initial_y;
	while (initial_y <= size_y + img_y)
	{
		initial_x = img_x;
		while (initial_x <= size_x + img_x)
		{
			my_mlx_pixel_put(data, initial_x, initial_y, 0x00FF0000);
			initial_x++;
		}
		initial_y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	square_drawn();
}
