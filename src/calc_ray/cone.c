/*
** cone.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/calc_ray
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:04:57 2015 Thomas Martins
** Last update Sun Mar 15 09:05:23 2015 Thomas Martins
*/

#include "../struct.h"

float	my_cone(t_vec *vec, float angle)
{
  float	a;
  float	b;
  float	c;
  t_vec	oc;

  oc.px = vec->px - XCONE;
  oc.py = vec->py - YCONE;
  oc.pz = vec->pz - ZCONE;
  a = pow(vec->vx, 2) + pow(vec->vz, 2) - (pow(vec->vy, 2) * angle);
  b = 2.0 * (oc.px * vec->vx + oc.pz * vec->vz - angle * oc.py * vec->vy);
  c = pow(oc.px, 2) + pow(oc.pz, 2) - pow(oc.py, 2) * angle;
  return (solve_quadric(a, b, c));
}
