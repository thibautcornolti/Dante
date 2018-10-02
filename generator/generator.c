/*
** main.c for generator in /home/thibrex/Dropbox/delivery/CPE/dante/generator
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Apr 21 09:31:31 2017 Thibaut Cornolti
** Last update Sun May 14 15:12:53 2017 Thibaut Cornolti
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "generator.h"

static void	print_map(char *map, t_size *param, int perfect)
{
  int		i;
  int		j;

  i = -1;
  while (++i < param->x)
    {
      j = -1;
      while (++j < param->y)
	{
	  if (map[i * param->y + j])
	    putchar('*');
	  else if (!perfect && !(rand() % 10))
	    putchar('*');
	  else
	    putchar('X');
	}
      if (i + 1 < param->x)
	putchar('\n');
    }
}

static void	create_stack(t_pile **stack, t_size *param)
{

  if (!(*stack = malloc(sizeof(t_pile) * (param->x * param->y))))
    exit(84);
  memset(*stack, -1, sizeof(t_pile) * (param->x * param->y));
}

int		main(int ac, char **av)
{
  char		*map;
  t_pile	*stack;
  t_size	param;
  int		perfect;

  check_and_get_param(ac, av, &param, &perfect);
  if (!(map = malloc(sizeof(char) * (param.x * param.y + 1))))
    return (84);
  srand(time(NULL) * getpid());
  memset(map, 0, param.x * param.y + 1);
  while (map[param.x * param.y - 1] == 0)
    {
      memset(map, 0, param.x * param.y + 1);
      create_stack(&stack, &param);
      generate_lab(stack, map, &param);
      free(stack);
    }
  print_map(map, &param, perfect);
  free(map);
  return (0);
}
