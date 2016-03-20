/*
** create_matrix.c for tetris in /home/samuel_r/temp/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Mar 20 00:18:36 2016 romain samuel
** Last update Sun Mar 20 03:09:41 2016 Chevalier Nicolas
*/

#include "tetris.h"

int	create_compartments(t_tetris *s)
{
  int	i;
  int	j;

  i = 0;
  if ((s->game.scene = malloc(sizeof(t_compartment *) * (s->scene->rows + 1)))
      == NULL)
    return (-1);
  while (i < s->scene->rows)
    {
      j = 0;
      if ((s->game.scene[i] = malloc(sizeof(t_compartment)
				     * (s->scene->colums))) == NULL)
	return (-1);
      while (j < s->scene->colums)
	{
	  s->game.scene[i][j].filled = false;
	  s->game.scene[i][j].color = 0;
	  j++;
	}
      i++;
    }
  return (0);
}
