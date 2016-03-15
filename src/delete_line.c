/*
** delete_line.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Mar 15 19:33:41 2016 romain samuel
** Last update Tue Mar 15 20:33:19 2016 romain samuel
*/

#include "tetris.h"

int	sandpile(t_tetris *s, int line)
{
  int	y;
  int	x;

  y = line - 1;
  while (y >= 0)
    {
      x = 0;
      while (x < s->scene->colums)
	{
	  if (s->game.scene[y + 1][x].filled == false)
	    {
	      s->game.scene[y + 1][x].filled = true;
	      s->game.scene[y][x].filled = false;
	      s->game.scene[y + 1][x].color = s->game.scene[y][x].color;
	      s->game.scene[y][x].color = 0;
	    }
	  x++;
	}
      y--;
    }
  return (0);
}

int	del_line(t_tetris *s, int line)
{
  int	x;

  x = 0;
  while (x < s->scene->colums)
    {
      s->game.scene[line][x].filled = false;
      s->game.scene[line][x].color = 0;
      x++;
    }
  sandpile(s, line);
  return (0);
}
