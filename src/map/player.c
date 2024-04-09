/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:21:10 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/09 12:04:06 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_player(t_data *data)
{
	int	temp;

	draw_yell_quadrilaters(data->player_x + 5, data->player_y + 5, 10, data);
	draw_yell_quadrilaters((data->player_x + data->p_deltX * 5) + 8, \
		(data->player_y + data->p_deltY * 5) + 8, 5, data);
	refresh(data);
}
