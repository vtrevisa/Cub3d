/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:03:32 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/09 11:43:38 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_red_quadrilaters(int ix, int iy, int sz, t_data *data)
{
	int	img_x;
	int	img_y;

	img_x = ix;
	img_y = iy;
	while (iy <= sz + img_y)
	{
		ix = img_x;
		while (ix <= sz + img_x)
		{
			my_mlx_pixel_put(data, ix, iy, 0x00FF0000);
			ix++;
		}
		iy++;
	}
}

void	draw_grey_quadrilaters(int ix, int iy, int sz, t_data *data)
{
	int	img_x;
	int	img_y;

	img_x = ix;
	img_y = iy;
	while (iy <= sz + img_y)
	{
		ix = img_x;
		while (ix <= sz + img_x)
		{
			my_mlx_pixel_put(data, ix, iy, 0x666666);
			ix++;
		}
		iy++;
	}
}

void	draw_yell_quadrilaters(int ix, int iy, int sz, t_data *data)
{
	int	img_x;
	int	img_y;

	img_x = ix;
	img_y = iy;
	while (iy <= sz + img_y)
	{
		ix = img_x;
		while (ix <= sz + img_x)
		{
			my_mlx_pixel_put(data, ix, iy, 0xffff00);
			ix++;
		}
		iy++;
	}
}

void	draw_3d_quadrilaters(t_ray *r, t_data *data)
{
	int	img_x;
	int	img_y;

	img_x = r->ini_x;
	img_y = r->ini_y;
	while (r->ini_y <= r->size_y + img_y)
	{
		r->ini_x = img_x;
		while (r->ini_x <= r->size_x + img_x)
		{
			my_mlx_pixel_put(data, r->ini_x, r->ini_y, r->color);
			r->ini_x++;
		}
		r->ini_y++;
	}
}
