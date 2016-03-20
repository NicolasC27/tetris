/*
** clear_next.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed Mar 16 16:06:59 2016 romain samuel
** Last update Sat Mar 19 15:06:58 2016 romain samuel
*/

#include "tetris.h"

void	clear_next(t_tetris *s)
{
  wclear(s->windows->next);
  box(s->windows->next, 0, 0);
  wrefresh(s->windows->next);
}
