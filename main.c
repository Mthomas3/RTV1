/*
** main.c for  in /home/mart_4/rendu/MUL_2014_rtv1
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:10:20 2015 Thomas Martins
** Last update Sun Mar 15 19:37:14 2015 Thomas Martins
*/

#include "src/struct.h"

int		gere_all(t_glob *glob)
{
  HOOK(glob->par->win_ptr, KeyPress, KeyPressMask, key_bind, glob);
  mlx_expose_hook(glob->par->win_ptr, &expose, glob);
  mlx_loop(glob->par->mlx_ptr);
}

int		init_struct(t_glob *glob)
{
  if ((glob->par = malloc(sizeof(t_param))) == NULL)
    return (-1);
  if ((glob->pix = malloc(sizeof(t_pixel))) == NULL)
    return (-1);
  if ((glob->par->d_pix = malloc(sizeof(t_pixel))) == NULL)
    return (-1);
  if ((glob->vec = malloc(sizeof(t_vec))) == NULL)
    return (-1);
  if ((glob->lig = malloc(sizeof(t_light))) == NULL)
    return (-1);
  return (0);
}

void		end_of_free(t_glob *glob)
{
  if (glob->par != NULL)
    free(glob->par);
  if (glob->pix != NULL)
    free(glob->pix);
  if (glob->vec != NULL)
    free(glob->vec);
  if (glob->lig != NULL)
    free(glob->lig);
  if (glob != NULL)
    free(glob);
}

int		main(int ac, char **av, char **env)
{
  t_glob	*glob;

  (void)ac;
  (void)av;
  if (!*env)
    fail_env();
  if ((glob = malloc(sizeof(t_glob))) == NULL)
    return (1);
  if ((init_struct(glob)) < 0)
    return (1);
  glob->par->width = 1000;
  glob->par->height = 1000;
  if ((init_mlx(glob)) < 0)
    return (1);
  my_image(glob);
  gere_all(glob);
  return (0);
}
