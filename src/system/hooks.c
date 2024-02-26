/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:29:02 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/02/26 17:03:09 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	movement(int key, t_data *data)
{
	show_dataxy(data);
	int	factor;
	
	factor = 10;
	hook_got(key);
	if (key == 119) // W
	{
		data->player_x += data->p_deltX;
		data->player_y -= data->p_deltX;
		/* data->initial_x -= factor/2;All functions of the math
library
		data->initial_y -= factor/2;
		data->size_x += factor;
		data->size_y += factor; */
	}
	else if (key == 115) // S
	{
		data->player_x -= data->p_deltX;
		data->player_y += data->p_deltX;
		/* data->initial_x += factor/2;
		data->initial_y += factor/2;
		data->size_x -= factor;
		data->size_y -= factor; */
	}
	else if (key == 100) // D
	{
		data->p_angle += 0.1;
		/* if (data->p_angle > (2 * PI))
			data->p_angle -= (2 * PI); */
		data->p_deltX = cos (data->p_angle) * 5;
		data->p_deltY = sin (data->p_angle) * 5;
	}
	else if (key == 97) // A
	{
		data->p_angle -= 0.1;
		/* if (data->p_angle < 0)
			data->p_angle += (2 * PI); */
		data->p_deltX = cos (data->p_angle) * 5;
		data->p_deltY = sin (data->p_angle) * 5;
	}
	display(data);
/* 	draw_quadrilaters(data->initial_x, data->initial_y, data->size_x, data->size_y, data, 0x00FF0000);
	refresh(data); */
}

void	get_hook(t_data *data)
{
	mlx_key_hook(data->win, movement, data);
}
