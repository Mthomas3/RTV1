/*
** eyes.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/calc_ray
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:05:12 2015 Thomas Martins
** Last update Sun Mar 15 21:52:44 2015 Thomas Martins
*/

#include "../struct.h"

t_vec	*init_look(t_vec *vec, int x, int y)
{
  float	len;
  float	e;

  e = tan(30.0 * M_PI / 180.0);
  vec->vx = (-1.0 + 2.0 * (x / 1000.0)) * e;
  vec->vy = (-1.0 + 2.0 * (y / 1000.0)) * e;
  vec->vz = -1.0;
  len = sqrt(pow(vec->vx, 2) + pow(vec->vy, 2) + 1.0);
  if (len != 0.0)
    {
      vec->vx /= len;
      vec->vy /= len;
      vec->vz /= len;
    }
  vec->px = XEYE;
  vec->py = YEYE;
  vec->pz = ZEYE;
  vec = rotate_z(vec, ZANGLE);
  vec = rotate_y(vec, YANGLE);
  vec = rotate_x(vec, XANGLE);
  return (vec);
}
