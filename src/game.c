/*
** game.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Mar 14 01:53:41 2016 romain samuel
** Last update Tue Mar 15 16:48:34 2016 romain samuel
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

int	game(t_tetris *s)
{
  srand(time(NULL));
  if (create_compartments(s) == -1)
    return (-1);
  s->game.scene[0][0].filled = true;
  s->game.scene[0][0].color = 3;
  get_next_tetrimino(s);
  get_current_tetrimino(s);
  init_tetrimino_pos(s);
  display_tetrimino(s->windows->scene, s->game.current);
  /*display_matrix(s, s->game.scene);*/
  while (1);
  return (0);
}
