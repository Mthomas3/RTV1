/*
** sphere.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/calc_ray
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:06:38 2015 Thomas Martins
** Last update Sun Mar 15 09:06:52 2015 Thomas Martins
*/

#include "../struct.h"

float	my_sphere(t_vec *vec, float ray)
{
  float	a;
  float	b;
  float	c;
  t_vec	oc;

  oc.px = vec->px - XSPHERE;
  oc.py = vec->py - YSPHERE;
  oc.pz = vec->pz - ZSPHERE;
  a = pow(vec->vx, 2) + pow(vec->vy, 2) + pow(vec->vz, 2);
  b = 2.0 * (oc.px * vec->vx + oc.py * vec->vy + oc.pz * vec->vz);
  c = pow(oc.px, 2) + pow(oc.py, 2) + pow(oc.pz, 2) - pow(ray, 2);
  return (solve_quadric(a, b, c));
}

float	my_sphere_two(t_vec *vec, float ray)
{
  float	a;
  float	b;
  float	c;
  t_vec	oc;

  oc.px = vec->px - XSPHERETWO;
  oc.py = vec->py - YSPHERETWO;
  oc.pz = vec->pz - ZSPHERETWO;
  a = pow(vec->vx, 2) + pow(vec->vy, 2) + pow(vec->vz, 2);
  b = 2.0 * (oc.px * vec->vx + oc.py * vec->vy + oc.pz * vec->vz);
  c = pow(oc.px, 2) + pow(oc.py, 2) + pow(oc.pz, 2) - pow(ray, 2);
  return (solve_quadric(a, b, c));
}

float	my_sphere_mid(t_vec *vec, float ray)
{
  float	a;
  float	b;
  float	c;
  t_vec	oc;

  oc.px = vec->px - XSPHEREMID;
  oc.py = vec->py - YSPHEREMID;
  oc.pz = vec->pz - ZSPHEREMID;
  a = pow(vec->vx, 2) + pow(vec->vy, 2) + pow(vec->vz, 2);
  b = 2.0 * (oc.px * vec->vx + oc.py * vec->vy + oc.pz * vec->vz);
  c = pow(oc.px, 2) + pow(oc.py, 2) + pow(oc.pz, 2) - pow(ray, 2);
  return (solve_quadric(a, b, c));
}
