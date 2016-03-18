/*
** input_functions.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu Mar 17 16:40:00 2016 romain samuel
** Last update Fri Mar 18 09:52:30 2016 romain samuel
*/

#include "tetris.h"

int	move_to_right(t_tetris *s)
{
  move_tetrimino(s, 1, 0);
  return (0);
}

int	move_to_left(t_tetris *s)
{
  move_tetrimino(s, -1, 0);
  return (0);
}

int	move_down(t_tetris *s)
{
  move_tetrimino(s, 0, 1);
  return (0);
}

int	rotate(t_tetris *s)
{
  rotate_tetrimino(s->game.current);
  if (move_tetrimino(s, 0, 0) == -1)
    {
      rotate_tetrimino(s->game.current);
      rotate_tetrimino(s->game.current);
      rotate_tetrimino(s->game.current);
    }
  display_matrix(s, s->game.scene);
  display_tetrimino(s->windows->scene, s->game.current);
  return (0);
}

int	pause_game(t_tetris *s)
{
  char	buff[10];
  int	i;

  while (1)
    {
      if (read(0, buff, 10) > 0)
	if (my_strncmp(buff, s->keys->keytab[5], 9) == 0)
	  return (0);
      i = 0;
      while (i < 10)
	{
	  buff[i] = 0;
	  i++;
	}
    }
}
