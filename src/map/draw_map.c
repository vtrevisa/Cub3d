/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:53:15 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/24 15:52:32 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	draw_ceiling(t_data *data)
{
	//3d map ceiling and floor
	draw_quadrilaters(data->max_x/2 + 38, 0, data->max_x/2, data->max_y/2, data, data->color_c);
	draw_quadrilaters(data->max_x/2 + 38, data->max_y/2, data->max_x/2, data->max_y/2, data, data->color_f);
	//black background of minimap
	draw_quadrilaters(0, 0, data->max_x/2, data->max_y, data, 0);
	refresh(data);
}

static void	draw_floor(t_data *data)
{
	int	ini_x;
	int	ini_y;

	ini_x = data->max_x / 2;
	ini_y = data->max_y / 2;
	while (ini_y <= data->max_y)
	{
		ini_x = data->max_x / 2;
		while (ini_x <= data->max_x)
		{
			my_mlx_pixel_put(data, ini_x, ini_y, data->color_f);
			ini_x++;
		}
		ini_y++;
	}
	refresh(data);
}

void	draw_background(t_data *data)
{
	draw_floor(data);
	draw_ceiling(data);
}

static void	if_wall_or_ground(int *ix, int iy, t_data *data, char flag)
{
	if (flag == '1')
	{
		draw_red_quadrilaters(*ix, iy, data->cube_size - 2, data);
		*ix += data->size_x;
	}
	else if (flag == '0')
	{
		draw_grey_quadrilaters(*ix, iy, data->cube_size - 2, data);
		*ix += data->size_x;
	}
}

static void	if_player(int *ix, int iy, t_data *data, char flag)
{
	draw_grey_quadrilaters(*ix, iy, data->cube_size - 2, data);
	if (data->upg == 0)
	{
		data->player_x = *ix;
		data->player_y = iy;
	}
	*ix += data->size_x;
}

static void	if_space(int *ix, t_data *data)
{
	*ix += data->size_x;
}

void	draw_map(t_data *data)
{
	int	i;
	int	c;
	int	i_x;
	int	i_y;
	int	center;

	center = data->size_x / 2;
	i_x = data->initial_x;
	i_y = data->initial_y;
	draw_background(data);
	i = 0;
	while (data->map[i])
	{
		c = data->map[i];
		if (c == ' ')
		{i_x += data->size_x;}
		else if (c == '1')
		{
			draw_quadrilaters(i_x, i_y, data->size_x - 2, data->size_y - 2, data, 0x00FF0000);
			i_x += data->size_x;
		}
		else if (c == '0')
		{
			draw_quadrilaters(i_x, i_y, data->size_x - 2, data->size_y - 2, data, 0x666666);
			i_x += data->size_x;
		}
		else if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
		{
			draw_quadrilaters(i_x, i_y, data->size_x - 2, data->size_y - 2, data, 0x666666);
			if (data->upg == 0)
			{
				data->player_x = i_x + center;
				data->player_y = i_y + center;
			}
			i_x += data->size_x;
		}
		else if (c == '\n')
		{
			i_x = 0;
			i_y += data->size_y;
		}
		else if (c == ' ' || c == '	')
			if_space(&i_x, data);
		i++;
	}
	data->upg = 1;
	refresh(data);
}
