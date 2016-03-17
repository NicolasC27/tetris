/*
** display_tetris.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu Mar 17 01:01:27 2016 romain samuel
** Last update Thu Mar 17 01:12:32 2016 romain samuel
*/

#include "tetris.h"

void	display_t_letter(WINDOW *win, int x)
{
  wattron(win, COLOR_PAIR(1));
  wmove(win, 1, 1 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 2, 2 + x);
  waddch(win, ' ');
  wmove(win, 3, 2 + x);
  waddch(win, ' ');
  wmove(win, 4, 2 + x);
  waddch(win, ' ');
  wmove(win, 5, 2 + x);
  wattroff(win, COLOR_PAIR(1));
}
