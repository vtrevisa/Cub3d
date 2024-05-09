/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:43:21 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/08 16:54:44 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	compare_strings(char *str1, char *str2)
{
	if (ft_strlen(str1) != ft_strlen(str2))
		return (1);
	if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0)
		return (0);
	return (1);
}
