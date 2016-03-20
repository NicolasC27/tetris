/*
** check_complete_line.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Mar 15 18:12:34 2016 romain samuel
** Last update Sat Mar 19 23:43:54 2016 romain samuel
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
  s->scene->points += 10 * nb;
  if ((s->scene->line / 10) != ((s->scene->line + nb) / 10))
    s->scene->level++;
  s->scene->line += nb;
  return (nb);
}
