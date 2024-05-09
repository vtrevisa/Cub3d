/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:13:20 by r-afonso          #+#    #+#             */
/*   Updated: 2024/05/08 21:13:42 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_p_angle(char dir)
{
	if (dir == 'N')
		return (3);
	if (dir == 'S')
		return (1);
	if (dir == 'E')
		return (0);
	if (dir == 'W')
		return (2);
	return (0);
}