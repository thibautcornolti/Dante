/*
** display.c for dante in /home/rectoria/delivery/Projets/dante/breadth
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Sat May 13 14:48:11 2017 Bastien
** Last update Sat May 13 18:06:18 2017 Bastien
*/

#include <stdio.h>
#include "breadth.h"

void	display(t_solve *solve)
{
  int           i;

  i = -1;
  while (solve->map[++i])
    if (solve->map[i] < 0)
      solve->map[i] *= -1;
  printf("%s", solve->map);
}
