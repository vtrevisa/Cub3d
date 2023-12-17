/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:22:13 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/12/17 14:51:42 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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