/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:53:15 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/12 23:45:19 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_background(t_data *data)
{
	int	ini_x;
	int	ini_y;

	ini_x = 0;
	ini_y = 0;
	while (ini_y < data->max_y)
	{
		ini_x = 0;
		while (ini_x < data->max_x)
		{
			mlx_put_pixel(data->img, ini_x, ini_y, 0);
			ini_x++;
		}
		ini_y++;
	}
	// refresh(data);
}

static void	if_wall_or_ground(int *ix, int iy, t_data *data, char flag)
{
	if (flag == '1')
	{
		draw_red_quadrilaters(*ix, iy, data->cube_size -2, data);
		*ix += data->size_x;
	}
	else if (flag == '0')
	{
		// draw_grey_quadrilaters(*ix, iy, data->size_x - 2, data->size_x, data);
		*ix += data->size_x;
	}
}

static void	if_player(int *ix, int iy, t_data *data, char flag)
{
	// TODO: rever flag
	if(flag)
		// draw_grey_quadrilaters(*ix, iy, data->size_x - 2, data->size_x, data);
	if (data->upg == 0)
	{
		data->player_x = *ix;
		data->player_y = iy;
	}
	*ix += data->size_x;
}

void	draw_map(t_data *data)
{
	int	i;
	int	i_x;
	int	i_y;

	i_x = data->initial_x;
	i_y = data->initial_y;
	// draw_background(data);
	i = 0;
	while (data->map[i])
	{
		if (data->map[i] == '1' || data->map[i] == '0')
			if_wall_or_ground(&i_x, i_y, data, data->map[i]);
		else if (data->map[i] == 'W' || data->map[i] == 'E' || data->map[i] == 'N' || data->map[i] == 'S')
			if_player(&i_x, i_y, data, data->map[i]);
		else if (data->map[i] == '\n')
		{
			i_x = 0;
			i_y += data->size_y;
		}
		i++;
	}
	data->upg = 1;
	// refresh(data);
}
