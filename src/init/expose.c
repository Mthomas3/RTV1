/*
** expose.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/init
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:07:04 2015 Thomas Martins
** Last update Sun Mar 15 14:47:00 2015 Thomas Martins
*/

#include "../struct.h"

int     expose(t_glob *glob)
{
  IMG_TOWIN(glob->par->mlx_ptr, glob->par->win_ptr,
	    glob->par->d_pix->pixel, 0, 0);
  return (0);
}
