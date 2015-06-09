/*
** put_pixel.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/basic
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:04:11 2015 Thomas Martins
** Last update Sun Mar 15 09:04:14 2015 Thomas Martins
*/

#include "../struct.h"

int	my_put_pixel_to_image(t_glob *glob, int x, int y, int color)
{
  int	a;
  int	b;
  int	c;
  int	d;

  if (x < 0 || y >= 1000 || y < 0 || x >= 1000)
    return (-1);
  d = x * glob->pix->bpp / 8 + y * glob->pix->sizeline;
  a = (color >> 16) & 255;
  b = (color >> 8) & 255;
  c = color & 255;
  glob->pix->mat[d + 0] = c;
  glob->pix->mat[d + 1] = b;
  glob->pix->mat[d + 2] = a;
  return (0);
}
