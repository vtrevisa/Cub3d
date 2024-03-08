/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:29:02 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/03/07 16:05:49 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	movement(int key, t_data *data)
{
	show_dataxy(data);
	int	factor;
	float x, y;

	hook_got(key);
	x = y = 0;
	if (key == 119) // W
	{
		x += data->p_deltX;
		y += data->p_deltY;
		/* data->initial_x -= factor/2;
		data->initial_y -= factor/2;
		data->size_x += factor;
		data->size_y += factor; */
	}
	else if (key == 115) // S
	{
		x -= data->p_deltX;
		y -= data->p_deltY;
		/* data->initial_x += factor/2;
		data->initial_y += factor/2;
		data->size_x -= factor;
		data->size_y -= factor; */
	}
	else if (key == 100) // D
	{
		data->p_angle += 0.1;
		if (data->p_angle > (2 * PI))
			data->p_angle -= (2 * PI);
		data->p_deltX = cos (data->p_angle) * 5;
		data->p_deltY = sin (data->p_angle) * 5;
	}
	else if (key == 97) // A
	{
		data->p_angle -= 0.1;
		if (data->p_angle < 0)
			data->p_angle += (2 * PI);
		data->p_deltX = cos (data->p_angle) * 5;
		data->p_deltY = sin (data->p_angle) * 5;
	}
	data->player_x += (int) x;
	data->player_y += (int) y;
	printf("x: %d\ny: %d\nplayer_x: %d\nplayer_y: %d\ndeltX: %f\ndeltY: %f\nangle: %f\n", x, y, data->player_x, data->player_y, data->p_deltX, data->p_deltY, data->p_angle);
	display(data);
/* 	draw_quadrilaters(data->initial_x, data->initial_y, data->size_x, data->size_y, data, 0x00FF0000);
	refresh(data); */
}

void	get_hook(t_data *data)
{
	mlx_key_hook(data->win, movement, data);
}
