/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_p2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:56:56 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/11 19:00:56 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	error_msg(char *msg)
{
	printf(RED);
	printf("Error\n");
	printf(WHITE);
	printf(RED);
	printf("%s", msg);
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
