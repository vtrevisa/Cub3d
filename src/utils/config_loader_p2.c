/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_loader_p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:42:02 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/11 21:14:07 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

unsigned long	ft_rgb_to_hex(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	check_texture_path(t_data *data, char *str, char texture_index)
{
	if (texture_index == 'N' && !data->textures[0])
		return ((data->textures[0] = ft_strdup(str)), 1);
	if (texture_index == 'S' && !data->textures[1])
		return ((data->textures[1] = ft_strdup(str)), 2);
	if (texture_index == 'E' && !data->textures[2])
		return ((data->textures[2] = ft_strdup(str)), 3);
	if (texture_index == 'W' && !data->textures[3])
		return ((data->textures[3] = ft_strdup(str)), 4);
	return (-1);
}

int	load_textures(t_data *data, char *str)
{
	int		index;
	int		result;
	char	*trimmed;

	index = 2;
	result = -1;
	if ((str[0] == 'N' && str[1] == 'O') || (str[0] == 'S' && str[1] == 'O')
		|| (str[0] == 'W' && str[1] == 'E')
		|| (str[0] == 'E' && str[1] == 'A'))
	{
		while (str[index] == ' ')
			index++;
		trimmed = ft_strtrim(str + index, "\n");
		result = check_texture_path(data, trimmed, str[0]);
		free(trimmed);
		data->txt_ok += 1;
	}
	if (result < 0)
		return (-1);
	return (1);
}
