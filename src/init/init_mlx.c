/*
** init_mlx.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/init
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:07:25 2015 Thomas Martins
** Last update Sun Mar 15 19:44:22 2015 Thomas Martins
*/

#include "../struct.h"

int     init_mlx(t_glob *glob)
{
  if (!(glob->par->mlx_ptr = INIT()))
    check_init(glob);
  glob->par->d_pix->pixel = NEW_IMG(glob->par->mlx_ptr,
				    glob->par->width, glob->par->height);
  glob->pix->mat = GET_DATA(glob->par->d_pix->pixel, &(glob->pix->bpp),
			    &(glob->pix->sizeline), &(glob->pix->endian));
  if (!(glob->par->win_ptr = NEW_WIN(glob->par, "Ray_One")))
    check_windows(glob);
  return (0);
}

