/*
** free_matrix.c for tetris in /home/samuel_r/temp/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Mar 20 00:13:49 2016 romain samuel
** Last update Sun Mar 20 00:17:03 2016 romain samuel
*/

#include "tetris.h"

void		free_matrix(t_tetris *s)
{
  int		y;

  y = 0;
  while (y < s->scene->rows)
    {
      free(s->game.scene[y]);
      y++;
    }
  free(s->game.scene);
}
