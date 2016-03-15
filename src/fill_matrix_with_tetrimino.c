/*
** fill_matrix_with_tetrimino.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Mar 15 18:17:21 2016 romain samuel
** Last update Tue Mar 15 18:37:20 2016 romain samuel
*/

#include "tetris.h"

int	fill_matrix_with_tetrimino(t_tetris *s)
{
  int	i;

  i = 0;
  while (s->game.current.coord[i][0] != 0)
    {
      s->game.scene[s->game.current.coord[i][0] - 1]
	[s->game.current.coord[i][1] - 1].filled = true;
      s->game.scene[s->game.current.coord[i][0] - 1]
	[s->game.current.coord[i][1] - 1].color = s->game.current.color;
      i++;
    }
  return (0);
}
