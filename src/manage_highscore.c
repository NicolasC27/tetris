/*
** manage_highscore.c for tetris in /home/samuel_r/temp/PSU_2015_tetris
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Mar 20 00:17:53 2016 romain samuel
** Last update Sun Mar 20 03:08:41 2016 Chevalier Nicolas
*/

#include "tetris.h"

void	manage_highscore(t_tetris *s)
{
  if (s->scene->points > s->scene->highscore)
    s->scene->highscore = s->scene->points;
  s->scene->points = 0;
  s->scene->level = 1;
  s->scene->line = 0;
}
