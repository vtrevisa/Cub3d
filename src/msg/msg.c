/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:22:13 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/11 19:00:10 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
