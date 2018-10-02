/*
** main.c for breadth in /home/rectoria/delivery/Projets/dante/astar
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Apr 27 12:37:21 2017 Bastien
** Last update Sun May 14 23:45:32 2017 Thibaut Cornolti
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "breadth.h"

static int	get_size_line(char *maze)
{
  int		i;

  i = -1;
  while (maze[++i] && maze[i] != '\n');
  return (i);
}

static int	set_struct(t_solve *solve, char *maze, int size)
{
  int		first;

  first = get_size_line(maze);
  if (maze[first + 1] && first != get_size_line(maze + first + 1))
    return (-1);
  solve->map = maze;
  solve->size.x = first;
  if ((size + 1) % (solve->size.x + 1))
    return (-1);
  solve->size.y = size / (solve->size.x + 1) + 1;
  if (solve->size.x == 0 || solve->size.y == 0)
    return (-1);
  return (0);
}

static int	get_maze(char *str, t_solve *solve)
{
  char		*maze;
  int		fd;
  struct stat	buf;
  int		readed;

  if ((fd = open(str, O_RDONLY)) == -1 || stat(str, &buf))
    return (-1);
  if ((maze = malloc(sizeof(char) * (buf.st_size + 1))) == NULL)
    return (-1);
  if ((readed = read(fd, maze, buf.st_size)) == -1)
    return (-1);
  maze[readed] = 0;
  close(fd);
  if ((set_struct(solve, maze, buf.st_size)) == -1)
    return (-1);
  return (0);
}

static void	create_stack(t_solve *solve)
{
  if (!(solve->stack = malloc(sizeof(t_stack) *
			      solve->size.y * solve->size.x)))
    return ;
  memset(solve->stack, 0, solve->size.y * solve->size.x);
}

int		main(int ac, char **av)
{
  t_solve	solve;

  if (ac != 2)
    return (84);
  memset(&solve, 0, sizeof(t_solve));
  if (get_maze(av[1], &solve) == -1)
    return (84);
  create_stack(&solve);
  if (!solve.stack)
    return (84);
  solve.save = solve.stack;
  breadth(&solve);
  free(solve.map);
  free(solve.save);
  return (0);
}
