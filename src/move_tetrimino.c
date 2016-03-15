/*
** move_tetrimino.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Mar 15 14:58:32 2016 romain samuel
** Last update Tue Mar 15 16:44:48 2016 romain samuel
*/

#include "tetris.h"

int	move_tetrimino(t_tetris *s, int x, int y)
{
  int	i;

  i = 0;/*
  while (s->game.current.coord[i] != NULL)
    {
      if (s->game.scene[y + s->game.current.coord[i][0] -  1]
	  [x + s->game.current.coord[i][1] - 1].filled == true)
	return (-1);
      i++;
    }*/
  i = 0;
  while (s->game.current.coord[i] != NULL)
    {
      s->game.current.coord[i][0] += y;
      s->game.current.coord[i][1] += x;
      i++;
    }
  return (0);
}
