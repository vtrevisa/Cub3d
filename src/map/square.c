/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:50:02 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/08 18:15:30 by vtrevisa         ###   ########.fr       */
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

void	dda(int x1, int x2, int y1, int y2, int col, t_data *data)
{
	int step;
	float x, y, xinc, yinc;
	step = fabs (x2 - x1);
	if (fabs (y2 - y1) > step)
		step = fabs (y2 - y1);
	xinc = (x2 - x1)/step;
	yinc = (y2 - y1)/step;
	x = x1;
	y = y1;
	while (x < x2)
	{
		draw_quadrilaters((int)fabs (x), (int)fabs (y), 2, 2, data, col);
		x = x + xinc;
		y = y + yinc;
	}
	refresh (data);
}
