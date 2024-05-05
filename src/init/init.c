/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:28:07 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/05 12:37:19 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	get_p_angle(char dir)
{
	if (dir == 'N')
		return (3);
	if (dir == 'S')
		return (1);
	if (dir == 'E')
		return (0);
	if (dir == 'W')
		return (2);
	return (0);
}

int	init_params(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (invalid_input());
	else
		data->map_name = ft_strdup(argv[1]);
	data->upg = 0;
	data->max_x = 1024;
	data->max_y = 512;
	data->col_ok = 0;
	data->txt_ok = 0;
	data->arrow_r = 0;
	data->arrow_l = 0;
	return (1);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	mlx_do_key_autorepeatoff(data->mlx);
	if (!data->mlx)
		return (mlx_error());
	data->win = mlx_new_window(data->mlx, data->max_x, data->max_y, "CUB3D");
	if (!data->win)
		return (mlx_error());
	data->img = mlx_new_image(data->mlx, data->max_x, data->max_y);
	if (!data->img)
		return (mlx_error());
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->line_lenght, &data->endian);
	return (1);
}

int	init_map(t_data *data)
{
	if (config_file_loader(data) < 0)
		return (-1);
	data->initial_x = 0;
	data->initial_y = 0;
	data->size_x = 10;
	data->size_y = 10;
	if (data->size_x < data->size_y)
		data->size_y = data->size_x;
	else
		data->size_x = data->size_y;
	data->cube_size = data->size_x;
	data->x = 0;
	data->y = 0;
	data->flag = 0;
	data->p_angle = (PI/2) * get_p_angle(data->player_dir);
	data->p_deltX = cos (data->p_angle) * 5;
	data->p_deltY = sin (data->p_angle) * 5;
	return (1);
}
