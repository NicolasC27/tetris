/*
** rotation.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Mar 14 19:57:11 2016 romain samuel
** Last update Tue Mar 15 19:44:56 2016 romain samuel
*/

#include "tetris.h"

int	rotate_tetrimino(t_tetriminos tetri)
{
  int	i;
  int	b1;
  int	b2;
  int	tmp;

  i = 0;
  while (tetri.coord[i][0] != 0)
    {
      b1 = tetri.coord[i][1];
      b2 = tetri.height - tetri.coord[i][0];
      tetri.coord[i][0] = b1;
      tetri.coord[i][1] = b2;
      i++;
    }
  tmp = tetri.height;
  tetri.height = tetri.width;
  tetri.width = tmp;
  return (0);
}
