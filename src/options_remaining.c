/*
** options_remaining.c for options_remaining.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Thu Mar 10 19:38:42 2016 Chevalier Nicolas
** Last update Sun Mar 20 20:25:26 2016 Chevalier Nicolas
*/

#include "tetris.h"

int			is_help(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*options);
  (void)(*i);
  (void)(**argv);
  my_putstr("Usage: ");
  my_putstr(game->binary_name);
  my_putstr(" [options]");
  my_putstr(HELP);
  exit (0);
  return (0);
}

int			is_level(char *options, t_tetris *game, char **argv, int *i)
{
  int			level;

  level = my_getnbr(options);
  if (level <= 0)
    is_help(options, game, argv, i);
  game->scene->level = level;
  return (0);
}

int			is_keypause(char *options, t_tetris *game, char **argv, int *i)
{
  if (options[0] == '\0')
    is_help(options, game, argv, i);
  if (!my_strncmp(game->keys->keyquit, options, 0)
      && !my_strncmp(game->keys->keypause, options, 0)
      && !my_strncmp(game->keys->keyquit, options, 0)
      && !my_strncmp(game->keys->keyleft, options, 0)
      && !my_strncmp(game->keys->keydrop, options, 0)
      && !my_strncmp(game->keys->keyturn, options, 0))
    game->keys->keypause = options;
  else
    is_help(options, game, argv, i);
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
  if (rows <= 0 || colums <= 0)
    is_help(options, game, argv, i);
  game->scene->rows = rows;
  game->scene->colums = colums;
  return (0);
}

int			is_next(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*options);
  (void)(**argv);
  (void)(*i);
  game->scene->boolnext = false;
  return (0);
}
