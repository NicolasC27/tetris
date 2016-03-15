/*
** init_tetrimino_pos.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Mar 15 16:05:01 2016 romain samuel
** Last update Tue Mar 15 16:44:33 2016 romain samuel
*/

#include "tetris.h"

int	init_tetrimino_pos(t_tetris *s)
{
  int	diff;

  diff = (s->scene->colums - s->game.current.width) / 2;
  wprintw(s->windows->score, "%d", diff);
  if (move_tetrimino(s, diff, 0) == -1)
    return (-1);
  wrefresh(s->windows->score);
  return (0);
}
