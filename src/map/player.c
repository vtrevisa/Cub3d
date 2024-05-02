/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:21:10 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/02 17:32:01 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_player(t_data *data)
{
	data->draw.initial_x = data->player_x;
	data->draw.initial_y = data->player_y;
	data->draw.size_x = 5;
	data->draw.size_y = 5;
	data->draw.color = 0xffff00;
	draw_quadrilaters(data);
	data->draw.initial_x = (data->player_x + data->p_deltX * 2) + 2;
	data->draw.initial_y = (data->player_y + data->p_deltY * 2) + 2;
	data->draw.size_x = 2;
	data->draw.size_y = 2;
	data->draw.color = 0xffff00;
	draw_quadrilaters(data);
	refresh(data);
}