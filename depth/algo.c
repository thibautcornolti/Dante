/*
** algo.c for depth in /home/rectoria/delivery/Projets/dante/depth
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue May  9 15:31:59 2017 Bastien
** Last update Sun May 14 13:15:13 2017 Bastien
*/

#include <stdio.h>
#include "depth.h"

static int	destack(int *pos, t_solve *solve)
{
  if (solve->stack.index == 0)
    return (0);
  if (solve->map[*pos] > 0)
    solve->map[*pos] *= -1;
  *pos = solve->stack.stack[solve->stack.index - 1];
  solve->stack.stack[solve->stack.index - 1] = 0;
  solve->stack.index -= 1;
  return (1);
}

static int	add_stack(int *pos, t_solve *solve, int type)
{
  if (solve->map[*pos] > 0)
    solve->map[*pos] *= -1;
  solve->stack.stack[solve->stack.index] = *pos;
  solve->stack.index += 1;
  *pos = type;
  if (*pos == (solve->size.x + 1) * solve->size.y - 2)
    return (0);
  return (1);
}

static int	get_path(t_solve *solve, int *pos)
{
  int		i;
  const int	coin[4] = {RIGHT(*pos, solve->size.x, solve->size.y),
			   BOT(*pos, solve->size.x, solve->size.y),
			   LEFT(*pos, solve->size.x, solve->size.y),
			   TOP(*pos, solve->size.x, solve->size.y)};

  i = -1;
  while (++i < 4)
    if (coin[i] > 0 && solve->map[coin[i]] == '*')
      return (add_stack(pos, solve, coin[i]));
  return (destack(pos, solve));
}

static void	display(t_solve *solve)
{
  int		i;

  i = -1;
  while (solve->map[++i])
    if (solve->map[i] < 0)
      solve->map[i] *= -1;
  printf("%s", solve->map);
}

void	depth(t_solve *solve)
{
  int	pos;

  pos = 0;
  while (get_path(solve, &pos));
  if (pos)
    {
      while (--solve->stack.index >= 0)
	solve->map[solve->stack.stack[solve->stack.index]] = 'o';
      solve->map[(solve->size.x + 1) * solve->size.y - 2] = 'o';
    }
  if (solve->map[0] == 'o')
    display(solve);
  else
    puts("no solution found");
}
