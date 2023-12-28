/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:40:53 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/12/28 20:54:41 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx_int.h"
#include "../mlx_linux/mlx.h"
#include "../Libft/Include/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define WHITE "\e[00m"
#define GREEN "\e[32m"
#define RED "\e[91m"
#define YELLOW "\e[033m"
#define BLUE "\e[34m"

/* 	x and y -> pixels to be painted
	size_x and y -> how many pixels will be painted
	img_x and y -> initial poition of the pixels to be painted 
*/

typedef struct s_data
{
	int	initial_x;
	int	initial_y;
	int	size_x;
	int	size_y;
	int	x;
	int	y;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	void	*mlx;
	void	*win;

	int		max_x;
	int		max_y;
	
	char	*map;
	int		map_size[2];
	int		blocks_nbr;
}	t_data;

//--MAP--
void	draw_map(t_data *data);
void	draw_square(int initial_x, int initial_y, int size_x, int size_y, t_data *data, int color);

//--INIT--
int	init_mlx(t_data *data, int argc, char **argv);

//--MSG--
void	config_loaded(void);
void	mlx_initialized(void);
void	screen_initialized(void);
void	img_initialized(void);
void	square_drawn(void);
void	hook_got(int key);
void	refreshed(void);
void	show_dataxy(t_data *data);
int		open_error(int fd);
void	show_map(char *map);
int		map_error(void);
void	map_loaded(void);
void	show_map_nbrs(t_data *data);

//--SYSTEM--
void	get_hook(t_data *data);

//--UTILS--
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	refresh(t_data *data);
int		map_reader(t_data *data);