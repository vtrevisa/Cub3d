/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:29:02 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/03 22:02:37 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	if_d(t_data *data)
{
	data->p_angle += 0.05;
	if (data->p_angle > (2 * PI))
		data->p_angle -= (2 * PI);
	data->p_deltX = cos(data->p_angle) * 5;
	data->p_deltY = sin(data->p_angle) * 5;
}

static void	if_a(t_data *data)
{
	data->p_angle -= 0.05;
	if (data->p_angle <= 0)
		data->p_angle += (2 * PI);
	data->p_deltX = cos(data->p_angle) * 5;
	data->p_deltY = sin(data->p_angle) * 5;
}

static int	key_press(int key, t_data *data)
{
	double	x;
	double	y;
	int		i;

	x = 0;
	y = 0;
	i = -1;
	
	if (key == W)
	{
		x += data->p_deltX;
		y += data->p_deltY;
	}
	else if (key == S)
	{
		x -= data->p_deltX;
		y -= data->p_deltY;
	}
	else if (key == D)
		if_d(data);
	else if (key == A)
		if_a(data);
	else if (key == 65307)
		exit_mlx(data);
	else if (key == 65363)
	{
		if (data->arrow_r != 1)
		{
			data->arrow_r = 1;
			while (i++, i < 32)
				if_d(data);
		}
	}
	else if (key == 65361)
	{
		if (data->arrow_l != 1)
		{
			data->arrow_l = 1;
			while (i++, i < 32)
				if_a(data);
		}
	}
	data->player_x += (int)x;
	data->player_y += (int)y;
	display(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	int		i;

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
	mlx_hook(data->win, 17, 0, exit_mlx, data);
}
