/*
** solve_quadric.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/calc_ray
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:06:27 2015 Thomas Martins
** Last update Sun Mar 15 19:42:50 2015 Thomas Martins
*/

#include "../struct.h"

float	solve_quadric(float a, float b, float c)
{
  float	delta;

  delta = b * b - 4.0 * a * c;
  if (delta < 0.001)
    return (-1.0);
  return (fmin((-b - sqrt(delta)) / (2.0 * a),
	       (-b + sqrt(delta)) / (2.0 * a)));
}
