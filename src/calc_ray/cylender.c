/*
** cylender.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/calc_ray
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:05:06 2015 Thomas Martins
** Last update Sun Mar 15 09:05:23 2015 Thomas Martins
*/

#include "../struct.h"

float	my_cylender(t_vec *vec, float ray)
{
  float	a;
  float	b;
  float	c;
  t_vec	oc;

  oc.px = vec->px - XCYLENDER;
  oc.py = vec->py - YCYLENDER;
  oc.pz = vec->pz - ZCYLENDER;
  a = pow(vec->vx, 2) + pow(vec->vz, 2);
  b = 2.0 * (oc.px * vec->vx + oc.pz * vec->vz);
  c = pow(oc.px, 2) + pow(oc.pz, 2) - pow(ray, 2);
  return (solve_quadric(a, b, c));
}

float	my_cylender_two(t_vec *vec, float ray)
{
  float	a;
  float	b;
  float	c;
  t_vec	oc;

  oc.px = vec->px - XCYL;
  oc.py = vec->py - YCYL;
  oc.pz = vec->pz - ZCYL;
  a = pow(vec->vx, 2) + pow(vec->vz, 2);
  b = 2.0 * (oc.px * vec->vx + oc.pz * vec->vz);
  c = pow(oc.px, 2) + pow(oc.pz, 2) - pow(ray, 2);
  return (solve_quadric(a, b, c));
}
