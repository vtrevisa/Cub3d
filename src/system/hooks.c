/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:29:02 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/06 20:41:49 by vtrevisa         ###   ########.fr       */
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

int	is_moviment_possible(t_data *data, double x, double y)
{
	double player_x ;
	double player_y ;
	
	player_y = ((x / 10.0 ));
	player_x = ((y / 10.0 ));
	if(player_x + 1.5 >= data->map_size[1] || player_y + 1.5 >= data->map_size[0])
		return (0);	
	if(player_x < 1.0 || player_y < 1.0)
		return (0);	
	return (1);
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
		if(!is_moviment_possible(data, data->player_x + round(x), data->player_y + round(y)))
			return (0);
	}
	else if (key == S)
	{
		x -= data->p_deltX;
		y -= data->p_deltY;
		if(!is_moviment_possible(data, data->player_x + round(x), data->player_y + round(y)))
			return (0);
	}
	else if (key == D)
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
			while (i++, i < 32)
				if_d(data);
		}
	}
	else if (key == ARROW_L)
	{
		if (data->arrow_l != 1)
		{
			data->arrow_l = 1;
			while (i++, i < 32)
				if_a(data);
		}
	}
	data->player_x += round(x);
	data->player_y += round(y);
	display(data);
	return (0);
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
