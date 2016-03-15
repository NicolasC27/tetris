/*
** options_key.c for options_key.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Thu Mar 10 19:33:35 2016 Chevalier Nicolas
** Last update Tue Mar 15 16:03:57 2016 Chevalier Nicolas
*/

#include <term.h>
#include "tetris.h"

int			is_keyleft(char *options, t_tetris *game, char **argv, int *i)
{
  int			ret;
  char			buff[10];
  int			len;

  (void)(*i);
  (void)(*game);
  (void)(**argv);
  (void)(*options);
  setupterm(NULL, 1, &ret);
  mode(0);
  write(0, "a", 2);
  while ((len = read(0, buff, 10)));
  printf("nb_lu: %d\n%d %d %d", len, buff[0], buff[1], buff[2]);
  mode(1);
  endwin();
  exit (0);
  return (0);
}

int			is_keyright(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*i);
  (void)(*game);
  (void)(**argv);
  game->keys->keyright = options;
  return (0);
}

int			is_keyturn(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*i);
  (void)(*game);
  (void)(**argv);
  game->keys->keyturn = options;
  return (0);
}

int			is_keydrop(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*i);
  (void)(*game);
  (void)(**argv);
  game->keys->keydrop = options;
  return (0);
}

int			is_keyquit(char *options, t_tetris *game, char **argv, int *i)
{
  (void)(*i);
  (void)(*game);
  (void)(**argv);
  game->keys->keyquit = options;
  return (0);
}
