/*
** mlx_destroy_image.c for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Tue Mar 12 10:25:15 2002 Charlie Root
** Last update Tue May 15 16:45:54 2007 Olivier Crouzet
*/


#include	"mlx_int.h"


int	mlx_destroy_image(t_xvar *xvar, t_img *img)
{
  if (data->type == MLX_TYPE_SHM_PIXMAP ||
      data->type == MLX_TYPE_SHM)
    {
      XShmDetach(xvar->display, &(data->shm));
      shmdt(data->shm.shmaddr);
      /* shmctl IPC_RMID already done */
    }
  XDestroyImage(data->image);  /* For image & shm-image. Also free data->data */
  XFreePixmap(xvar->display, data->pix);
  if (data->gc)
    XFreeGC(xvar->display, data->gc);
  free(img);
  if (xvar->do_flush)
    XFlush(xvar->display);
}
