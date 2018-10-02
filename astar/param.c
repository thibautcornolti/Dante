/*
** param.c for dante in /home/thibrex/Dropbox/delivery/CPE/dante/astar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Apr 25 17:10:01 2017 Thibaut Cornolti
** Last update Sat May 13 13:24:59 2017 Thibaut Cornolti
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "astar.h"

void		check_and_get_param(int ac, char **av,
				    t_param *param, t_solve *solve)
{
  int		i;
  char		c;
  struct stat	st;

  i = -1;
  if (ac != 2)
    {
      dprintf(2, "Usage: %s [file]\n", av[0]);
      exit(0);
    }
  param->name = av[1];
  if ((param->fd = open(av[1], O_RDONLY)) < 0 ||
      stat(param->name, &st) < 0 ||
      (solve->map = malloc(sizeof(char) * st.st_size + 1)) == NULL)
    {
      perror("Fatal error");
      exit(84);
    }
  while (read(param->fd, &c, 1))
    solve->map[++i] = c;
  close(param->fd);
}
