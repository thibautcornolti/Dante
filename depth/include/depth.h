/*
** astar.h for dante in /home/thibrex/Dropbox/delivery/CPE/dante/astar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Apr 25 17:01:53 2017 Thibaut Cornolti
** Last update Sat May 13 17:30:23 2017 Thibaut Cornolti
*/

#ifndef DEPTH_H_
# define DEPTH_H_

# define TOP(i, x, y)   ((i - (x + 1) < 0) ? -1 : i - x - 1)
# define BOT(i, x, y)   ((i + (x + 1) > (x + 1) * y - 1) ? -1 : i + x + 1)
# define LEFT(i, x, y)  ((i % (x + 1) == 0) ? -1 : i - 1)
# define RIGHT(i, x, y) ((i % (x + 1) == x - 1) ? -1 : i + 1)

typedef struct	s_size
{
  int		x;
  int		y;
}		t_size;

typedef struct	s_param
{
  char		*name;
  int		fd;
}		t_param;

typedef struct	s_stack
{
  int		*stack;
  int		index;
}		t_stack;

typedef struct	s_solve
{
  char		*map;
  t_size	size;
  t_stack	stack;
}		t_solve;

void		check_and_get_param(int, char **, t_param *, t_solve *);
void		depth(t_solve *);

#endif /* !DEPTH_H_ */
