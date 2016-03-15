/*
** check_complete_line.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Mar 15 18:12:34 2016 romain samuel
** Last update Tue Mar 15 20:33:30 2016 romain samuel
*/

#include "tetris.h"

int	check_complete_line(t_tetris *s, t_compartment *line)
{
  int	i;

  i = 0;
  while (i < s->scene->colums)
    {
      if (line[i].filled == false)
	return (0);
      i++;
    }
  return (1);
}

int	check_complete_lines(t_tetris *s)
{
  int	y;
  int	nb;

  nb = 0;
  y = 0;
  while (y < s->scene->rows)
    {
      if (check_complete_line(s, s->game.scene[y]) == 1)
	{
	  del_line(s, y);
	  nb++;
	}
      y++;
    }
  return (0);
}
