/*
** my_putnbr.c for  in /home/mart_4/rendu/MUL_2014_rtv1/src/basic
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 15 09:04:02 2015 Thomas Martins
** Last update Sun Mar 15 09:04:14 2015 Thomas Martins
*/

#include "../struct.h"

void	my_putnbr_rec(int nb)
{
  if (nb < -9)
    my_putnbr_rec(nb / 10);
  my_putchar('0' - nb % 10);
}

void	my_putnbr(int nb)
{
  if (nb < 0)
    my_putchar('-');
  else
    nb = -nb;
  my_putnbr_rec(nb);
}
