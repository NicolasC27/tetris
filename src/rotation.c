/*
** rotation.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Mar 14 19:57:11 2016 romain samuel
** Last update Wed Mar 16 14:48:06 2016 romain samuel
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
      b1 = tetri.simple_coord[i][1];
      b2 = tetri.height - tetri.simple_coord[i][0];
      tetri.simple_coord[i][0] = b1;
      tetri.simple_coord[i][1] = b2;
      tetri.coord[i][0] = tetri.simple_coord[i][0] + tetri.y_translation;
      tetri.coord[i][1] = tetri.simple_coord[i][1] + tetri.x_translation;
      i++;
    }
  tmp = tetri.height;
  tetri.height = tetri.width;
  tetri.width = tmp;
  return (0);
}
