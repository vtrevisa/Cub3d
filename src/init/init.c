/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:28:07 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/12/17 14:50:37 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"


int	init_mlx(t_data *data)
{
	data->mlx = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	mlx_initialized();

	data->win = NULL;
	data->win = mlx_new_window(data->mlx, 800, 600, "CUB3D");
	if (!data->win)
		return (0);
	screen_initialized();

	data->img = NULL;
	data->img = mlx_new_image(data->mlx, 800, 600);
	if (!data->img)
		return (0);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_lenght, &data->endian);
	img_initialized();

	data->initial_x=350;
	data->initial_y=250;
	data->size_x=100;
	data->size_y=100;
	data->x=0;
	data->y=0;
	show_dataxy(data);
	
	return (1);
}