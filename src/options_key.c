/*
** options_key.c for options_key.c in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Thu Mar 10 19:33:35 2016 Chevalier Nicolas
** Last update Thu Mar 10 19:36:58 2016 Chevalier Nicolas
*/

#include "tetris.h"

int			is_keyleft(char *options, t_tetris *game, char **argv, int *i)
{
  int		       ret;
  int			x;
  char			*s;
  char			buff[10];
  int			y;
  int			nb;
  int			len;

  setupterm(NULL, 1, &ret);
  mode (0);
  write(0, "a", 2);
  while (read(0, buff, 10));
  printf("nb_lu: %d\n%d %d %d", len, buff[0], buff[1], buff[2]);
  mode (1);
  endwin();
  exit (0);
  return (0);
}

int			is_keyright(char *options, t_tetris *game, char **argv, int *i)
{
  game->keys->key_right = options;
  my_putstr(game->keys->key_right);
  return (0);
}

int			is_keyturn(char *options, t_tetris *game, char **argv, int *i)
{
  game->keys->key_turn = options;
  my_putstr(game->keys->key_turn);
  return (0);
}

int			is_keydrop(char *options, t_tetris *game, char **argv, int *i)
{
  game->keys->key_drop = options;
  my_putstr(game->keys->key_drop);
  return (0);
}

int			is_keyquit(char *options, t_tetris *game, char **argv, int *i)
{
  game->keys->key_quit = options;
  my_putstr(game->keys->key_quit);
  return (0);
}
