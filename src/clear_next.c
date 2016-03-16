/*
** clear_next.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed Mar 16 16:06:59 2016 romain samuel
** Last update Wed Mar 16 16:23:40 2016 romain samuel
*/

#include "tetris.h"

void	clear_next(t_tetris *s)
{
  int	x;
  int	y;

  y = 1;
  while (y < 5)
    {
      x = 1;
      while (x < 5)
	{
	  mvwaddch(s->windows->next, y, x, ' ');
	  x++;
	}
      y++;
    }
}
