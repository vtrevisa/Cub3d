/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:48 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/12 00:12:19 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	display(t_data *data)
{
	draw_background(data);
	draw_map(data);
	draw_player(data);
	data->player_x += (data->cube_size * 2);
	data->player_y += (data->cube_size);
	drawrays3d(data);
	data->player_x -= (data->cube_size * 2);
	data->player_y -= (data->cube_size);
	draw_map(data);
	draw_player(data);
	refresh(data);
}

static int	init_all(t_data *data, int argc, char **argv)
{
	if (init_params(data, argc, argv) < 0)
		return (-2);
	else if (init_mlx(data) < 0)
		return (-1);
	else if (init_map(data) < 0)
		return (-1);
	else
		return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		error;

	error = 0;
	ft_bzero(&data, sizeof(t_data));
	error = init_all(&data, argc, argv);
	if (error < 0)
	{
		if (error == -1)
			exit_mlx(&data);
		if (error == -2)
			return (0);
		return (0);
	}
	display(&data);
	key_press(A, &data);
	key_press(D, &data);
	get_hook(&data);
	mlx_loop(data.mlx);
	return (0);
}
