/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:47:34 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/30 15:50:30 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

double	dist(t_data *data, double bx, double by)
{
	int	ax;
	int	ay;

	ax = data->player_x;
	ay = data->player_y;
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}
