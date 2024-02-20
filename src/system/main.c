/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:48 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/02/20 19:03:15 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	casting_ray(t_data *data)
{
	unsigned float	x[10];
	unsigned float	angle[10];
	unsigned float	ray[10];
	int				i;
	
	i = 1;
	while (i <= 10)
	{
		x[i] = i / (data->max_x / data->max_y) - 0.5;

		i++;
	} 
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
	draw_map(&data);
	mlx_loop(data.mlx);
	return (0);
}