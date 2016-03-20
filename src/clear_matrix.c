/*
** clear_matrix.c for tetris in /home/samuel_r/temp/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Mar 20 00:17:22 2016 romain samuel
** Last update Sun Mar 20 03:09:52 2016 Chevalier Nicolas
*/

#include "tetris.h"

int	clear_matrix(t_tetris *s)
{
  int	y;
  int	x;

  y = 0;
  while (y < s->scene->rows)
    {
      x = 0;
      while (x < s->scene->colums)
	{
	  s->game.scene[y][x].filled = false;
	  s->game.scene[y][x].color = 0;
	  x++;
	}
      y++;
    }
  return (0);
}
