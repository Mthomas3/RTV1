/*
** put_image.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/calc_img
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:04:40 2015 Thomas Martins
** Last update Sun Mar 15 22:07:22 2015 Thomas Martins
*/

#include "../struct.h"

int		get_color(t_glob *glob, float t, int id)
{
  if (id < 0)
    return (-1);
  glob->pix->k = t;
  if (XLIGHT == 0.0 && YLIGHT == 0.0 && ZLIGHT == 0.0)
    return (0x000033);
    vec_lum(glob);
  return (my_lum(glob->vec, id));
}

void		print_image(int x, int y)
{
  int		result;

  my_putstr("\033[0G");
  result = ((y + x * 1000) * 100) / (1000 * 1000);
  my_putnbr(result);
  my_putstr("%");
}

int		my_image(t_glob *glob)
{
  t_print	print;

  print.x = -1;
  my_putstr("please wait ...\n");
  while (++print.x < 1000)
    {
      print.y = -1;
      while (++print.y < 1000)
	{
	  init_look(glob->vec, print.x, print.y);
	  print.color = 0;
	  print.t = 1000.0;
	  print.id = calc_image(glob, glob->vec, &print.t);
	  if (print.t > 0.0 && print.id > 0)
	    print.color = get_color(glob, print.t, print.id);
	  my_put_pixel_to_image(glob, print.x, print.y, print.color);
	}
      print_image(print.x, print.y);
    }
  my_putstr("\n");
  return (0);
}
