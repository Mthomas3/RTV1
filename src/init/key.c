/*
** key.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/init
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:07:49 2015 Thomas Martins
** Last update Sun Mar 15 19:44:38 2015 Thomas Martins
*/

#include "../struct.h"

int	key_bind(int key, t_glob *glob)
{
  if (key == 65307)
    {
      my_putstr("end of program!\n");
      end_of_free(glob);
      exit(0);
    }
  return (0);
}

