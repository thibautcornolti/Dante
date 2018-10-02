/*
** param.c for generator in /home/thibrex/Dropbox/delivery/CPE/dante/generator
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Apr 21 09:47:31 2017 Thibaut Cornolti
** Last update Sun May 14 23:46:12 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "generator.h"

static int	str_isnum(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    if (!((str[i] >= '0' && str[i] <= '9') ||
	  (str[i] == '-' && i == 0)))
      return (0);
  return (1);
}

void		check_and_get_param(int ac, char **av,
				    t_size *size, int *perfect)
{
  if (ac < 3 || ac > 4 ||
      !str_isnum(av[1]) || !str_isnum(av[2]) ||
      (ac == 4 && strcmp(av[3], "perfect")))
    {
      dprintf(2, "Usage: %s x y [perfect]\n", av[0]);
      exit(0);
    }
  size->x = atoi(av[1]);
  size->y = atoi(av[2]);
  *perfect = 0;
  if (ac == 4 && !strcmp(av[3], "perfect"))
    *perfect = 1;
  if (size->x <= 0 || size->y <= 0)
    exit(84);
}
