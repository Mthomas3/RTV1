/*
** calc_image.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/calc_img
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:04:27 2015 Thomas Martins
** Last update Sun Mar 15 14:51:17 2015 Thomas Martins
*/

#include "../struct.h"

int	get_inter(t_glob *glob, t_vec *v, float *rest, t_img *img)
{
  if (img->tsph > 0.0)
    {
      *rest = img->tsph;
      img->id = COLSPHERE;
    }
  if (img->t_sphere_two > 0.0 && img->t_sphere_two < *rest)
    {
      *rest = img->t_sphere_two;
      img->id = COLSPHERETWO;
    }
  if (img->tcyl > 0.0 && img->tcyl < *rest)
    {
      *rest = img->tcyl;
      img->id = COLCYLENDER;
    }
  if (img->t_cyl_two > 0.0 && img->t_cyl_two < *rest)
    {
      *rest = img->t_cyl_two;
      img->id = COLCYLTWO;
    }
  img->id = get_inters(glob, v, rest, img);
  return (img->id);
}

int	get_inters(t_glob *glob, t_vec *vec, float *rest, t_img *img)
{
  if (img->t_sphere_mid > 0.0 && img->t_sphere_mid < *rest)
    {
      *rest = img->t_sphere_mid;
      img->id = COLSPHEREMID;
    }
  if (img->tcon > 0.0 && img->tcon < *rest)
    {
      *rest = img->tcon;
      img->id = COLCONE;
    }
  if (img->tplane > 0.0 && img->tplane < *rest)
    {
      *rest = img->tplane;
      img->id = COLPLANE;
    }
  if (img->t_wall_one > 0.0 && img->t_wall_one < *rest)
    {
      *rest = img->t_wall_one;
      img->id = COLWALL;
    }
  return (img->id);
}

int	calc_image(t_glob *glob, t_vec *v, float *rest)
{
  t_img	img;

  img.id = -1;
  img.tsph = my_sphere(glob->vec, RSPHERE);
  img.tcyl = my_cylender(glob->vec, RCYLENDER);
  img.tcon = my_cone(glob->vec, RCONE);
  img.tplane = my_plane(glob->vec, DPLANE);
  img.t_wall_one = my_first_wall(glob->vec, DWALL);
  img.t_cyl_two = my_cylender_two(glob->vec, RCYL);
  img.t_sphere_two = my_sphere_two(glob->vec, RSPHERETWO);
  img.t_sphere_mid = my_sphere_mid(glob->vec, RSPHEREMID);
  img.id = get_inter(glob, v, rest, &img);
  return (img.id);
}
