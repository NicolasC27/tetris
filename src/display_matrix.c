/*
** display_matrix.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Mar 14 17:53:37 2016 romain samuel
** Last update Tue Mar 15 16:42:09 2016 romain samuel
*/

#include "tetris.h"

void	display_compartment(WINDOW *win, t_compartment **matrix, int i, int j)
{
  char	c;

  if (matrix[i][j].filled == false)
    c = ' ';
  else
    c = '*';
  attron(COLOR_PAIR(matrix[i][j].color));
  mvwaddch(win, i + 1, j + 1, c);
  attroff(COLOR_PAIR(matrix[i][j].color));
  wrefresh(win);
}

void	display_matrix(t_tetris *s, t_compartment **matrix)
{
  int	i;
  int	j;

  i = -1;
  while (++i < s->scene->rows)
    {
      j = -1;
      while (++j < s->scene->colums)
	display_compartment(s->windows->scene, matrix, i, j);
    }
}