/*
** get_max_size.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Mar 14 19:32:27 2016 romain samuel
** Last update Sun Mar 20 01:07:08 2016 romain samuel
*/

#include "tetris.h"

int		get_max_termitrino_width(t_tetriminos *root)
{
  int		max;
  t_tetriminos	*it;

  max = 0;
  it = root;
  while (it != NULL)
    {
      if (it->valid == true && it->width > max)
	max = it->width;
      it = it->next;
    }
  return (max);
}

int		get_max_termitrino_height(t_tetriminos *root)
{
  int		max;
  t_tetriminos	*it;

  max = 0;
  it = root;
  while (it != NULL)
    {
      if (it->valid == true && it->height > max)
	max = it->height;
      it = it->next;
    }
  return (max);
}
