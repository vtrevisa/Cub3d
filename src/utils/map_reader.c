/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:43:27 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/25 20:10:02 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	*remove_lnbrk(t_data *data, char *str)
{
	char	*ret;
	int		i;
	int		j;
	int		si;

	i = 0;
	j = 0;
	si = 0;
	ret = malloc (sizeof (char) * data->max_x);
	while (str[i])
	{
		if (str[i] != '\n')
		{
			ret[j] = str[i];
			j++;
			i++;
			si++;
		}
		if (str[i] == '\n')
		{
			while (si < data->map_size[0])
			{
				ret[j] = '.';
				j++;
				si++;
			}
			i++;
			si = 0;
		}
	}
	return (ret);
}

static int	is_valid_character(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else if (c == '1' || c == '0')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

static int	get_qtt_blk(int *x, int *y, char *map)
{
	int	i;
	int	l_x;
	int	l_y;
	int	sum;

	i = 0;
	l_x = 0;
	l_y = 0;
	sum = 0;
	while (map[i])
	{
		if (is_valid_character(map[i]))
		{
			l_x++;
			sum++;
		}
		else if(map[i] == '\n')
		{
			if (l_x > *x)
				*x = l_x;
			l_x = 0;
			l_y++;
		}
		i++;
	}
	*y = l_y;
	return (sum);
}

static unsigned long	ft_rgb_to_hex(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static int	load_textures(t_data *data, char *str, char dir)
{
	int	i;

	if (dir == 'N')
		i = 0;
	if (dir == 'S')
		i = 1;
	if (dir == 'E')
		i = 2;
	if (dir == 'W')
		i = 3;
	data->textures[i] = ft_strdup(str);
	if (!data->textures[i])
		return (0);
	data->txt_ok = 1;
	return (1);
}

static int	load_color_cf(t_data *data, char *str, char place)
{
	t_col	c;
	int		i;

	i = 0;
	c.col = malloc (sizeof (char *) * 4);
	while(str[i])
	{
		while (str[i] < '0' || str[i] > '9')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			c.col = ft_split(str + i, ',');
		break ;
	}
	c.r = ft_atoi(c.col[0]);
	c.g = ft_atoi(c.col[1]);
	c.b = ft_atoi(c.col[2]);
	if (place == 'C')
		data->color_c = ft_rgb_to_hex(c.r, c.g, c.b);
	else if (place == 'F')
		data->color_f = ft_rgb_to_hex(c.r, c.g, c.b);
	if (data->color_c == 0)
		data->color_c = 1;
	if (data->color_f == 0)
		data->color_f = 1;
	data->col_ok = 1;
	return (1);
}

int	config_loader(t_data *data, int *fd, char **map)
{
	char	*tmp;
	int		i;

	tmp = get_next_line(*fd);
	while (tmp)
	{
		i = 0;
		while (tmp[i] == ' ')
			i++;
		if (tmp[i] == '\n')
		{}
		else if ((tmp[i] == 'N' || tmp[i] == 'S' || tmp[i] == 'W' || tmp[i] == 'E'))
			load_textures(data, tmp, tmp[i]);
		else if ((tmp[i] == 'F' || tmp[i] == 'C'))
			load_color_cf(data, tmp, tmp[i]);
		else
		{
			*map = ft_strdup(tmp);
			free (tmp);
			return (1);
		}
		free(tmp);
		tmp = get_next_line(*fd);
	}
	return (0);
}

int	map_loader(t_data *data, int *fd, char **map)
{
	char	*tmp;
	int		s_tmp;
	char	*tmp2;
	int		s_tmp2;

	tmp = ft_strdup(*map);
	data->map = NULL;
	while (tmp)
	{
		if (!data->map)
			data->map = ft_strdup(tmp);
		else
		{
			tmp2 = ft_strdup(data->map);
			free(data->map);
			s_tmp = ft_strlen(tmp);
			s_tmp2 = ft_strlen(tmp2);
			data->map = malloc(sizeof (char) * (s_tmp + s_tmp2) + 1);
			data->map = ft_strjoin(tmp2, tmp);
		}
		free(tmp);
		tmp = get_next_line(*fd);
	}
	return (1);
}

int	config_file_loader(t_data *data)
{
	int		fd;
	char	*map_name;
	char	*map;

	map_name = ft_strjoin("./src/maps/", data->map_name);
	fd = open (map_name, O_RDONLY);
	free (map_name);
	if (fd < 0)
		return (map_error());
	if (!config_loader(data, &fd, &map))
		return (map_error());
	if (!map_loader(data, &fd, &map))
		return (map_error());
	data->blocks_nbr = get_qtt_blk(&data->map_size[0], &data->map_size[1], data->map);
	data->map_lined = remove_lnbrk(data, data->map);
	show_map(data->map);
	write(1, "\n\n", 2);
	show_map(data->map_lined);
/* 	if (!parse_config_file(data))
		return (map_error()); */
	return (1);
}