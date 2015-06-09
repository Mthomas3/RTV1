/*
** wall.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/calc_ray
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:06:47 2015 Thomas Martins
** Last update Sun Mar 15 21:53:28 2015 Thomas Martins
*/

#include "../struct.h"

float   my_first_wall(t_vec *vec, float dplane)
{
  float d;
  float len;
  float x;
  float y;
  float z;
  float d_o;
  float d_r;

  len = sqrt(pow(XWALL, 2) + pow(YWALL, 2) + pow(ZWALL, 2));
  if (len != 0.0)
    {
      x = XWALL / len;
      y = YWALL / len;
      z = ZWALL / len;
    }
  d_o = vec->px * x + vec->py * y + vec->pz * z;
  d_r = vec->vx * x + vec->vy * y + vec->vz * z;
  d = -(d_o + dplane) / d_r;
  if (d < 0.001)
    return (-1.0);
  return (d);
}
