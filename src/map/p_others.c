/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_others.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:43:21 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/12 00:09:42 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	compare_strings(char *str1, char *str2)
{
	if (ft_strlen(str1) != ft_strlen(str2))
		return (1);
	if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0)
		return (0);
	return (1);
}

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
}

void	draw_quadrilaters(t_data *data)
{
	int	img_x;
	int	img_y;

	img_x = data->draw.initial_x;
	img_y = data->draw.initial_y;
	while (data->draw.initial_y <= data->draw.size_y + img_y)
	{
		data->draw.initial_x = img_x;
		while (data->draw.initial_x <= data->draw.size_x + img_x)
		{
			my_mlx_pixel_put(data, data->draw.initial_x, data->draw.initial_y,
				data->draw.color);
			data->draw.initial_x++;
		}
		data->draw.initial_y++;
	}
}
