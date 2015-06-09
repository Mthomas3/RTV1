/*
** error.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/basic
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:03:53 2015 Thomas Martins
** Last update Sun Mar 15 09:04:14 2015 Thomas Martins
*/

#include "../struct.h"

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

void	puterror(char *s)
{
  int	a;

  a = 0;
  while (s[a])
    {
      my_putchar_error(s[a]);
      a++;
    }
}

void    check_init(t_glob *glob)
{
  my_putstr("Fail on Init, try again please\n");
  end_of_free(glob);
  exit(0);
}

void    check_windows(t_glob *glob)
{
  my_putstr("Fail on Windows, try again please\n");
  end_of_free(glob);
  exit(0);
}

void	fail_env(void)
{
  my_putstr("Fail on env, try again please\n");
  exit(0);
}
