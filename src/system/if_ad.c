/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_ad.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:29:46 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/11 18:30:20 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	if_d(t_data *data)
{
	data->p_angle += 0.05;
	if (data->p_angle > (2 * PI))
		data->p_angle -= (2 * PI);
	data->p_deltX = cos(data->p_angle) * 5;
	data->p_deltY = sin(data->p_angle) * 5;
}

void	if_a(t_data *data)
{
	data->p_angle -= 0.05;
	if (data->p_angle <= 0)
		data->p_angle += (2 * PI);
	data->p_deltX = cos(data->p_angle) * 5;
	data->p_deltY = sin(data->p_angle) * 5;
}
