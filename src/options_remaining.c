/*
** options_remaining.c for options_remaining.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Thu Mar 10 19:38:42 2016 Chevalier Nicolas
** Last update Thu Mar 10 19:39:15 2016 Chevalier Nicolas
*/

#include "tetris.h"

int			is_help(char *options, t_tetris *game, char **argv, int *i)
{
  my_putstr(HELP);
  exit (0);
  return (0);
}

int			is_level(char *options, t_tetris *game, char **argv, int *i)
{
  int			level;

  level = my_getnbr(options);
  game->scene->level = level;
  return (0);
}

int			is_keypause(char *options, t_tetris *game, char **argv, int *i)
{
  game->keys->key_pause = options;
  my_putstr(game->keys->key_pause);
  return (0);
}

int			is_mapsize(char *options, t_tetris *game, char **argv, int *i)
{
  int			rows;
  int			colums;
  int			x;

  x = 0;
  rows = my_getnbr(options);
  while (options[x++] != ',');
  colums = my_getnbr(&options[x]);
  game->scene->rows = rows;
  game->scene->colums = colums;
  return (0);
}

int			is_next(char *options, t_tetris *game, char **argv, int *i)
{
  game->scene->boolnext = false;
}
