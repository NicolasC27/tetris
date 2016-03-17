/*
** options_remaining.c for options_remaining.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Thu Mar 10 19:38:42 2016 Chevalier Nicolas
** Last update Thu Mar 17 02:53:25 2016 Chevalier Nicolas
*/

#include "tetris.h"

int			is_help(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*options);
  (void)(**argv);
  (void)(*i);
  (void)(*game);
  my_putstr(HELP);
  exit (0);
  return (0);
}

int			is_level(char *options, t_tetris *game, char **argv, int *i)
{
  int			level;

  (void)(**argv);
  (void)(*i);
  level = my_getnbr(options);
  game->scene->level = level;
  return (0);
}

int			is_keypause(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(**argv);
  (void)(*i);
  game->keys->keypause = options;
  return (0);
}

int			is_mapsize(char *options, t_tetris *game, char **argv, int *i)
{
  int			rows;
  int			colums;
  int			x;


  (void)(**argv);
  (void)(*i);
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
  (void)(*options);
  (void)(**argv);
  (void)(*i);
  (void)(*game);
  game->scene->boolnext = false;
  return (0);
}
