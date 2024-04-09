/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:28:07 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/09 12:01:48 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	init_params(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (invalid_config());
	else
		data->map_name = ft_strdup(argv[1]);
	data->upg = 0;
	data->max_x = 1024;
	data->max_y = 600;
	return (1);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, data->max_x, data->max_y, "CUB3D");
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, data->max_x, data->max_y);
	if (!data->img)
		return (0);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->line_lenght, &data->endian);
	return (1);
}

int	init_map(t_data *data)
{
	if (map_reader(data) < 0)
		exit (-1);
	data->initial_x = 0;
	data->initial_y = 0;
	data->size_x = (data->max_x / 2) / data->map_size[0];
	data->size_y = 600 / data->map_size[1];
	if (data->size_x < data->size_y)
	{
		data->size_y = data->size_x;
		data->cube_size = data->size_x;
	}
	else
	{
		data->size_x = data->size_y;
		data->cube_size = data->size_y;
	}
	data->x = 0;
	data->y = 0;
	data->flag = 0;
	data->p_angle = PI * data->player_dir;
	data->p_deltX = cos (data->p_angle) * 5;
	data->p_deltY = sin (data->p_angle) * 5;
	return (1);
}
