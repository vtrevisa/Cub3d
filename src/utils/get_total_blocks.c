/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_total_blocks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:12:02 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/11 18:52:14 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	is_valid_character(char c)
{
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E')
		|| (c == '1' || c == '0') || (c == ' '))
		return (1);
	return (0);
}

int	get_total_blocks_map(int *max_width, int *max_height, char *map)
{
	int	index;
	int	current_line_width;
	int	total_lines;
	int	total_blocks;

	index = -1;
	current_line_width = 0;
	total_lines = 0;
	total_blocks = 0;
	while (index++, map[index])
	{
		if (is_valid_character(map[index]) && current_line_width++)
			total_blocks++;
		else if (map[index] == '\n')
		{
			if (current_line_width > *max_width)
				*max_width = current_line_width;
			current_line_width = 0;
			total_lines++;
		}
	}
	if (map[index] == '\0' && map[index - 1] != '\n')
		total_lines += 1;
	*max_height = total_lines;
	return (total_blocks);
}
