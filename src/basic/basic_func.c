/*
** basic_func.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/basic
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:03:46 2015 Thomas Martins
** Last update Sun Mar 15 09:04:14 2015 Thomas Martins
*/

#include "../struct.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a++;
    }
}

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    a++;
  return (a);
}
