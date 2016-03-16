/*
** copy_coord_tab.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed Mar 16 16:30:03 2016 romain samuel
** Last update Wed Mar 16 16:43:41 2016 romain samuel
*/

#include "tetris.h"

int	**copy_coord_tab(t_tetriminos *tetri)
{
  int		**tab;
  int		i;
  int		lines;
  int		colums;
  int		a;

  colums = 3;
  lines = (tetri->height * tetri->width) + 1;
  if ((tab = malloc(sizeof(int *) * (lines + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < lines)
    if ((tab[i] = malloc(sizeof(int) * colums)) == NULL)
      return (NULL);
  i = -1;
  while (++i < lines)
    {
      a = -1;
      while (++a < colums)
	tab[i][a] = tetri->coord[i][a];
    }
  return (tab);
}
