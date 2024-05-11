/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:13:20 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/11 19:53:29 by r-afonso         ###   ########.fr       */
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

void	fix_map(t_data *data)
{
	char	*tmp;
	int		x_source;
	int		x_dest;
	int		x;

	x_source = 0;
	x_dest = data->map_size[0] + 2;
	tmp = malloc(10000);
	ft_memset((tmp), ' ', data->map_size[0] + 2);
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
	data->map_lined = tmp;
	data->map_size[0] += 2;
	data->map_size[1] += 2;
}
