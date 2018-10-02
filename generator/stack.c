/*
** stack.c for generator in /home/thibrex/Dropbox/delivery/CPE/dante/generator
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Apr 21 13:55:03 2017 Thibaut Cornolti
** Last update Sat May 13 13:26:51 2017 Thibaut Cornolti
*/

#include "generator.h"

int		add_case(int *index[2], t_stack *stack)
{
  stack->index += 1;
  stack->stack[stack->index].valid = *index[1];
  stack->stack[stack->index].vstack = *index[0];
  return (*index[0]);
}

int		get_case(t_stack *stack)
{
  stack->stack[stack->index].vstack = -1;
  if (stack->index > 0)
    stack->index -= 1;
  int	k = 1;
  while (stack->index && stack->stack[stack->index].valid == -1)
    {
      stack->stack[stack->index].vstack = -1;
      if (stack->index > 0)
	stack->index -= 1;
      ++k;
    }
  return (stack->stack[stack->index].vstack);
}
