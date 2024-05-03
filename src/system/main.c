/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:48 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/04 13:59:25 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	display(t_data *data)
{
	draw_background(data);
	draw_map(data);
	draw_player(data);
	drawrays3d(data);
}

static int	init_all(t_data *data, int argc, char **argv)
{
	if (init_params(data, argc, argv) < 0)
		return (-1);
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

	ft_bzero(&data, sizeof(t_data));
	if (init_all(&data, argc, argv) < 0)
		return (0);
	display(&data);
	get_hook(&data);
	mlx_loop(data.mlx);
	return (0);
}
