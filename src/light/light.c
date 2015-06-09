/*
** light.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/light
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:09:11 2015 Thomas Martins
** Last update Sun Mar 15 22:02:35 2015 Thomas Martins
*/

#include "../struct.h"

int		color_light(int r, int g, int b)
{
  if (r < 0)
    r = 0;
  else if (r > 255)
    r = 255;
  if (g < 0)
    g = 0;
  else if (g > 255)
    g = 255;
  if (b < 0)
    b = 0;
  else if (b > 255)
    b = 255;
  return (b << 16 | g << 8 | r);
}

int		my_ambiance(int color)
{
  int		r;
  int		g;
  int		b;

  r = color & 0xFF;
  b = ((color >> 16) & 0xFF);
  g = ((color >> 8) & 0xFF);
  r *= LIGHT_AMB;
  g *= LIGHT_AMB;
  b *= LIGHT_AMB;
  return (b << 16 | g << 8 | r);
}

int		my_lum(t_vec *vec, int color)
{
  int		amb;
  t_light	light;

  light.scalaire = (vec->px * vec->lx)
    + (vec->py * vec->ly) + (vec->pz * vec->lz);
  light.normal = sqrt(pow(vec->px, 2) + pow(vec->py, 2) + pow(vec->pz, 2));
  light.normal_lum = sqrt(pow(vec->lx, 2) + pow(vec->ly, 2) + pow(vec->lz, 2));
  if (light.normal != 0.0 && light.normal_lum != 0.0)
    light.cosa = (light.scalaire / (light.normal * light.normal_lum));
  light.cosa = 1 - light.cosa;
  if (light.cosa <= 0)
    return (-1);
  amb = my_ambiance(color);
  color = color * (1.0 - SHINE) + COL_SPOT * SHINE;
  color = color_light(light.cosa * (color & 0xFF),
		      light.cosa * ((color >> 8) & 0xFF),
		      light.cosa * ((color >> 16) & 0xFF));
  light.new_color = color_light((amb & 0xFF) + (color & 0xFF),
				((amb >> 8) & 0xFF) + ((color >> 8) & 0xFF),
				((amb >> 16) & 0xFF) + ((color >> 16) & 0xFF));
  return (light.new_color);
}

void		vec_lum(t_glob *glob)
{
  glob->vec->px += glob->vec->vx * glob->pix->k;
  glob->vec->py += glob->vec->vy * glob->pix->k;
  glob->vec->pz += glob->vec->vz * glob->pix->k;
  glob->vec->lx = glob->vec->px - XLIGHT;
  glob->vec->ly = glob->vec->py - YLIGHT;
  glob->vec->lz = glob->vec->pz - ZLIGHT;
}
