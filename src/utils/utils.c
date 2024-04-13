/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:22:13 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/11 19:50:29 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	refresh(t_data *data)
{
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	// int		offset;
	// char	*dst;

	// offset = (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	// dst = data->addr + offset;
	mlx_put_pixel(data->img, x, y, color);
	// *(unsigned int *)dst = color;
}

