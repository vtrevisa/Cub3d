/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:48 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/03/07 15:39:39 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	display(t_data *data)
{
	draw_background(data);
	draw_map(data);
	drawRays3D(data);
	draw_player(data);
}

int	main(int argc, char *argv[])
{
	t_data data;
	
	if (argc != 2)
		return (-1);
	ft_bzero(&data, sizeof(t_data));
	if (!init_mlx(&data, argc, argv))
		return (-1);
	/*RAY_CAST_CALCULATOR*/
	display(&data);
	get_hook(&data);
	mlx_loop(data.mlx);
	return (0);
}