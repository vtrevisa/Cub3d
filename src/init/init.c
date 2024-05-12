/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:28:07 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/11 23:53:43 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	init_params(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (input_error());
	else
		data->map_name = ft_strdup(argv[1]);
	data->upg = 0;
	data->max_x = 1056;
	data->max_y = 726;
	data->col_ok = 0;
	data->txt_ok = 0;
	data->arrow_r = 0;
	data->arrow_l = 0;
	data->remove_l.source_index = 0;
	data->remove_l.target_index = 0;
	data->remove_l.line_c_index = 0;
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
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_lenght, &data->endian);
	return (1);
}

int	validate_textures(t_data *data)
{
	int			count;
	int			count_inter;
	int			texture_detected;
	const char	*texture[4] = {"texture_1", "texture_2", "texture_3",
		"texture_4"};

	count = -1;
	while (count++, count < 4)
	{
		texture_detected = 0;
		count_inter = -1;
		while (count_inter++, count_inter < 4)
		{
			if (!compare_strings(data->textures[count],
					(char *)texture[count_inter]))
			{
				texture_detected = 1;
				break ;
			}
		}
		if (!texture_detected)
			return (-1);
	}
	return (1);
}

int	check_duplicates(t_data *data)
{
	int	count;
	int	count_intern;

	count = 0;
	while (count < 4)
	{
		count_intern = count + 1;
		while (count_intern < 4)
		{
			if (compare_strings(data->textures[count],
					data->textures[count_intern]) == 0)
				return (-1);
			count_intern++;
		}
		count++;
	}
	return (0);
}

int	init_map(t_data *data)
{
	int	x_source;

	data->mp_sz_p2 = 0;
	if (config_file_loader(data) < 0)
		return (-1);
	if (validate_textures(data) < 0)
		return (txt_error());
	if (check_duplicates(data) < 0)
		return (txt_error());
	data->initial_x = 0;
	data->initial_y = 0;
	data->cube_size = 10;
	data->x = 0;
	data->y = 0;
	data->flag = 0;
	data->p_angle = (PI / 2) * get_p_angle(data->player_dir);
	data->p_deltX = cos(data->p_angle);
	data->p_deltY = sin(data->p_angle);
	x_source = 0;
	if (fix_map(data, x_source) < 0)
		return (-1);
	data->map_size[0] += 2;
	data->map_size[1] += 2;
	return (1);
}
