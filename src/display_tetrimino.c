/*
** display_tetrimino.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Mar 14 18:28:56 2016 romain samuel
** Last update Wed Mar 16 16:02:02 2016 romain samuel
*/

#include "tetris.h"

void	display_tetrimino(WINDOW *win, t_tetriminos tetri)
{
  int	i;

  i = 0;
  attron(COLOR_PAIR(1));
  while (tetri.coord[i][0] != 0)
    {
      mvwaddch(win, tetri.coord[i][0], tetri.coord[i][1], '*');
      i++;
    }
  attroff(COLOR_PAIR(1));
  wrefresh(win);
}
