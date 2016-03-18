/*
** options_key.c for options_key.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Thu Mar 10 19:33:35 2016 Chevalier Nicolas
** Last update Fri Mar 18 23:51:00 2016 Chevalier Nicolas
*/

#include <term.h>
#include "tetris.h"

int			is_keyleft(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*i);
  (void)(*game);
  (void)(**argv);
  if (options[0] == ' ')
    options = "(space)";
  game->keys->keyleft = options;
  return (0);
}

int			is_keyright(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*i);
  (void)(*game);
  (void)(**argv);
  if (options[0] == ' ')
    options = "(space)";
  game->keys->keyright = options;
  return (0);
}

int			is_keyturn(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*i);
  (void)(*game);
  (void)(**argv);
  if (options[0] == ' ')
    options = "(space)";
  game->keys->keyturn = options;
  return (0);
}

int			is_keydrop(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*i);
  (void)(*game);
  (void)(**argv);
  if (options[0] == ' ')
    options = "(space)";
  game->keys->keydrop = options;
  return (0);
}

int			is_keyquit(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*i);
  (void)(*game);
  (void)(**argv);
  if (options[0] == ' ')
    options = "(space)";
  game->keys->keyquit = options;
  return (0);
}
