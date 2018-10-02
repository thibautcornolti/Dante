/*
** algo.c for breadth in /home/rectoria/delivery/Projets/dante/breadth
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Fri May 12 22:50:41 2017 Bastien
** Last update Sat May 13 18:11:21 2017 Bastien
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "breadth.h"

static char	*my_strmcat(char *str, char c)
{
  char	*new;
  int	len;

  len = (str) ? strlen(str) : 0;
  if (!(new = malloc(sizeof(char) * (len + 2))))
    exit(84);
  if (str)
    strcpy(new, str);
  new[len] = c + 1;
  new[len + 1] = 0;
  return (new);
}

static void		remove_first(t_solve *solve)
{
  free(solve->stack[0].root);
  solve->stack += 1;
  solve->stack_len -= 1;
  if (solve->stack_len == -1)
    {
      puts("no solution found");
      exit(0);
    }
}

static char		*add_stack(t_solve *solve, int cell, int way)
{
  solve->stack_len += 1;
  solve->stack[solve->stack_len].index = cell;
  solve->stack[solve->stack_len].root =
    my_strmcat(solve->stack[0].root, (char)way);
  solve->map[cell] *= -1;
  return (solve->stack[solve->stack_len].root);
}

static char	*get_path(t_solve *solve)
{
  int           i;
  const int     coin[4] = {RIGHT(solve->stack[0].index, solve->size.x,
				 solve->size.y),
			   BOT(solve->stack[0].index, solve->size.x,
			       solve->size.y),
			   LEFT(solve->stack[0].index, solve->size.x,
				solve->size.y),
			   TOP(solve->stack[0].index, solve->size.x,
			       solve->size.y)};

  i = -1;
  while (++i < 4)
    {
      if (coin[i] == (solve->size.x + 1) * solve->size.y - 2 &&
	  solve->map[coin[i]] == '*')
	return (add_stack(solve, coin[i], i));
      if (coin[i] > 0 && solve->map[coin[i]] == '*')
	add_stack(solve, coin[i], i);
    }
  remove_first(solve);
  return (NULL);
}

void	breadth(t_solve *solve)
{
  char	*root;
  int	i;
  int	pos;

  i = -1;
  pos = 0;
  while (!(root = get_path(solve)));
  while (root[++i])
    {
      solve->map[pos] = 'o';
      if ((int)root[i] == 1)
	pos = RIGHT(pos, solve->size.x, solve->size.y);
      else if ((int)root[i] == 2)
	pos = BOT(pos, solve->size.x, solve->size.y);
      else if ((int)root[i] == 3)
	pos = LEFT(pos, solve->size.x, solve->size.y);
      else if ((int)root[i] == 4)
	pos = TOP(pos, solve->size.x, solve->size.y);
    }
  solve->map[(solve->size.x + 1) * solve->size.y - 2] = 'o';
  display(solve);
}
