/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:53:15 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/12/28 16:33:31 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	fill_map(t_data *data)
{
	draw_square(0, 0, 50, 50, data, 0x00FF0000);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);;
}

void	draw_map(t_data *data)
{
	int	fd;
	int *size;
	
}