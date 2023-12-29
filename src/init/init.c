/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:28:07 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/12/28 21:20:17 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	init_mlx(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (invalid_config());
	else
		data->map_name = ft_strdup(argv[1]);
	ft_printf("%s\n", data->map_name);
	
	data->max_x = 800;
	data->max_y = 600;
	data->mlx = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	mlx_initialized();

	data->win = NULL;
	data->win = mlx_new_window(data->mlx, data->max_x, data->max_y, "CUB3D");
	if (!data->win)
		return (0);
	screen_initialized();

	data->img = NULL;
	data->img = mlx_new_image(data->mlx, data->max_x, data->max_y);
	if (!data->img)
		return (0);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_lenght, &data->endian);
	img_initialized();

	data->initial_x=0;
	data->initial_y=0;
	data->size_x=0;
	data->size_y=0;
	data->x=0;
	data->y=0;
	show_dataxy(data);

	if (map_reader(data) < 0)
		exit (-1);
	return (1);
}