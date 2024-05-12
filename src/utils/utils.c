/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:22:13 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/11 23:54:37 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	refresh(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int		offset;
	char	*dst;

	offset = (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

int	ft_strlen_spaceless(const char *s)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n')
			len++;
		i++;
	}
	return ((size_t)len);
}

static int	exit_map(t_data *data)
{
	int	i;
	int	size;

	i = -1;
	size = 2;
	if (data->mp_sz_p2 == 0)
		size = 0;
	if (data->map_array)
	{
		while (++i, i < data->map_size[1] - size && data->map_array[i])
			free (data->map_array[i]);
		free (data->map_array);
	}
	free(data->map);
	free(data->map_name);
	free (data->map_lined);
	i = -1;
	while (++i < 4)
		free (data->textures[i]);
	return (0);
}

int	exit_mlx(t_data *data)
{		
	mlx_do_key_autorepeaton(data->mlx);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit_map(data);
	exit(0);
	return (0);
}
