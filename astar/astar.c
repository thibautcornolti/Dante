/*
** astar.c for dante in /home/thibrex/Dropbox/delivery/CPE/dante/astar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Apr 25 17:05:43 2017 Thibaut Cornolti
** Last update Sun May 14 02:38:41 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "astar.h"

static void	set_stack(t_solve *solve, t_stack *stack)
{
  int		i;

  i = -1;
  while (++i < stack->index)
    solve->map[stack->stack[i]] = 'o';
}

static void	show_map(t_solve *solve, t_stack *stack)
{
  int		i;

  i = -1;
  while (solve->map[++i])
    if (solve->map[i] == '.')
      solve->map[i] = '*';
  solve->map[(solve->size.x + 1) * solve->size.y - 2] = 'o';
  set_stack(solve, stack);
  printf("%s", solve->map);
}

static int	calc_astar(t_solve *solve, int pos)
{
  t_size	astar;
  int		res;

  astar.x = solve->size.x - pos % solve->size.x - 1;
  astar.y = solve->size.y - pos / solve->size.x;
  if (astar.x > astar.y)
    res = RIGHT(pos, solve->size.x, solve->size.y);
  if (astar.x <= astar.y || res == -1 ||
      solve->map[res] == '.' || solve->map[res] == 'X')
    res = BOT(pos, solve->size.x, solve->size.y);
  return (res);
}

static int	get_next_pos(t_solve *solve, int pos)
{
  const int	coin[4] = {TOP(pos, solve->size.x, solve->size.y),
			   BOT(pos, solve->size.x, solve->size.y),
			   LEFT(pos, solve->size.x, solve->size.y),
			   RIGHT(pos, solve->size.x, solve->size.y)};
  int		res;
  int		random;

  random = rand() % 4;
  res = calc_astar(solve, pos);
  while (res == -1 ||
	 solve->map[res] == '.' ||
	 solve->map[res] == 'X')
    {
      if (random >= 8)
	return (-1);
      else
	res = coin[random % 4];
      random += 1;
    }
  return (res);
}

void		astar(t_solve *solve)
{
  int		i;
  t_stack	stack;
  int		start;

  i = 0;
  start = 0;
  srand(time(NULL));
  stack.index = 0;
  if ((stack.stack = malloc(sizeof(int) *
			    (solve->size.x * solve->size.y + 1))) == NULL)
    return ;
  while (!start || (i > 0 && i != (solve->size.x + 1) * solve->size.y - 2))
    {
      start = 1;
      solve->map[i] = '.';
      add_case(&stack, i);
      if ((i = get_next_pos(solve, i)) == -1)
	i = get_case(&stack);
    }
  if (i == 0 && solve->size.x != 1 && solve->size.y != 1)
    puts("no solution found");
  else
    show_map(solve, &stack);
  free(stack.stack);
}
