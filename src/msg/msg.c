/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:22:13 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/04/29 19:41:09 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	config_loaded(void)
{
	ft_printf(GREEN);
	ft_printf("\nConfigurations Loaded Succesfully!\n");
	ft_printf(WHITE);
}

int	invalid_config(void)
{
	ft_printf(RED);
	ft_printf("\nWrong parameters! Configurations not loaded. Terminating program...\n");
	ft_printf(WHITE);
	return (-1);
}

void	mlx_initialized(void)
{
	ft_printf(GREEN);
	ft_printf("\nMLX Initialized Succesfully!\n");
	ft_printf(WHITE);
}

void	screen_initialized(void)
{
	ft_printf(GREEN);
	ft_printf("\nScreen Initialized Succesfully!\n");
	ft_printf(WHITE);
}

void	img_initialized(void)
{
	ft_printf(GREEN);
	ft_printf("\nImg Initialized Succesfully!\n");
	ft_printf(WHITE);
}

void	square_drawn(void)
{
	ft_printf(GREEN);
	ft_printf("\nSquare Drawn!\n");
	ft_printf(WHITE);
}

void	hook_got(int key)
{
	ft_printf(GREEN);
	ft_printf("\n%d Got\n", key);
	ft_printf(WHITE);
}

void	refreshed(void)
{
	ft_printf(GREEN);
	ft_printf("\nRefreshed!\n");
	ft_printf(WHITE);
}

void	show_dataxy(t_data *data)
{
	ft_printf(GREEN);
	ft_printf("\n>>>>>>SHOWING DATA PARAMS<<<<<<\n");
	ft_printf("data->initial_x = %d\n", data->initial_x);
	ft_printf("data->initial_y = %d\n", data->initial_y);
	ft_printf("data->size_x = %d\n", data->size_x);
	ft_printf("data->size_y = %d\n", data->size_y);
	ft_printf(WHITE);
}

int	open_error(int fd)
{
	ft_printf(RED);
	ft_printf("\nOpen map error, exit code: %d\n", fd);
	ft_printf(WHITE);
	return (-1);
}

void	show_map(char *map)
{
	ft_printf(YELLOW);
	ft_printf("Current map:\n%s\n", map);
	ft_printf(WHITE);
}

int	map_error(void)
{
	ft_printf(RED);
	ft_printf("\nFailed to read the map\n");
	ft_printf(WHITE);
	return (-1);
}

void	map_loaded(char *str)
{
	ft_printf(GREEN);
	ft_printf("\nMap \e[033m %s \e[00m Loaded!\n", str);
	ft_printf(WHITE);
}

void	show_map_nbrs(t_data *data)
{
	ft_printf(BLUE);
	ft_printf("\nMap X: %d\n", data->map_size[0]);
	ft_printf("Map Y: %d\n", data->map_size[1]);
	ft_printf("Map Blocks: %d\n", data->blocks_nbr);
	ft_printf(WHITE);
}

void	show_map_nbr(char *map)
{
	int i, j;
	i = 1;
	j = -1;
	ft_printf("  ");
	while (map[i + j])
	{
		if (map[i + j] == ' ')
		{
			j++;
		}
		else if (map[i + j] == '\n')
		{
			ft_printf("%c", map[i + j]);
			j++;
		}
		else
		{
			ft_printf("%d ", i);
			i++;
		}
		if (i < 10)
			ft_printf("  ");
		else if (i >= 10 && i < 100)
			ft_printf(" ");
	}
}

int	txt_fail(void)
{
	ft_printf(RED);
	ft_printf("Texture load error\n");
	ft_printf(WHITE);
	return (0);
}

int	col_fail(void)
{
	ft_printf(RED);
	ft_printf("Texture load error\n");
	ft_printf(WHITE);
	return (0);
}

int	map_error_here(int index)
{
	ft_printf(RED);
	ft_printf("Map error at data->map[%d]", index);
	ft_printf(WHITE);

	return (0);
}

void	show_map_array(char **map, int	ln)
{
	int	i;

	i = 0;
	while (i <= ln)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}