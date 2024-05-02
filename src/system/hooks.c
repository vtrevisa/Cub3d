/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:29:02 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/02 19:01:35 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
	else if (key == 65363)
		if_d(data);
	else if (key == 65361)
		if_a(data);
	else if (key == 65307)
		exit_mlx(data);
	data->player_x += (int) x;
	data->player_y += (int) y;
	display(data);
	return (0);
}

void	get_hook(t_data *data)
{
	mlx_key_hook(data->win, movement, data);
}
