/*
** handle_keys.c for handle_keys in /home/cheval_8/rendu/PSU_2015_tetris
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sat Mar 19 01:53:28 2016 Chevalier Nicolas
** Last update Sat Mar 19 02:41:57 2016 Chevalier Nicolas
*/

#include "tetris.h"

static int		(*redirection[6])(t_tetris *) =
{
  move_to_left,
  move_to_right,
  move_down,
  rotate,
  pause_game,
  '\0'
};

int			handle_keyboard(t_tetris *s)
{
  static char		**keys;
  char			buff[10];
  int			len;
  int			i;

  len = 0;
  i = -1;
  if ((keys = malloc(sizeof(char *) * 6)) == NULL)
    exit_tetris("Error with malloc\n", -1);
  keys[0] = s->keys->keyleft;
  keys[1] = s->keys->keyright;
  keys[2] = s->keys->keydrop;
  keys[3] = s->keys->keyturn;
  keys[4] = s->keys->keypause;
  keys[5] = s->keys->keyquit;
  keys[6] = '\0';
  mode(0, 1);
  len = read(0, buff, 10);
  buff[len] = '\0';
  mode(1, 1);
  if (len > 0)
    while (redirection[++i] && !(my_strncmp(buff, keys[i], 0)));
  return (i >= 0 && i != 5) ? redirection[i](s) : (0);
}
