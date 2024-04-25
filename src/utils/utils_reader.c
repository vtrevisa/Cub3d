/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:34:06 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/25 20:10:26 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	*remove_space(t_data *data, char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc (sizeof (char) * data->max_x);
	while (str[i])
	{
		if (str[i] != ' ')
		{
			ret[j] = str[i];
			j++;
			i++;
		}
		else
			i++;
	}
	return (ret);
}

int	get_quantity_blocks(int *x, int *y, char *map_name)
{
	char	*tmp;
	int		x_tmp;
	int		blocks_nbr;
	int		fd;

	fd = open(map_name, O_RDONLY);
	tmp = get_next_line(fd);
	x[0] = ft_strlen_spaceless(tmp);
	y[0] = 0;
	blocks_nbr = x[0];
	while (tmp)
	{
		free (tmp);
		tmp = get_next_line(fd);
		if (tmp)
		{
			x_tmp = ft_strlen_spaceless(tmp);
			blocks_nbr += x_tmp;
			if (x_tmp > x[0])
				x[0] = x_tmp;
		}
		y[0]++;
	}
	close (fd);
	return (blocks_nbr);
}

int	check_dir_facing(char c, t_data *data, int i, int l)
{
	if (data->flag)
		return (map_error());
	data->player_dir = c;
	data->flag = 1;
	data->player_x = i;
	data->player_y = l;
	return (1);
}
