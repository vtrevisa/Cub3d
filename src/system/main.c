/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:48 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/12/29 16:06:02 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"


int	main(int argc, char *argv[])
{
	t_data data;
	
	if (!init_mlx(&data, argc, argv))
		return (-1);
	draw_map(&data);
	/* draw_quadrilaters(data.initial_x, data.initial_y, data.size_x, data.size_y, &data);
	get_hook(&data); */
	mlx_loop(data.mlx);
	return (0);
}