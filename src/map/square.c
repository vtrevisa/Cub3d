/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:03:32 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/11 21:22:36 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_red_quadrilaters(int initial_x, int initial_y, int size_x, int size_y, t_data *data)
{
	int	img_x;
	int	img_y;

	img_x = initial_x;
	img_y = initial_y;
	while (initial_y <= size_y + img_y)
	{
		initial_x = img_x;
		while (initial_x <= size_x + img_x)
		{
			mlx_put_pixel(data->img, initial_x, initial_y, 0x00FF0000);
			initial_x++;
		}
		initial_y++;
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
			mlx_put_pixel(data->img, ix, iy, 0x666666);
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
			mlx_put_pixel(data->img, ix, iy, 0xffff00);
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
			mlx_put_pixel(data->img, r->ini_x, r->ini_y, r->color);
			r->ini_x++;
		}
		r->ini_y++;
	}
}
