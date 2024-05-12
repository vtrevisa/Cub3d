/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:29:02 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/12 00:11:53 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	is_moviment_possible(t_data *data, double x, double y)
{
	double	player_x;
	double	player_y;

	player_y = ((x / 10.0));
	player_x = ((y / 10.0));
	if (player_x + 1.5 >= data->map_size[1] || player_y
		+ 1.5 >= data->map_size[0])
		return (0);
	if (player_x < 1.0 || player_y < 1.0)
		return (0);
	return (1);
}

void	handle_da_arrow(int key, t_data *data, int *i)
{
	if (key == D)
		if_d(data);
	else if (key == A)
		if_a(data);
	else if (key == 65307)
		exit_mlx(data);
	else if (key == ARROW_R)
	{
		if (data->arrow_r != 1)
		{
			data->arrow_r = 1;
			while ((*i)++, *i < 32)
				if_d(data);
		}
	}
	else if (key == ARROW_L)
	{
		if (data->arrow_l != 1)
		{
			data->arrow_l = 1;
			while ((*i)++, *i < 32)
				if_a(data);
		}
	}
}

int	key_press(int key, t_data *data)
{
	int	i;

	i = -1;
	data->x = 0;
	data->y = 0;
	if (key == W)
	{
		data->x += data->p_deltX;
		data->y += data->p_deltY;
		if (!is_moviment_possible(data, data->player_x + round(data->x),
				data->player_y + round(data->y)))
			return (0);
	}
	else if (key == S)
	{
		data->x -= data->p_deltX;
		data->y -= data->p_deltY;
		if (!is_moviment_possible(data, data->player_x + round(data->x),
				data->player_y + round(data->y)))
			return (0);
	}
	handle_da_arrow(key, data, &i);
	data->player_x += round(data->x);
	data->player_y += round(data->y);
	return (display(data), 0);
}

int	key_release(int key, t_data *data)
{
	int	i;

	i = -1;
	if (key == 65363)
	{
		data->arrow_r = 0;
		while (i++, i < 32)
			if_a(data);
	}
	else if (key == 65361)
	{
		data->arrow_l = 0;
		while (i++, i < 32)
			if_d(data);
	}
	display(data);
	return (0);
}

void	get_hook(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 0L, exit_mlx, data);
}
