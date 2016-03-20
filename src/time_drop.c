/*
** time_drop.c for tetris in /home/samuel_r/temp/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Mar 20 01:22:00 2016 romain samuel
** Last update Sun Mar 20 01:22:19 2016 romain samuel
*/

#include "tetris.h"

int		time_drop(t_tetris *s)
{
  if (move_tetrimino(s, 0, 1) == -1)
    {
      fill_matrix_with_tetrimino(s);
      check_complete_lines(s);
      if (get_current_tetrimino(s) == -1)
	return (-2);
      get_next_tetrimino(s);
      if (s->scene->boolnext == true)
	{
	  clear_next(s);
	  display_tetrimino(s->windows->next, *s->game.next);
	}
      if (init_tetrimino_pos(s) == -1)
	return (-2);
    }
  else
    return (0);
  return (0);
}
