/*
** generator.h for dante in /home/rectoria/delivery/Projets/dante
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Fri Apr 21 09:15:24 2017 Bastien
** Last update Sun May 14 15:01:16 2017 Thibaut Cornolti
*/

#ifndef GENERATOR_H_
# define GENERATOR_H_

# define TOP(i, x, y)	((i - y < 0) ? -1 : i - y)
# define BOT(i, x, y)	((i + y > y * x - 1) ? -1 : i + y)
# define LEFT(i, x, y)	((!(i % y)) ? -1 : i - 1)
# define RIGHT(i, x, y)	((!((i + 1) % y)) ? -1 : i + 1)

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_pile
{
  int		vstack;
  char		valid;
}		t_pile;

typedef struct	s_stack
{
  t_pile	*stack;
  int		index;
}		t_stack;

typedef t_pos	t_size;

void		check_and_get_param(int, char **, t_size *, int *);
void		generate_lab(t_pile *, char *, t_size *);
int		add_case(int *[2], t_stack *);
int		get_case(t_stack *);

#endif /* !GENERATOR */
