/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_hole.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:53:50 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/11 19:49:57 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	exit_mlx(t_data *data)
{
	// mlx_destroy_image(data->mlx, data->img);
	// mlx_destroy_window(data->mlx, data->win);
	// mlx_destroy_display(data->mlx);
	mlx_terminate(data->mlx);
	free (data->mlx);
	exit(0);
}

void	black_hole(t_data *data, t_ray *ray)
{
	if (data->mlx)
		exit_mlx(data);
	free(data->map);
	free(data->map_lined);
	free(data->map_name);
	free(data);
	exit(0);
}
