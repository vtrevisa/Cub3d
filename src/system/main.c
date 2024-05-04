/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:48 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/03 21:16:29 by r-afonso         ###   ########.fr       */
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
	if (!init_params(data, argc, argv))
		return (0);
	else if (!init_mlx(data))
		return (0);
	else if (!init_map(data))
		return (0);
	else
		return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (-1);
	ft_bzero(&data, sizeof(t_data));
	if (!init_all(&data, argc, argv))
		return (-1);
	display(&data);
	get_hook(&data);
	mlx_loop(data.mlx);
	return (0);
}
