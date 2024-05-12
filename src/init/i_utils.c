/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:13:20 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/12 00:19:55 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	get_p_angle(char dir)
{
	if (dir == 'N')
		return (3);
	if (dir == 'S')
		return (1);
	if (dir == 'E')
		return (0);
	if (dir == 'W')
		return (2);
	return (0);
}

void	free_tmp(char **tmp, t_data *data)
{
	free(data->map_lined);
	data->map_lined = ft_strdup(*tmp);
	free (*tmp);
}

int	fix_map(t_data *data, int x_source)
{
	char	*tmp;
	int		x_dest;
	int		x;

	if (!data->map_lined)
		return (-1);
	x_dest = data->map_size[0] + 2;
	tmp = malloc(10000);
	ft_memset(tmp, ' ', data->map_size[0] + 2);
	while (data->map_lined[x_source])
	{
		x = -1;
		tmp[x_dest++] = ' ';
		while (++x < data->map_size[0])
			tmp[x_dest++] = data->map_lined[x_source++];
		tmp[x_dest++] = ' ';
	}
	tmp[x_dest++] = ' ';
	x = -1;
	x_dest -= 1;
	while (++x < data->map_size[0] + 2)
		tmp[x_dest++] = ' ';
	tmp[x_dest] = 0;
	free_tmp(&tmp, data);
	return (1);
}
