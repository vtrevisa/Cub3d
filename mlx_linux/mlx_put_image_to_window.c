/*
** mlx_put_image_to_window.c for MiniLibX in raytraceur
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Aug 14 15:55:49 2000 Charlie Root
** Last update Sun Oct  2 09:53:00 2005 Olivier Crouzet
*/



#include	"mlx_int.h"


int	mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img,
				int x,int y)
{
  GC	gc;

  gc = win->gc;
  if (data->gc)
    {
      gc = data->gc;
      XSetClipOrigin(xvar->display, gc, x, y);
    }
  if (data->type==MLX_TYPE_SHM)
    XShmPutImage(xvar->display,data->pix, win->gc, data->image,0,0,0,0,
		 data->width,data->height,False);
  if (data->type==MLX_TYPE_XIMAGE)
    XPutImage(xvar->display,data->pix, win->gc, data->image,0,0,0,0,
	      data->width,data->height);
  XCopyArea(xvar->display,data->pix,win->window, gc,
	    0,0,data->width,data->height,x,y);
  if (xvar->do_flush)
    XFlush(xvar->display);
}
