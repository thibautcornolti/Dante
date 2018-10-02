/*
** stack.c for generator in /home/thibrex/Dropbox/delivery/CPE/dante/generator
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Apr 21 13:55:03 2017 Thibaut Cornolti
** Last update Thu May 11 00:18:11 2017 Thibaut Cornolti
*/

#include "astar.h"

void		add_case(t_stack *stack, int i)
{
  stack->stack[stack->index] = i;
  stack->index += 1;
}

int		get_case(t_stack *stack)
{
  stack->index -= 2;
  return (stack->stack[stack->index]);
}
