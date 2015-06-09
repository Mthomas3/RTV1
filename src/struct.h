/*
** struct.h for  in /home/mart_4/rendu/TestPiscine/Raytracer/parsing
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sat Feb 21 23:13:43 2015 Thomas Martins
** Last update Sun Mar 15 19:41:30 2015 Thomas Martins
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/Xlib.h>
# include <mlx.h>
# include <math.h>
# include "../init.h"

# define NEW_WIN(X, Y)  mlx_new_window((X)->mlx_ptr, (X)->width, (X)->height, Y)
# define INIT		mlx_init
# define NEW_IMG	mlx_new_image
# define GET_DATA	mlx_get_data_addr
# define LOOP		mlx_loop
# define IMG_TOWIN	mlx_put_image_to_window
# define HOOK		mlx_hook
# define SIZE		1

typedef struct	s_pixel	t_pixel;
typedef struct	s_param	t_param;
typedef struct	s_global t_glob;
typedef struct	s_vec	t_vec;
typedef struct	s_light	t_light;
typedef struct	s_calc	t_img;
typedef struct	s_print	t_print;

struct			s_pixel
{
  int			*pixel;
  char			*mat;
  int			bpp;
  int			sizeline;
  int			endian;
  int			color;
  float			k;
};

struct			s_vec
{
  float			vx;
  float			vy;
  float			vz;
  float			px;
  float			py;
  float			pz;
  float			lx;
  float			ly;
  float			lz;
  float			sx;
  float			sy;
  float			sz;
};

struct			s_param
{
  void			*mlx_ptr;
  void			*win_ptr;
  t_pixel		*d_pix;
  int			width;
  int			height;
};

struct			s_light
{
  float			scalaire;
  float			normal;
  float			normal_lum;
  float			cosa;
  int			new_color;
};

struct			s_global
{
  t_light		*lig;
  t_vec			*vec;
  t_param		*par;
  t_pixel		*pix;
};

struct			s_calc
{
  int			id;
  float			tsph;
  float			tcyl;
  float			tcon;
  float			tplane;
  float			t_wall_one;
  float			t_wall_two;
  float			t_cyl_two;
  float			t_sphere_two;
  float			t_sphere_mid;
};

struct			s_print
{
  int			x;
  int			y;
  int			color;
  int			id;
  float			t;
  int			lock;
  int			cpt;
};

void			check_init(t_glob *glob);
void			check_windows(t_glob *glob);
int			init_mlx(t_glob *glob);
int			key_bind(int key, t_glob *glob);
int			expose(t_glob *glob);
int			init_struct(t_glob *glob);
void			end_of_free(t_glob *glob);
float			solve_quadric(float a, float b, float c);
int			get_inter(t_glob *glob, t_vec *v, float *rest, t_img *img);
int			get_inters(t_glob *glob, t_vec *v, float *rest, t_img *img);
float			my_plane(t_vec *vec, float dplane);
float			my_first_wall(t_vec *vec, float dplane);
float			my_sphere(t_vec *vec, float ray);
float			my_sphere_two(t_vec *vec, float ray);
float			my_sphere_mid(t_vec *vec, float ray);
float			my_cylender(t_vec *vec, float ray);
float			my_cylender_two(t_vec *vec, float ray);
float			my_cone(t_vec *vec, float angle);
t_vec			*rotate_x(t_vec *vec, float angle);
t_vec			*rotate_y(t_vec *vec, float angle);
t_vec			*rotate_z(t_vec *vec, float angle);
t_vec			*init_look(t_vec *vec, int x, int y);
int			get_color(t_glob *glob, float t, int id);
int			my_image(t_glob *glob);
int			calc_image(t_glob *glob, t_vec *v, float *rest);
int			my_put_pixel_to_image(t_glob *glob, int x, int y, int color);
int			color_light(int r, int g, int b);
int			my_lum(t_vec *vec, int color);
void			vec_lum(t_glob *glob);

#endif
