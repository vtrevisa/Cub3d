/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:40:53 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/06 16:31:04 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/Include/libft.h"
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#define WHITE "\e[00m"
#define GREEN "\e[32m"
#define RED "\e[91m"
#define YELLOW "\e[033m"
#define BLUE "\e[34m"
#define PI 3.141592
#define P2 PI / 2
#define P3 3 * PI / 2
#define DR 0.0174533
#define W 119
#define S 115
#define D 100
#define A 97
#define ARROW_L 65361
#define ARROW_R 65363

typedef struct s_col
{
	int				r;
	int				g;
	int				b;
	char			**col;
	char			tmp;
}					t_col;

typedef struct s_ray //2 screen
{
	int max_view;
	double aTan;
	double nTan;
	int color;
	double ca;
	double lineH;
	double lineO;
	int ray_width;
	int r;
	int mx;
	int my;
	int mp;
	int dof;
	int hx;
	int hy;
	int vx;
	int vy;
	double rx;
	double ry;
	double ra;
	double xo;
	double yo;
	double disH;
	double disV;
	double disT;
}					t_ray;

typedef struct s_draw
{
	int				initial_x;
	int				initial_y;
	int				size_x;
	int				size_y;
	int				color;
}					t_draw;

typedef struct s_data
{
	int				initial_x;
	int				initial_y;
	int				size_x;
	int				size_y;
	int				cube_size;
	int				x;
	int				y;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
	void			*mlx;
	void			*win;
	int				max_x;
	int				max_y;
	char			*map_name;
	char			*map;
	char			*map_lined;
	char			**map_array;
	char			*line_below;
	int				map_size[2];
	int				blocks_nbr;
	int				flag;
	char			upg;
	int				player_x;
	int				player_y;
	double			p_deltX;
	double			p_deltY;
	double			p_angle;
	char			player_dir;
	void			*textures[4];
	unsigned long	color_c;
	unsigned long	color_f;
	int				col_ok;
	int				txt_ok;
	int				N_S;
	int				E_W;
	int				arrow_r;
	int				arrow_l;
	void			*texture;
	t_ray			ray;
	t_draw			draw;
}					t_data;

void				draw_map(t_data *data);
void				draw_background(t_data *data);
void				draw_quadrilaters(t_data *data);
void				draw_player(t_data *data);
void				dda(int x1, int x2, int y1, int y2, int color,
						t_data *data);
int					init_params(t_data *data, int argc, char **argv);
int					init_mlx(t_data *data);
int					init_map(t_data *data);
void				config_loaded(void);
int					input_error(void);
int					mlx_error(void);
void				mlx_initialized(void);
void				screen_initialized(void);
void				img_initialized(void);
void				square_drawn(void);
void				hook_got(int key);
void				refreshed(void);
void				show_dataxy(t_data *data);
int					open_error(void);
void				show_map(char *map);
int					map_error(void);
void				map_loaded(char *str);
void				show_map_nbrs(t_data *data);
void				show_map_nbr(char *map);
double				dist(t_data *data, double bx, double by);
void				display(t_data *data);
void				get_hook(t_data *data);
void				drawrays3d(t_data *data);
int					map_reader(t_data *data);
void				refresh(t_data *data);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					ft_strlen_spaceless(const char *s);
int					exit_mlx(t_data *data);
int					get_quantity_blocks(int *x, int *y, char *map_name);
char				*cat_map(t_data *data, char **tmp, int fd, int l);
int					config_file_loader(t_data *data);
int					parse_config_file(t_data *data);
int					txt_error(void);
int					col_error(void);
int					map_error_here(int index);
void				show_map_array(char **map, int ln);
int					is_valid_character(char c);
void				drawrays3d_second(t_data *data);
int					wrong_file_name(void);
int					no_player_position(void);