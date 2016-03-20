/*
** options_key.c for options_key.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Thu Mar 10 19:33:35 2016 Chevalier Nicolas
** Last update Sun Mar 20 20:24:11 2016 Chevalier Nicolas
*/

#include <term.h>
#include "tetris.h"

int			is_keyleft(char *options, t_tetris *game, char **argv, int *i)
{
  if (options[0] == '\0')
    is_help(options, game, argv, i);
  if (!my_strncmp(game->keys->keyquit, options, 0)
      && !my_strncmp(game->keys->keypause, options, 0)
      && !my_strncmp(game->keys->keyquit, options, 0)
      && !my_strncmp(game->keys->keyright, options, 0)
      && !my_strncmp(game->keys->keydrop, options, 0)
      && !my_strncmp(game->keys->keyturn, options, 0))
    game->keys->keyleft = options;
  else
   is_help(options, game, argv, i);
  return (0);
}

int			is_keyright(char *options, t_tetris *game, char **argv, int *i)
{
  if (options[0] == '\0')
    is_help(options, game, argv, i);
  if (!my_strncmp(game->keys->keyquit, options, 0)
      && !my_strncmp(game->keys->keypause, options, 0)
      && !my_strncmp(game->keys->keyquit, options, 0)
      && !my_strncmp(game->keys->keyleft, options, 0)
      && !my_strncmp(game->keys->keydrop, options, 0)
      && !my_strncmp(game->keys->keyturn, options, 0))
    game->keys->keyright = options;
  else
    is_help(options, game, argv, i);
  return (0);
}

int			is_keyturn(char *options, t_tetris *game, char **argv, int *i)
{
  if (options[0] == '\0')
    is_help(options, game, argv, i);
  if (!my_strncmp(game->keys->keyquit, options, 0)
      && !my_strncmp(game->keys->keypause, options, 0)
      && !my_strncmp(game->keys->keyquit, options, 0)
      && !my_strncmp(game->keys->keyleft, options, 0)
      && !my_strncmp(game->keys->keydrop, options, 0)
      && !my_strncmp(game->keys->keyright, options, 0))
    game->keys->keyturn = options;
  else
    is_help(options, game, argv, i);
  return (0);
}

int			is_keydrop(char *options, t_tetris *game, char **argv, int *i)
{
  if (options[0] == '\0')
    is_help(options, game, argv, i);
  if (!my_strncmp(game->keys->keyquit, options, 0)
      && !my_strncmp(game->keys->keypause, options, 0)
      && !my_strncmp(game->keys->keyquit, options, 0)
      && !my_strncmp(game->keys->keyleft, options, 0)
      && !my_strncmp(game->keys->keyturn, options, 0)
      && !my_strncmp(game->keys->keyright, options, 0))
    game->keys->keydrop = options;
  else
    is_help(options, game, argv, i);
  return (0);
}

int			is_keyquit(char *options, t_tetris *game, char **argv, int *i)
{
  if (options[0] == '\0')
    is_help(options, game, argv, i);
  if (!my_strncmp(game->keys->keyquit, options, 0)
      && !my_strncmp(game->keys->keypause, options, 0)
      && !my_strncmp(game->keys->keyquit, options, 0)
      && !my_strncmp(game->keys->keyleft, options, 0)
      && !my_strncmp(game->keys->keyturn, options, 0)
      && !my_strncmp(game->keys->keyright, options, 0))
    game->keys->keyquit = options;
  else
    is_help(options, game, argv, i);
  return (0);
}
