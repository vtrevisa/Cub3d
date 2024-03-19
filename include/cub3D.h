/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:40:53 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/03/19 14:44:40 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//FOR TEST
#include <stdio.h>

#include "../mlx_linux/mlx_int.h"
#include "../mlx_linux/mlx.h"
#include "../Libft/Include/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#define WHITE "\e[00m"
#define GREEN "\e[32m"
#define RED "\e[91m"
#define YELLOW "\e[033m"
#define BLUE "\e[34m"
#define PI 3.14159265359


/* 	x and y -> pixels to be painted
	size_x and y -> how many pixels will be painted
	img_x and y -> initial poition of the pixels to be painted 
*/

typedef struct s_data
{
	//MAP CREATION
	int	initial_x;
	int	initial_y;
	int	size_x;
	int	size_y;
	int	x;
	int	y;
	//MLX PARAMETERS
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	void	*mlx;
	void	*win;
	//DONT REMMEBER WHAT IT IS
	int		max_x;
	int		max_y;
	//MAP INFO
	char	*map_name;
	char	*map;
	char	*map_lined;
	int		map_size[2];
	int		blocks_nbr;
	int		flag; //char if 1 plaer pos
	char	upg;
	//PLAYER POSITION AND MOVEMENT
	int		player_x;
	int		player_y;
	float	p_deltX;
	float	p_deltY;
	float	p_angle;
	char 	player_dir;
	//RAY_CAST INFO
	int		ray, mx, my, mp, dof;
	float	ray_x, ray_y, r_angle, rx_offset, ry_offset;
}	t_data;

//--MAP--
void	draw_map(t_data *data);
void	draw_background (t_data *data);
void	draw_quadrilaters(int initial_x, int initial_y, int size_x, int size_y, t_data *data, int color);
void	draw_player(t_data *data);
void	dda(int x1, int x2, int y1, int y2, int color, t_data *data);

//--INIT--
int	init_mlx(t_data *data, int argc, char **argv);

//--MSG--
void	config_loaded(void);
int		invalid_config(void);
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
void	map_loaded(char *str);
void	show_map_nbrs(t_data *data);
void	show_map_nbr(char *map);

//--SYSTEM--
void	display(t_data *data);
void	get_hook(t_data *data);
void	drawRays3D (t_data *data);

//--UTILS--
void	refresh(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_strlen_spaceless(const char *s);
int		map_reader(t_data *data);