/*
** rotate_x.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/translation
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:09:24 2015 Thomas Martins
** Last update Sun Mar 15 16:14:59 2015 Thomas Martins
*/

#include "../struct.h"

t_vec	*rotate_x(t_vec *vec, float angle)
{
  float	c;
  float	s;
  float	len;

  c = cos((angle) * M_PI / 180.0);
  s = sin((angle) * M_PI / 180.0);
  vec->vy = vec->vy * c + vec->vz * -s;
  vec->vz = vec->vy * s + vec->vz * c;
  return (vec);
}
