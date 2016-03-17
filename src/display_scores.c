/*
** display_scores.c for tetris in /home/samuel_r/EPITECH/PSU/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed Mar 16 18:40:32 2016 romain samuel
** Last update Wed Mar 16 19:23:30 2016 romain samuel
*/

#include "tetris.h"

int	my_intlen(int nb)
{
  int	i;
  int	div;

  i = 0;
  div = 1;
  while (nb / div > 1)
    div *= 10;
  return (i);
}

int	display_scores(t_tetris *s)
{
  int	len;

  wmove(s->windows->score, 3, 5 + (6 my_intlen(s->scene->highscore)));

  return (0);
}
