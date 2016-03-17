/*
** display_tetris.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu Mar 17 01:01:27 2016 romain samuel
** Last update Thu Mar 17 16:05:14 2016 romain samuel
*/

#include "tetris.h"

void	display_t_letter(WINDOW *win, int x, int color)
{
  wattron(win, COLOR_PAIR(color));
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
  waddch(win, ' ');
  wattroff(win, COLOR_PAIR(color));
}

void	display_e_letter(WINDOW *win, int x, int color)
{
  wattron(win, COLOR_PAIR(color));
  wmove(win, 1, 5 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 2, 5 + x);
  waddch(win, ' ');
  wmove(win, 3, 5 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 4, 5 + x);
  waddch(win, ' ');
  wmove(win, 5, 5 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wattroff(win, COLOR_PAIR(color));
}

void	display_r_letter(WINDOW *win, int x, int color)
{
  wattron(win, COLOR_PAIR(color));
  wmove(win, 1, 13 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 2, 13 + x);
  waddch(win, ' ');
  wmove(win, 2, 15 + x);
  waddch(win, ' ');
  wmove(win, 3, 13 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 4, 13 + x);
  waddch(win, ' ');
  wmove(win, 4, 15 + x);
  waddch(win, ' ');
  wmove(win, 5, 13 + x);
  waddch(win, ' ');
  wmove(win, 5, 15 + x);
  waddch(win, ' ');
  wattroff(win, COLOR_PAIR(color));
}

void	display_i_letter(WINDOW *win, int x, int color)
{
  wattron(win, COLOR_PAIR(color));
  wmove(win, 1, 17 + x);
  waddch(win, ' ');
  wmove(win, 2, 17 + x);
  waddch(win, ' ');
  wmove(win, 3, 17 + x);
  waddch(win, ' ');
  wmove(win, 4, 17 + x);
  waddch(win, ' ');
  wmove(win, 5, 17 + x);
  waddch(win, ' ');
  wattroff(win, COLOR_PAIR(color));
}

void	display_s_letter(WINDOW *win, int x, int color)
{
  wattron(win, COLOR_PAIR(color));
  wmove(win, 1, 19 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 2, 19 + x);
  waddch(win, ' ');
  wmove(win, 3, 19 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wmove(win, 4, 21 + x);
  waddch(win, ' ');
  wmove(win, 5, 19 + x);
  waddch(win, ' ');
  waddch(win, ' ');
  waddch(win, ' ');
  wattroff(win, COLOR_PAIR(color));
}
