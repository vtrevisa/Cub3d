/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:29:02 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/08 17:51:51 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

#define W 119
#define S 115
#define D 100
#define A 97

static void	if_d(t_data *data)
{
	data->p_angle += 0.05;
	if (data->p_angle > (2 * PI))
		data->p_angle -= (2 * PI);
	data->p_deltX = cos (data->p_angle) * 5;
	data->p_deltY = sin (data->p_angle) * 5;
}

static void	if_a(t_data *data)
{
	data->p_angle -= 0.05;
	if (data->p_angle <= 0)
		data->p_angle += (2 * PI);
	data->p_deltX = cos (data->p_angle) * 5;
	data->p_deltY = sin (data->p_angle) * 5;
}

static int	movement(int key, t_data *data)
{
	int		factor;
	double	x;
	double	y;

	x = 0;
	y = 0;
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
	data->player_x += (int) x;
	data->player_y += (int) y;
	display(data);
}

void	get_hook(t_data *data)
{
	mlx_key_hook(data->win, movement, data);
}
