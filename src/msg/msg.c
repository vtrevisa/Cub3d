/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:22:13 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/06 16:44:43 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	error(void)
{
	printf(RED);
	printf("Error\n");
	printf(WHITE);
}

void	error_msg(char *msg)
{
	error();
	printf(RED);
	printf("%s",msg);
	printf(WHITE);
}

int	input_error(void)
{
	error_msg("Passed invalid parameters\n");
	return (-1);
}

int	mlx_error(void)
{
	error_msg("Mlx error\n");
	return (-1);
}

int	open_error(void)
{
	error_msg("Couldn't open the config file\n");
	return (-1);
}

int	map_error(void)
{
	error_msg("Wrong map configuration\n");
	return (-1);
}

int	txt_error(void)
{
	error_msg("Texture load error\n");
	return (-1);
}

int	col_error(void)
{
	error_msg("Color load error\n");
	return (-1);
}

int	wrong_file_name(void)
{
	error_msg("Wrong map file name\n");
	return (-1);
}

int	no_player_position(void)
{
	error_msg("No player start position\n");
	return (-1);
}