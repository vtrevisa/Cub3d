/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:21:10 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/01 22:04:13 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_player(t_data *data)
{
	/* write(1, "ok1\n", 4); */
	draw_quadrilaters(data->player_x, data->player_y, 5, 5, data, 0xffff00);
	/* this makes a square to orbitate the player square somehow, its fun*/
	draw_quadrilaters((data->player_x + data->p_deltX * 2) + 2, (data->player_y + data->p_deltY * 2) + 2, 2, 2, data, 0xffff00);
	/* write(1, "ok2\n", 4); */
	refresh(data);
	/* write(1, "ok3\n", 4); */
}