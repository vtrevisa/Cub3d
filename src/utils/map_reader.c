/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:07:31 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/03/19 14:57:36 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	get_quantity_blocks(int *x, int *y, char *map_name)
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

int	check_map(char *str, t_data *data, int l)
{
	int		i;
	char	c;
	int		j;
	
	j = 0;
	i = 0;
	while(str[i + j])
	{
		c = str[i + j];
		if (c == '1' || c == '0')
		{
			i++;
		}
		else if (c == 'N')
		{
			if (data->flag)
				return (map_error());
			i++;
			data->player_x = i;
			data->player_y = l;
			data->player_dir = 'N';
			data->flag = 1;
		}
		else if (c == 'S')
		{
			if (data->flag)
				return (map_error());
			i++;
			data->player_x = i;
			data->player_y = l;
			data->player_dir = 'S';
			data->flag = 1;
		}
		else if (c == 'W')
		{
			if (data->flag)
				return (map_error());
			i++;
			data->player_x = i;
			data->player_y = l;
			data->player_dir = 'W';
			data->flag = 1;
		}
		else if (c == 'E')
		{
			if (data->flag)
				return (map_error());
			i++;
			data->player_x = i;
			data->player_y = l;
			data->player_dir = 'E';
			data->flag = 1;
		}
		else if (c == ' ')
		{
			j++;
		}
		else if (c == '\n' || c == '\0')
			return (1);
		else
			return (map_error());
	}
	return (0);
}

char *remove_space(t_data *data, char *str)
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

char *remove_lnbrk(t_data *data, char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc (sizeof (char) * data->max_x);
	while (str[i])
	{
		if (str[i] != '\n')
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

int	map_reader(t_data *data)
{
	int		fd;
	char	*tmp;
	char	*tmpns;
	char	*map_name;
	int	l = 1;

	map_name = ft_strjoin("./src/maps/", data->map_name);
	fd = open(map_name, O_RDONLY);
	//GET_MAP_PARAMS
	data->blocks_nbr = get_quantity_blocks(&data->map_size[0],& data->map_size[1], map_name);
	show_map_nbrs(data);
	tmp = get_next_line(fd);
	data->map = malloc(sizeof(char) * data->blocks_nbr);
	ft_bzero(data->map, data->blocks_nbr);
	while(tmp)
	{
	//CHECK_MAP
		if (check_map(tmp, data, l) < 0)
			return (-1);
	//LOAD_MAP
		tmpns = remove_space(data, tmp);
		data->map = ft_strjoin(data->map, tmpns);
		free(tmp);
		tmp = get_next_line(fd);
		l++;
	}
	map_loaded(data->map_name);
	show_map(data->map);
	show_map_nbr(data->map);
	data->map_lined = remove_lnbrk(data, data->map);
	show_map(data->map_lined);
	ft_printf("FACING ");
	ft_printf(RED);
	ft_printf("%c ", data->player_dir);
	ft_printf(WHITE);
	ft_printf("AT ");
	ft_printf(RED);
	ft_printf("%d, %d\n", data->player_x, data->player_y);
	ft_printf(WHITE);
}