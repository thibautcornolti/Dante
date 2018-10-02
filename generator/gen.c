/*
** gen.c for generator in /home/thibrex/Dropbox/delivery/CPE/dante/generator
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Apr 21 10:31:40 2017 Thibaut Cornolti
** Last update Sun May 14 15:10:55 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "generator.h"

static int	check_coin(char *map, t_size *param, int i)
{
  const int	coin[4] = {TOP(i, param->x, param->y),
			   BOT(i, param->x, param->y),
			   LEFT(i, param->x, param->y),
			   RIGHT(i, param->x, param->y)};
  int	j;
  int	p;

  j = -1;
  p = 0;
  while (++j < 4)
    if (coin[j] < 0)
      continue;
    else if (map[coin[j]] == 1)
      p += 1;
  return (p >= 2);
}

static void	get_coinflip(char *map, t_size *param, int *i[2])
{
  const int	coin[4] = {TOP(*i[0], param->x, param->y),
			   BOT(*i[0], param->x, param->y),
			   LEFT(*i[0], param->x, param->y),
			   RIGHT(*i[0], param->x, param->y)};
  int		j;
  int		p;
  int		ret;

  j = -1;
  p = 0;
  while (++j < 4)
    {
      if (coin[j] < 0 ||
	  map[coin[j]] != 0 ||
	  check_coin(map, param, coin[j]))
	p += 1;
    }
  *i[1] = (4 - p) ? 3 - p : -1;
  if (p >= 4)
    return ;
  ret = rand() % 4;
  j = coin[ret];
  while (j < 0 || map[j] != 0 || check_coin(map, param, j))
    j = coin[(ret = ret + 1) % 4];
  *i[0] = j;
}

static void	rec_gen(t_stack *stack, char *map,
			t_size *param, int *i[2])
{
  int		comp;

  map[*i[0]] = 1;
  get_coinflip(map, param, i);
  comp = *i[1];
  *i[1] = (*i[1] > 0) ? *i[1] : -1;
  if (comp == -1)
    *i[0] = get_case(stack);
  else
    add_case(i, stack);
}

void		generate_lab(t_pile *st, char *map, t_size *param)
{
  int		*i[2];
  t_stack	stack;

  i[0] = malloc(sizeof(int) * 2);
  i[1] = malloc(sizeof(int) * 2);
  *i[0] = 0;
  stack.stack = st;
  stack.index = 0;
  while (!(!stack.index && map[0]))
    rec_gen(&stack, map, param, i);
}
