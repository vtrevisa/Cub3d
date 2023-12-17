/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:29:02 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/12/17 17:04:42 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	movement(int key, t_data *data)
{
	show_dataxy(data);
	int	factor;
	
	factor = 10;
	hook_got(key);
	if (key == 119)
	{
		data->initial_x -= factor/2;
		data->initial_y -= factor/2;
		data->size_x += factor;
		data->size_y += factor;
	}
	else if (key == 115)
	{
		data->initial_x += factor/2;
		data->initial_y += factor/2;
		data->size_x -= factor;
		data->size_y -= factor;
	}
	draw_square(data->initial_x, data->initial_y, data->size_x, data->size_y, data);
	refresh(data);
}

void	get_hook(t_data *data)
{
	mlx_key_hook(data->win, movement, data);
}