/*
** mlx_get_data_addr.c for MiniLibX in raytraceur
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Aug 14 15:45:57 2000 Charlie Root
** Last update Thu Sep 27 19:05:25 2001 Charlie Root
*/



#include	"mlx_int.h"


char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel,
			   int *size_line,int *endian)
{
  *bits_per_pixel = data->bpp;
  *size_line = data->size_line;
  *endian = data->image->byte_order;
  return (data->data);
}