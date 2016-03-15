/*
** move_tetrimino.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Mar 15 14:58:32 2016 romain samuel
** Last update Tue Mar 15 17:58:20 2016 romain samuel
*/

#include "tetris.h"

int	move_tetrimino(t_tetris *s, int x, int y)
{
  int	i;

  i = 0;
  while (s->game.current.coord[i][0] != 0)
    {
      if ((y + s->game.current.coord[i][0] - 1) < 0 ||
	  x + s->game.current.coord[i][1] - 1 < 0 ||
	  y + s->game.current.coord[i][0] - 1 >= s->scene->rows ||
	  x + s->game.current.coord[i][1] - 1 >= s->scene->colums ||
	  s->game.scene[y + s->game.current.coord[i][0] - 1]
	  [x + s->game.current.coord[i][1] - 1].filled == true)
	return (-1);
      i++;
    }
  i = 0;
  while (s->game.current.coord[i][0] != 0)
    {
      s->game.current.coord[i][0] += y;
      s->game.current.coord[i][1] += x;
      i++;
    }
  return (0);
}
