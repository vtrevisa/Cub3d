/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:34:06 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/09 12:01:34 by vtrevisa         ###   ########.fr       */
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
	if (c == 'N')
		data->player_dir = 1.5;
	if (c == 'S')
		data->player_dir = 0.5;
	if (c == 'E')
		data->player_dir = 0;
	if (c == 'W')
		data->player_dir = 1;
	data->flag = 1;
	data->player_x = i;
	data->player_y = l;
}

static int	check_map(char *str, t_data *data, int l)
{
	int		i;
	char	c;
	int		j;

	j = 0;
	i = 0;
	while (str[i + j])
	{
		c = str[i + j];
		if (c == '1' || c == '0')
			i++;
		else if (c == 'S' || c == 'W' || c == 'N' || c == 'E')
		{
			check_dir_facing(c, data, i, l);
			i++;
		}
		else if (c == ' ')
			j++;
		else if (c == '\n' || c == '\0')
			return (1);
		else
			return (map_error());
	}
	return (0);
}

char	*cat_map(t_data *data, char **tmp, int fd, int l)
{
	char	*tmpns;

	if (check_map(*tmp, data, l) < 0)
		exit (-1);
	tmpns = remove_space(data, *tmp);
	data->map = ft_strjoin(data->map, tmpns);
	free(*tmp);
	*tmp = get_next_line(fd);
}
